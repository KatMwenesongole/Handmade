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
	    if(bytes_written != size)
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
