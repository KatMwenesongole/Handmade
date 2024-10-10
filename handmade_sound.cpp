/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

 Notice: (C) Copyright 2024 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/
#pragma once

#define WAVE_RIFF_CODE(a, b, c, d) (((u32)a << 0) | ((u32)b << 8) | ((u32)c << 16) | ((u32)d << 24))
enum
{
    WAVE_CHUNKID_DATA   = WAVE_RIFF_CODE('d', 'a', 't', 'a'),
    WAVE_CHUNKID_FORMAT = WAVE_RIFF_CODE('f', 'm', 't', ' '),
    WAVE_CHUNKID_RIFF   = WAVE_RIFF_CODE('R', 'I', 'F', 'F'),
    WAVE_CHUNKID_WAVE   = WAVE_RIFF_CODE('W', 'A', 'V', 'E')
};

#pragma pack(push, 1)
struct wave_header
{
    u32 riff_id;
    u32  size;
    u32 wave_id;
};
struct wave_format_header
{
    u16 audio_format;          // must be PCM (1)
    u16 channel_count;         // must be 2 (Stereo)
    u32 samples_per_sec;       // must be 48 000 Hz
    u32 average_bytes_per_sec; 
    u16 block_align;           // must be 4
    u16 bits_per_sample;       // must be 16
};
struct wave_chunk_header
{
    u32 id;
    u32 size;
};
#pragma pack(pop)

internal b32 wave_load(s8* sound_file, s16** sample_data, s32* sample_size)
{
    b32 success = false;
    
    io_file file = io_readfile(sound_file);
    if(file.source)
    {
	b32 found_format = false;
	b32 found_data   = false;
	
	wave_header* header = (wave_header*)file.source;
	ASSERT(header->riff_id == WAVE_CHUNKID_RIFF);
	ASSERT(header->wave_id == WAVE_CHUNKID_WAVE);

	wave_chunk_header* chunk = (wave_chunk_header*)((s8*)header + sizeof(wave_header));
	while(!(found_format && found_data))
	{
	    if(chunk->id == WAVE_CHUNKID_FORMAT)
	    {
		wave_format_header* format_header = (wave_format_header*)((s8*)chunk + sizeof(wave_chunk_header));
		ASSERT(format_header->audio_format    == 1); 
		ASSERT(format_header->channel_count   == 2); 
		ASSERT(format_header->samples_per_sec == 48000);
		ASSERT(format_header->bits_per_sample == 16);

		chunk = (wave_chunk_header*)((s8*)chunk + sizeof(wave_chunk_header) + chunk->size);
		
		found_format = true;
	    }
	    else if(chunk->id == WAVE_CHUNKID_DATA)
	    {
		*sample_data = (s16*)((s8*)chunk + sizeof(wave_chunk_header));
		*sample_size = chunk->size;
		
		// mem_copy((s8*)chunk + sizeof(wave_chunk_header), sample_data, chunk->size);

		found_data = true;
	    }
	}
	
    }
    
    return(success);
}



   // // region 0
   // 	    s16* sample_out = (s16*)region_0;
   // 	    for(s32 s = 0; s < region_0_size/sound_info->bytes_per_sample; s++)
   // 	    {
   // 		r32 t = (sound_info->sample_index/(r32)(sound_info->samples_per_sec/sound_info->period))*TAU;
   // 		s16 wave_value = sinf(t)*sound_info->volume;
			    
   // 		*sample_out++ = wave_value; 
   // 		*sample_out++ = wave_value;
		
   // 		sound_info->sample_index = (sound_info->sample_index + 1)%(sound_info->samples_per_sec/sound_info->period);
   // 	    }
   // 	    // region 1

   // 	    sample_out = (s16*)region_1;
   // 	    for(s32 s = 0; s < region_1_size/sound_info->bytes_per_sample; s++)
   // 	    {
   // 		r32 t = (sound->sample_index/(r32)(sound->samples_per_sec/sound->period))*TAU;
   // 		s16 wave_value = sinf(t)*sound->volume;
			    
   // 		*sample_out++ = wave_value; 
   // 		*sample_out++ = wave_value;
		
   // 		sound->sample_index = (sound->sample_index + 1)%(sound->samples_per_sec/sound->period);
   // 	    }
