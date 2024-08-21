// mem
internal inline void
mem_copy(void* source, void* destination, s32 size)
{
    RtlMoveMemory(destination, source, (SIZE_T)size);
}
internal inline void
mem_clear(void* source, s32 size)
{
    SecureZeroMemory(source, (SIZE_T)size);
}

// i/o

internal io_file
io_readfile(s8* filename)
{
    io_file file = {};
    
    HANDLE handle = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if(handle)
    {
	LARGE_INTEGER file_size = {};
	if(GetFileSizeEx(handle, &file_size))
	{
	    /* note: we could use 'GetFileSize' instead, the trick
	       is the low part is the return value and the high part 
	       is a parameter, so..., my theory is 'or'ing the return
	       value and parameter gets the actual value. that's a bit of
	       a hassle to test now because I don't have any files large 
	       enough to require the high part, but in the future i'd like 
	       that we switch to 'GetFileSize' instead.                     */

	    file.source = VirtualAlloc(0, file_size.QuadPart, MEM_COMMIT, PAGE_READWRITE);

	    if(file.source)
	    {
		DWORD bytes_read = 0;
		if(ReadFile(handle, file.source, file_size.QuadPart, &bytes_read, 0))
		{
		    if(bytes_read == file_size.QuadPart)
		    {
			file.size = file_size.QuadPart; /* temp: this is dodgy and you know it. */
		    }
		    else
		    {
			VirtualFree(file.source, 0, MEM_RELEASE);
			file.source = 0;

			OutputDebugStringA("file size retrieved from 'GetFileSizeEx' the same as number of bytes read, returned from 'ReadFile'!\n");
		    }
		}
		else
		{
		    OutputDebugStringA("'ReadFile' failed!\n");
		}
	    }
	    else
	    {
		OutputDebugStringA("'VirtualAlloc' failed!\n");
	    }
	}
	else
	{
	    OutputDebugStringA("'GetFileSizeEx' failed!\n");
	}

	CloseHandle(handle);
    }
    else
    {
	OutputDebugStringA("'CreateFileA' failed!\n");
    }

    return(file);
}
internal void
io_writefile(s8* filename, s32 size, void* data)
{
    HANDLE handle = CreateFileA(filename, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if(handle)
    {
	DWORD bytes_written = 0;
	if(WriteFile(handle, data, size, &bytes_written, 0))
	{
	    if(bytes_written != (DWORD)size)
	    {
		OutputDebugStringA("size passed to function, not the same as number of bytes written by 'WriteFile'!\n");
	    }
	}
	else
	{
	    OutputDebugStringA("'WriteFile' failed!\n");
	}

	CloseHandle(handle);
    }
    else
    {
	OutputDebugStringA("'CreateFileA' failed!\n");
    }   
}
internal void
io_freefile(io_file file)
{
    if(file.source)
    {
	VirtualFree(file.source, 0, MEM_RELEASE);
    }
    else
    {
	OutputDebugStringA("'os_freefile (windows)' failed!\n");
    }
}

// windows helpers.

// requires:
// Handmade Heroine/hh_opengl_windows.cpp
//

struct windows_information
{
    HWND window;
    HDC  window_dc;
    
    s32  window_width;
    s32  window_height;

    s32 monitor_width;
    s32 monitor_height;
    
    WINDOWPLACEMENT placement;
    DWORD style;
};

internal void
windows_fullscreen(windows_information* info, b32* fullscreen)
{
    if(!(*fullscreen))
    {
	MONITORINFO monitor_info = { sizeof(monitor_info) };
	if (GetWindowPlacement(info->window, &info->placement) &&
	    GetMonitorInfoA(MonitorFromWindow(info->window, MONITOR_DEFAULTTOPRIMARY), &monitor_info))
	{
	    SetWindowLong(info->window, GWL_STYLE, info->style & ~WS_OVERLAPPEDWINDOW);
	    SetWindowPos (info->window, HWND_TOP,
			  monitor_info.rcMonitor.left, monitor_info.rcMonitor.top,
			  monitor_info.rcMonitor.right  - monitor_info.rcMonitor.left,
			  monitor_info.rcMonitor.bottom - monitor_info.rcMonitor.top,
			  SWP_NOOWNERZORDER | SWP_FRAMECHANGED);

	    *fullscreen = true;
	}
    }
    else
    {
	SetWindowLong(info->window, GWL_STYLE, info->style);
	SetWindowPlacement(info->window, &info->placement);
	
	*fullscreen = false;
    }

    RECT window_rect = {};
    GetClientRect(info->window, &window_rect);

    info->window_width  = window_rect.right  - window_rect.left;
    info->window_height = window_rect.bottom - window_rect.top;

    windows_opengl_updateviewport(info->window_width, info->window_height);
}


internal b32
windows_initialise_window(windows_information* window_info,
			  HINSTANCE instance, WNDPROC window_procedure_message,
			  s32 window_width, s32 window_height,
                          s8* window_title)
{
    b32 success = false;

    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);

    window_info-> window_width  = window_width;
    window_info-> window_height = window_height;
    window_info->monitor_width  = GetSystemMetrics(SM_CXSCREEN);
    window_info->monitor_height = GetSystemMetrics(SM_CYSCREEN);
    
    WNDCLASSA window_class = {};
    window_class.style 	       = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc   = window_procedure_message;
    window_class.hInstance     = instance;
    window_class.hCursor       = LoadCursorA(0, IDC_ARROW);
    window_class.lpszClassName = window_title;

    if(RegisterClassA(&window_class))
    {
	RECT window_rect = {
	    (window_info->monitor_width  - window_width )/2,
	    (window_info->monitor_height - window_height)/2,
	    window_info->window_width  + window_rect.left  ,
	    window_info->window_height + window_rect.top   ,
	};

	if(!AdjustWindowRect(&window_rect, WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION, false)) {
	    OutputDebugStringA("'AdjustWindowRect' failed!\n");
	}
	

	window_info->window = CreateWindowA(window_class.lpszClassName,
					    window_class.lpszClassName,
					    WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,
					    window_rect.left, window_rect.top,
					    (window_rect.right - window_rect.left),
					    (window_rect.bottom - window_rect.top),
					    0, 0,
					    instance,
					    0);
	if(window_info->window)
	{
	    window_info->window_dc = GetDC(window_info->window);
	    window_info->placement = { sizeof(window_info->placement) }; 
	    window_info->style     = GetWindowLongA(window_info->window, GWL_STYLE);
    
	    if(windows_opengl_initialise(window_info->window_dc))
	    {
		windows_opengl_updateviewport(window_width, window_height);
		success = true;
	    }
	}
	else
	{
	    OutputDebugStringA("'CreateWindowA' failed!\n");
	}
    }
    else
    {
	OutputDebugStringA("'RegisterClassA' failed!\n");	
    }

    return(success);
}

