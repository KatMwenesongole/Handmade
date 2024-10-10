/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

 Notice: (C) Copyright 2024 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/
#pragma once


#define ACTION_COUNT 69

enum   action_choice
{
    // GENERAL
    ACTION_MOVE_RIGHTWARD = 0x00,
    ACTION_MOVE_FORWARD   = 0x01,
    ACTION_LOOK_RIGHTWARD = 0x02,
    ACTION_LOOK_UPWARD    = 0x03,
    ACTION_INTERACT       = 0x04,
    ACTION_CONFIRM        = 0x05,

    // CONCRETE
    ACTION_ENTER       = 0x06,
    ACTION_TAB         = 0x07,
    ACTION_ESC         = 0x08,
    ACTION_SPACEBAR    = 0x09,
    ACTION_CTRL        = 0x0A,
    ACTION_SHIFT       = 0x0B,
    ACTION_ALT         = 0x0C,
    ACTION_DELETE      = 0x0D,
    ACTION_BACKSPACE   = 0x0E,
    ACTION_PRINTSCREEN = 0x0F, 
    
    ACTION_A    = 0x10,
    ACTION_B    = 0x11,
    ACTION_C    = 0x12,
    ACTION_D    = 0x13,
    ACTION_E    = 0x14,
    ACTION_F    = 0x15,
    ACTION_G    = 0x16,
    ACTION_H    = 0x17,
    ACTION_I    = 0x18,
    ACTION_J    = 0x19,
    ACTION_K    = 0x1A,
    ACTION_L    = 0x1B,
    ACTION_M    = 0x1C,
    ACTION_N    = 0x1D,
    ACTION_O    = 0x1E,
    ACTION_P    = 0x1F,
    ACTION_Q    = 0x20,
    ACTION_R    = 0x21,
    ACTION_S    = 0x22,
    ACTION_T    = 0x23,
    ACTION_U    = 0x24,
    ACTION_V    = 0x25,
    ACTION_W    = 0x26,
    ACTION_X    = 0x27,
    ACTION_Y    = 0x28,
    ACTION_Z    = 0x29,

    ACTION_0 = 0x2A,
    ACTION_1 = 0x2B,
    ACTION_2 = 0x2C,
    ACTION_3 = 0x2D,
    ACTION_4 = 0x2E,
    ACTION_5 = 0x2F,
    ACTION_6 = 0x30,
    ACTION_7 = 0x31,
    ACTION_8 = 0x32,
    ACTION_9 = 0x33,
    
    ACTION_LMOUSE = 0x34,
    ACTION_RMOUSE = 0x35,
    ACTION_MMOUSE = 0x36,

    ACTION_RARROW = 0x37,
    ACTION_LARROW = 0x38,
    ACTION_UARROW = 0x39,
    ACTION_DARROW = 0x3A,

    ACTION_COMMA     = 0X3B,
    ACTION_PERIOD    = 0x3C,
    ACTION_FSLASH    = 0x3D,
    ACTION_BSLASH    = 0x3E,
    ACTION_LBRACE    = 0x3F,
    ACTION_RBRACE    = 0x40,
    ACTION_SEMICOLON = 0x41,
    ACTION_QUOTE     = 0x42,
    ACTION_DASH      = 0x43,
    ACTION_EQUAL     = 0x44,
};
struct action_state
{
    s8 character;
    union
    {
	b32 down;
	struct
	{
	    s16 pressed; // @ is down now, was not down before.
	    s16 holding; // @ is down now, was down before.
	};
    };
    r32 magnitude; // @ used for joysticks, always one or negative one for keyboard.
};
struct action_map
{
    // mouse
    
    v2 mouse_position; // [0.0, 16.0], [0.0, 9.0]
    v2 mouse_offset; // @ delta

    // scroll
    // backwards = -1
    // forwards  =  1 
    // no change =  0 
    // may have co-efficent depending on scroll distance within a frame
    
    s32 scroll;

    b32 gamepad_connected;

    action_state actions[ACTION_COUNT];
};

