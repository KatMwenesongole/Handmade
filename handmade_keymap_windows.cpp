/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

 Notice: (C) Copyright 2024 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/
#pragma once

#include <xinput.h>

// @ keyboard & mouse
internal void
windows_key_update (BYTE* keyboard_state, action_map* current, action_map* previous, action_choice choice, s32 windows_key, r32 magnitude)
{
    if((1 << 8) & (s32)GetKeyState(windows_key))
    {
	current->actions[choice].down    = GetKeyState(windows_key);
	current->actions[choice].pressed = ((1 << 8) & current->actions[choice].down) && !previous->actions[choice].down;
	current->actions[choice].holding = current->actions[choice].down && previous->actions[choice].down;
    
	current->actions[choice].magnitude += magnitude;

	// character value

	WORD translation = 0;
	if(ToAscii(windows_key, MapVirtualKeyA(windows_key, MAPVK_VK_TO_VSC), keyboard_state, &translation, 1))
	{
	    current->actions[choice].character = (s8)translation;
	}
    }
}
internal void
windows_mouse_update(action_map* current, action_map* previous, HWND window, s32 window_width, s32 window_height)
{
    POINT cursor_position = {};
    GetCursorPos(&cursor_position);
    ScreenToClient(window, &cursor_position);

    current->mouse_position.x = calc_lerp(cursor_position.x, window_width,  0) * 16.0;
    current->mouse_position.y = calc_lerp(cursor_position.y, window_height, 0) *  9.0;
    current->mouse_offset.x   = current->mouse_position.x - previous->mouse_position.x;
    current->mouse_offset.y   = current->mouse_position.y - previous->mouse_position.y;
}