internal void
windows_process_messages(windows_information* window_info)
{
    MSG message = {};
    while(PeekMessageA(&message, window_info->window, 0, 0, PM_REMOVE))
    {
	TranslateMessage(&message);
	DispatchMessageA(&message);
    }
}


// SAMPLE

// s32 WINAPI
// WinMain (HINSTANCE      instance,
// 	 HINSTANCE prev_instance,
// 	 LPSTR           cmdline,
// 	 s32        show_cmdline)
// {
//     window_information info = {};
    
//     if(windows_initialise_window(&info,
// 				 window_width, window_height,
// 	                         "Title"))
//     {

// 	// input.
// 	action_map current_map  = {};
// 	action_map previous_map = {};

// 	// timing.
// 	LARGE_INTEGER counter_frequency;
// 	QueryPerformanceFrequency(&counter_frequency);
    
// 	LARGE_INTEGER counter_begin = {};
// 	LARGE_INTEGER counter_mid   = {};
// 	LARGE_INTEGER counter_end   = {};

// 	r32 actual_ms = 0.0;
// 	r32 target_ms = ((r32)1000) / 60;
// 	r32  frame_ms = 0;

// 	running = true;

// 	while(running)
// 	{
// 	    QueryPerformanceCounter(&counter_begin);
	    
// 	    windows_process_messages(&info);
// 	    windows_actions_update(window, window_width, window_height, &current_map, &previous_map);

// 	    // begin program.

// 	    QueryPerformanceCounter(&counter_mid);
// 	    actual_ms = ((r32)(counter_mid.QuadPart - counter_begin.QuadPart)/counter_frequency.QuadPart) * 1000;

// 	    if(actual_ms < target_ms)
// 	    {
// 		Sleep(target_ms - actual_ms);
// 	    }

// 	    SwapBuffers(window_dc); // @ show prepared frame

// 	    previous_map = current_map;

// 	    QueryPerformanceCounter(&counter_end);
// 	    frame_ms = ((r32)(counter_end.QuadPart - counter_begin.QuadPart)/counter_frequency.QuadPart) * 1000;
// 	}

// 	windows_deinitialise_window(&info);
//     }
    
//     return(0);
// }

