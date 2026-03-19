/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

Notice: (C) Copyright 2024 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/

// asset_sound should have a loop option
// don't play the same sound twice, so check all current playing sounds.
// 
//


#pragma once

struct sound_information
{
    b32 sound_playing;
    
    // properties
    s32   bytes_per_sample;
    s32 samples_per_sec;
    r32 volume;
    
    asset_sound* sounds[6];
    s32 sound_count;

    s16* sound_buffer;
    s32  sound_buffer_size;
    s32  sound_buffer_sample_count;
    
    s32  sound_cursor;
    
    s32  sample_index;
};

internal void
mixer_update(sound_information* mixer)
{
    s32 write_offset = (mixer->sample_index*mixer->bytes_per_sample)%mixer->sound_buffer_size;
    
    s32 write_size0 = 0;
    s32 write_size1 = 0;

    if(write_offset > mixer->sound_cursor) // play cusor > write_cursor 
    {
	write_size0 = (mixer->sample_index*mixer->bytes_per_sample) - mixer->sound_cursor;
    }
    else if(mixer->sound_cursor > write_offset)
    {
	write_size0 = mixer->sound_buffer_size - mixer->sound_cursor;
	write_size1 = mixer->sample_index*mixer->bytes_per_sample;
    }
    else if(mixer->sound_cursor == write_offset)
    {
	write_size0 = 0;
    }
	
    if(!mixer->sample_index && !mixer->sound_cursor)
    {
	write_size0 = mixer->sound_buffer_size;
    }

    // quite buffer
    {
	s16* mixer_sample = (s16*)((s8*)mixer->sound_buffer + mixer->sound_cursor);
	for(s32 s = 0; s < (write_size0/mixer->bytes_per_sample); s++)
	{
	    mixer_sample[0] = 0;
	    mixer_sample[1] = 0;

	    mixer_sample+=2;
	}
	
	mixer_sample = (s16*)mixer->sound_buffer;
	for(s32 s = 0; s < (write_size1/mixer->bytes_per_sample); s++)
	{
	    mixer_sample[0] = 0;
	    mixer_sample[1] = 0;

	    mixer_sample+=2;
	}
    }
	
    mixer->sound_playing = false;
    
    for(s32 current_sound = 0; current_sound < mixer->sound_count; current_sound++)
    {
	asset_sound* sound = mixer->sounds[current_sound];
	if(sound)
	{
	    mixer->sound_playing = true;
	    
	    s16* mixer_sample = (s16*)((s8*)mixer->sound_buffer + mixer->sound_cursor);
	    s16* sound_sample = (s16*)((s8*)sound->samples + (sound->current_sample*mixer->bytes_per_sample));

	    r32  left_pan = (sound->pan <= 0.0f) ? 1.0f : (1.0f-sound->pan);
	    r32 right_pan = (sound->pan >= 0.0f) ? 1.0f : (1.0f+sound->pan);
		
	    for(s32 s = 0; s < (write_size0/mixer->bytes_per_sample); s++)
	    {
		mixer_sample[0] += (sound_sample[0] * sound->volume * left_pan )*mixer->volume; // L
		mixer_sample[1] += (sound_sample[1] * sound->volume * right_pan)*mixer->volume; // R

		mixer_sample+=2;
		sound_sample+=2;

		sound->current_sample++;
		if(sound->current_sample > sound->samples_size/mixer->bytes_per_sample)
		{
		    sound->current_sample = 0;
		    mixer->sounds[current_sound] = 0;
		    break;
		}
	    }

	    if(mixer->sounds[current_sound])
	    {
		mixer_sample = (s16*)mixer->sound_buffer;
		for(s32 s = 0; s < (write_size1/mixer->bytes_per_sample); s++)
		{
		    mixer_sample[0] += (sound_sample[0] * sound->volume *  left_pan)*mixer->volume; // L
		    mixer_sample[1] += (sound_sample[1] * sound->volume * right_pan)*mixer->volume; // R

		    mixer_sample+=2;
		    sound_sample+=2;

		    sound->current_sample++;
		    if(sound->current_sample > sound->samples_size/mixer->bytes_per_sample)
		    {
			sound->current_sample = 0;
			mixer->sounds[current_sound] = 0;
			break;
		    }
		}
	    }
	    
	}
    }

    mixer->sound_cursor = mixer->sample_index*mixer->bytes_per_sample;
}

internal void
mixer_playsound(sound_information* mixer, asset_sound* sound)
{
    for(s32 s = 0; s < mixer->sound_count; s++)
    {
	if(!mixer->sounds[s])
	{
	    mixer->sounds[s] = sound;
	    break;
	}
    }
}







