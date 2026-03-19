/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

Notice: (C) Copyright 2024 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/
#pragma once

struct windows_sound_information
{
    b32 sound_playing;
    
    s32 samples_per_sec;  
    s32 sample_index;     
    s32 bytes_per_sample; 
    s32 buffer_size;      
    s32 volume;           
    
    LPDIRECTSOUNDBUFFER sound_buffer;
};

internal b32
windows_dsound_initialise(windows_sound_information* sound_info, HWND window)
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
	wave_format.nSamplesPerSec = sound_info->samples_per_sec;
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
	secondary_buffer_desc.dwBufferBytes = sound_info->buffer_size;
	secondary_buffer_desc.lpwfxFormat = &wave_format;
	if((direct_sound->CreateSoundBuffer(&secondary_buffer_desc, &sound_info->sound_buffer, 0) == DS_OK))
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

    if(sound_info->sound_buffer->Play(0, 0, DSBPLAY_LOOPING) == DS_OK)
    {
	sound_info->sound_playing = true;
    }
    else
    {
	OutputDebugStringA("'IDirectSoundBuffer8::Play' failed!\n"); // no music.
	success = false;
    }

    return(success);
}
internal void
windows_dsound_write(windows_sound_information* sound_info, s16* sample_data, s32* sample_index, s32 sample_count)
{
    DWORD  play_cursor = 0;
    DWORD write_cursor = 0; // not used.
    
    if(sound_info->sound_buffer->GetCurrentPosition(&play_cursor, &write_cursor) == DS_OK)
    {
	DWORD write_offset = ((*sample_index)*sound_info->bytes_per_sample)%sound_info->buffer_size;
	DWORD write_size = 0;
	
	if     (write_offset == play_cursor) // write offset is at play cursor.
	{
	    if(!sound_info->sound_playing)
	    {
		write_size = sound_info->buffer_size;
	    }
	    else { return; }
	}
	else if(write_offset > play_cursor) // write offset is ahead of play cursor.
	{
	    write_size = (sound_info->buffer_size - write_offset) + play_cursor;
	}
	else if(play_cursor >= write_offset) // play cursor is ahead of write offset.
	{
	    write_size = play_cursor - write_offset;
	}
		    
	VOID* region_0 = 0;
	VOID* region_1 = 0;
	DWORD region_0_size = 0;
	DWORD region_1_size = 0;

	if(sound_info->sound_buffer->Lock(write_offset, write_size,
					  &region_0, &region_0_size,
					  &region_1, &region_1_size, 0) == DS_OK)
	{
	    // CopyMemory((PVOID)region_0, (PVOID)((s8*)sample_data + ((*sample_index)*sound_info->bytes_per_sample)), region_0_size);
	    // *sample_index = (*sample_index + (region_0_size/sound_info->bytes_per_sample))%sample_count;

	    // CopyMemory((PVOID)region_1, (PVOID)((s8*)sample_data + ((*sample_index)*sound_info->bytes_per_sample)), region_1_size);
	    // *sample_index = (*sample_index + (region_1_size/sound_info->bytes_per_sample))%sample_count;

	    // write.

	    s16* sample_out = (s16*)region_0;
	    for(u32 s = 0; s < (region_0_size/sound_info->bytes_per_sample); s++)
	    {
		s16* samples = (s16*)( (s8*)sample_data + ( (*sample_index) * sound_info->bytes_per_sample ) );
		
		sample_out[0] = samples[0]; // L 
		sample_out[1] = samples[1]; // R

		*sample_index = (*sample_index + 1)%sample_count;
		sample_out+=2;
	    }
 
	    sample_out = (s16*)region_1;
	    for(u32 s = 0; s < region_1_size/sound_info->bytes_per_sample; s++)
	    {
		s16* samples = (s16*)( (s8*)sample_data + ( (*sample_index) * sound_info->bytes_per_sample ) );
		
		sample_out[0] = samples[0]; // L
		sample_out[1] = samples[1]; // R

		*sample_index = (*sample_index + 1)%sample_count;
		sample_out+=2;
	    }
	    
	    if(sound_info->sound_buffer->Unlock(region_0, region_0_size, region_1, region_1_size) != DS_OK)
	    {
		OutputDebugStringA("'IDirectSoundBuffer8::Unlock' failed!\n");
	    }
	}
	else
	{
	    OutputDebugStringA("'IDirectSoundBuffer8::Lock' failed!\n");
	}
    }
    else
    {
	OutputDebugStringA("'IDirectSoundBuffer8::GetCurrentPosition' failed!\n");
    }    
}


