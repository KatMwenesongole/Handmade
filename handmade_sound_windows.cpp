/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

 Notice: (C) Copyright 2024 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/
#pragma once


internal b32
windows_dsound_initialise(HWND window, s32 samples_per_sec, s32 buffer_size, LPDIRECTSOUNDBUFFER* sound_buffer)
{
    b32 success = false;
    
    LPDIRECTSOUND direct_sound = 0;
    if(DirectSoundCreate(0, &direct_sound, 0) == DS_OK)
    {
	if(!(direct_sound->SetCooperativeLevel(window, DSSCL_PRIORITY) == DS_OK))
	{
	    OutputDebugStringA("'IDirectSoundBuffer8::SetCooperativeLevel' failed!\n");
	}

	WAVEFORMATEX wave_format = {};
	wave_format.wFormatTag = WAVE_FORMAT_PCM;
	wave_format.nChannels = 2;
	wave_format.nSamplesPerSec = samples_per_sec;
	wave_format.wBitsPerSample = 16;
	wave_format.nBlockAlign = (wave_format.nChannels * wave_format.wBitsPerSample)/8;
	wave_format.nAvgBytesPerSec = wave_format.nSamplesPerSec * wave_format.nBlockAlign;
	    
	LPDIRECTSOUNDBUFFER primary_buffer      = 0;
	DSBUFFERDESC        primary_buffer_desc = {};
	primary_buffer_desc.dwSize = sizeof(primary_buffer_desc);
	primary_buffer_desc.dwFlags = DSBCAPS_PRIMARYBUFFER;
	if(direct_sound->CreateSoundBuffer(&primary_buffer_desc, &primary_buffer, 0) == DS_OK)
	{
	    if(!(primary_buffer->SetFormat(&wave_format) == DS_OK))
	    {
		OutputDebugStringA("'IDirectSoundBuffer8::SetFormat' failed!\n");
	    }
	}
	else
	{
	    OutputDebugStringA("'IDirectSoundBuffer8::CreateSoundBuffer (PRIMARY)' failed!\n");
	}

	DSBUFFERDESC secondary_buffer_desc = {};
	secondary_buffer_desc.dwSize = sizeof(secondary_buffer_desc);
	secondary_buffer_desc.dwBufferBytes = buffer_size;
	secondary_buffer_desc.lpwfxFormat = &wave_format;
	if((direct_sound->CreateSoundBuffer(&secondary_buffer_desc, sound_buffer, 0) == DS_OK))
	{
	    success = true;
	}
	else
	{
	    OutputDebugStringA("'IDirectSoundBuffer8::CreateSoundBuffer (SECONDARY)' failed!\n");
	}
    }
    else
    {
	OutputDebugStringA("'DirectSoundCreate' failed!\n");
    }

    return(success);
}