// @ gamepad
internal void
windows_joystick_update(action_map* current, action_map* previous, action_choice choice, SHORT joystick)
{
    if(calc_abs(joystick) > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
    {
	action_state* state = &current->actions[choice];

	state->pressed = (!previous->actions[choice].down) ? true : false;
	state->holding = ( previous->actions[choice].down) ? true : false;
    
	state->magnitude += (joystick > 0) ?
	calc_lerp(         joystick , 32767, 0):
	-calc_lerp(calc_abs(joystick), 32768, 0);
    }
}
internal void
windows_button_update(action_map* current, action_map* previous, action_choice choice, b32 down)
{
    action_state* state = &current->actions[choice];
    state->pressed = (down && !previous->actions[choice].down) ? true : false;
    state->holding = (down &&  previous->actions[choice].down) ? true : false;
    state->magnitude = 1.0;
}

internal void
windows_actions_update(HWND window, s32 window_width, s32 window_height, action_map* current, action_map* previous)
{
    *current = {};
    
    // @ gamepad
    
    XINPUT_STATE gamepad_state = {};
    if(XInputGetState(0, &gamepad_state) == ERROR_SUCCESS)
    {
	current->gamepad_connected = true;

	windows_joystick_update(current, previous, ACTION_MOVE_RIGHTWARD, gamepad_state.Gamepad.sThumbLX);
	windows_joystick_update(current, previous, ACTION_MOVE_FORWARD  , gamepad_state.Gamepad.sThumbLY);
	windows_joystick_update(current, previous, ACTION_LOOK_RIGHTWARD, gamepad_state.Gamepad.sThumbRX);
	windows_joystick_update(current, previous, ACTION_LOOK_UPWARD   , gamepad_state.Gamepad.sThumbRY);
	
	windows_button_update(current, previous, ACTION_INTERACT, (gamepad_state.Gamepad.wButtons & XINPUT_GAMEPAD_A));
	windows_button_update(current, previous, ACTION_CONFIRM, (gamepad_state.Gamepad.wButtons & XINPUT_GAMEPAD_X));
    }
    else
    {
	current->gamepad_connected = false;
    }

    // @ keyboard
    
    BYTE keyboard_state[256];
    if(!GetKeyboardState(keyboard_state))
    {
	OutputDebugStringA("'GetKeyboardState' failed!\n");
    }
    
    windows_mouse_update(current, previous, window, window_width, window_height);

    windows_key_update(keyboard_state, current, previous, ACTION_MOVE_FORWARD,   0x57,  1.0); // @ W
    windows_key_update(keyboard_state, current, previous, ACTION_MOVE_FORWARD,   0x53, -1.0); // @ S
    windows_key_update(keyboard_state, current, previous, ACTION_MOVE_RIGHTWARD, 0x44,  1.0); // @ D
    windows_key_update(keyboard_state, current, previous, ACTION_MOVE_RIGHTWARD, 0x41, -1.0); // @ A
    windows_key_update(keyboard_state, current, previous, ACTION_INTERACT, VK_SPACE,   1.0); // @ SPACEBAR
    windows_key_update(keyboard_state, current, previous, ACTION_INTERACT, VK_LBUTTON, 1.0); // @ MOUSE BUTTON - L
    windows_key_update(keyboard_state, current, previous, ACTION_CONFIRM,  VK_RETURN,  1.0); // @ ENTER

    windows_key_update(keyboard_state, current, previous, ACTION_LMOUSE, VK_LBUTTON,  1.0); // @ MOUSE BUTTON - L
    windows_key_update(keyboard_state, current, previous, ACTION_RMOUSE, VK_RBUTTON,  1.0); // @ MOUSE BUTTON - R
    windows_key_update(keyboard_state, current, previous, ACTION_MMOUSE, VK_MBUTTON,  1.0); // @ MOUSE BUTTON - M

    windows_key_update(keyboard_state, current, previous, ACTION_ENTER,       VK_RETURN,   1.0); // @ ENTER
    windows_key_update(keyboard_state, current, previous, ACTION_TAB,         VK_TAB,      1.0); // @ TAB
    windows_key_update(keyboard_state, current, previous, ACTION_SPACEBAR,    VK_SPACE,    1.0); // @ SPACEBAR
    windows_key_update(keyboard_state, current, previous, ACTION_BACKSPACE,   VK_BACK,     1.0); // @ BACKSPACE
    windows_key_update(keyboard_state, current, previous, ACTION_ESC,         VK_ESCAPE,   1.0); // @ ESC
    windows_key_update(keyboard_state, current, previous, ACTION_DELETE,      VK_DELETE,   1.0); // @ DELETE
    windows_key_update(keyboard_state, current, previous, ACTION_PRINTSCREEN, VK_SNAPSHOT, 1.0); // @ PRINT SCREEN

    windows_key_update(keyboard_state, current, previous, ACTION_LARROW, VK_LEFT,  1.0); // @ LEFT  ARROW
    windows_key_update(keyboard_state, current, previous, ACTION_RARROW, VK_RIGHT, 1.0); // @ RIGHT ARROW
    windows_key_update(keyboard_state, current, previous, ACTION_UARROW, VK_UP,    1.0); // @ UP    ARROW
    windows_key_update(keyboard_state, current, previous, ACTION_DARROW, VK_DOWN,  1.0); // @ DOWN  ARROW

    windows_key_update(keyboard_state, current, previous, ACTION_CTRL,  VK_CONTROL, 1.0); // @ CTRL
    windows_key_update(keyboard_state, current, previous, ACTION_SHIFT, VK_SHIFT,   1.0); // @ SHIFT
    windows_key_update(keyboard_state, current, previous, ACTION_ALT,   VK_MENU,    1.0); // @ ALT

    windows_key_update(keyboard_state, current, previous, ACTION_COMMA,     VK_OEM_COMMA,   1.0); // @ COMMA
    windows_key_update(keyboard_state, current, previous, ACTION_PERIOD,    VK_OEM_PERIOD,  1.0); // @ PERIOD
    windows_key_update(keyboard_state, current, previous, ACTION_FSLASH,    VK_OEM_2,       1.0); // @ FORWARD SLASH
    windows_key_update(keyboard_state, current, previous, ACTION_BSLASH,    VK_OEM_5,       1.0); // @ BACKWARD SLASH
    windows_key_update(keyboard_state, current, previous, ACTION_LBRACE,    VK_OEM_4,       1.0); // @ RIGHT BRACE
    windows_key_update(keyboard_state, current, previous, ACTION_RBRACE,    VK_OEM_6,       1.0); // @ LEFT  BRACE
    windows_key_update(keyboard_state, current, previous, ACTION_SEMICOLON, VK_OEM_1,       1.0); // @ SEMI-COLON
    windows_key_update(keyboard_state, current, previous, ACTION_QUOTE,     VK_OEM_7,       1.0); // @ QUOTE
    windows_key_update(keyboard_state, current, previous, ACTION_DASH,      VK_OEM_MINUS,   1.0); // @ DASH
    windows_key_update(keyboard_state, current, previous, ACTION_EQUAL,     VK_OEM_PLUS,    1.0); // @ EQUAL
    
    windows_key_update(keyboard_state, current, previous, ACTION_A, 0x41,  1.0); // @ A
    windows_key_update(keyboard_state, current, previous, ACTION_B, 0x42,  1.0); // @ B
    windows_key_update(keyboard_state, current, previous, ACTION_C, 0x43,  1.0); // @ C
    windows_key_update(keyboard_state, current, previous, ACTION_D, 0x44,  1.0); // @ D
    windows_key_update(keyboard_state, current, previous, ACTION_E, 0x45,  1.0); // @ E
    windows_key_update(keyboard_state, current, previous, ACTION_F, 0x46,  1.0); // @ F
    windows_key_update(keyboard_state, current, previous, ACTION_G, 0x47,  1.0); // @ G
    windows_key_update(keyboard_state, current, previous, ACTION_H, 0x48,  1.0); // @ H
    windows_key_update(keyboard_state, current, previous, ACTION_I, 0x49,  1.0); // @ I
    windows_key_update(keyboard_state, current, previous, ACTION_J, 0x4A,  1.0); // @ J
    windows_key_update(keyboard_state, current, previous, ACTION_K, 0x4B,  1.0); // @ K
    windows_key_update(keyboard_state, current, previous, ACTION_L, 0x4C,  1.0); // @ L
    windows_key_update(keyboard_state, current, previous, ACTION_M, 0x4D,  1.0); // @ M
    windows_key_update(keyboard_state, current, previous, ACTION_N, 0x4E,  1.0); // @ N
    windows_key_update(keyboard_state, current, previous, ACTION_O, 0x4F,  1.0); // @ O
    windows_key_update(keyboard_state, current, previous, ACTION_P, 0x50,  1.0); // @ P
    windows_key_update(keyboard_state, current, previous, ACTION_Q, 0x51,  1.0); // @ Q
    windows_key_update(keyboard_state, current, previous, ACTION_R, 0x52,  1.0); // @ R
    windows_key_update(keyboard_state, current, previous, ACTION_S, 0x53,  1.0); // @ S
    windows_key_update(keyboard_state, current, previous, ACTION_T, 0x54,  1.0); // @ T
    windows_key_update(keyboard_state, current, previous, ACTION_U, 0x55,  1.0); // @ U
    windows_key_update(keyboard_state, current, previous, ACTION_V, 0x56,  1.0); // @ V
    windows_key_update(keyboard_state, current, previous, ACTION_W, 0x57,  1.0); // @ W
    windows_key_update(keyboard_state, current, previous, ACTION_X, 0x58,  1.0); // @ X
    windows_key_update(keyboard_state, current, previous, ACTION_Y, 0x59,  1.0); // @ Y
    windows_key_update(keyboard_state, current, previous, ACTION_Z, 0x5A,  1.0); // @ Z

    windows_key_update(keyboard_state, current, previous, ACTION_0, 0x30,  1.0); // @ 0
    windows_key_update(keyboard_state, current, previous, ACTION_1, 0x31,  1.0); // @ 1
    windows_key_update(keyboard_state, current, previous, ACTION_2, 0x32,  1.0); // @ 2
    windows_key_update(keyboard_state, current, previous, ACTION_3, 0x33,  1.0); // @ 3
    windows_key_update(keyboard_state, current, previous, ACTION_4, 0x34,  1.0); // @ 4
    windows_key_update(keyboard_state, current, previous, ACTION_5, 0x35,  1.0); // @ 5
    windows_key_update(keyboard_state, current, previous, ACTION_6, 0x36,  1.0); // @ 6
    windows_key_update(keyboard_state, current, previous, ACTION_7, 0x37,  1.0); // @ 7
    windows_key_update(keyboard_state, current, previous, ACTION_8, 0x38,  1.0); // @ 8
    windows_key_update(keyboard_state, current, previous, ACTION_9, 0x39,  1.0); // @ 9

    

    

    // @ mouse

    // SLOW!
    
    /*
    MSG message;
    while(PeekMessageA(&message, window, WM_MOUSEFIRST, WM_MOUSELAST, PM_NOREMOVE | PM_QS_INPUT))
    {
	if(message.message == WM_MOUSEWHEEL)
	{
	    s16 value = (message.wParam >> 16);
	    current->scroll = (value > 1) ? 1 : -1;
	    current->scroll *= calc_abs(value) / WHEEL_DELTA;
	}
    }
    */
}
