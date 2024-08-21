#define WAVE_RIFF_CODE(a, b, c, d) (((u32)a << 8) | ((u32)b << 16) | ((u32)c << 24) | ((u32)d << 32)))
enum
{
    WAVE_CHUNKID_FORMAT = WAVE_RIFF_CODE('f', 'm', 't', ' '),
    WAVE_CHUNKID_RIFF   = WAVE_RIFF_CODE('R', 'I', 'F', 'F'),
    WAVE_CHUNKID_WAVE   = WAVE_RIFF_CODE('W', 'A', 'V', 'E')
};

struct wave_header
{
    u32 riff_id;
    u32  size;
    u32 wave_id;
    
};
struct wave_format_header
{
    u16 format_tag;
    u16 channel_count;
    u32 samples_per_sec;
    u32 average_bytes_per_sec;
    u32 block_align;
    u32 bits_per_sample;
    u32 size;
    u16 valid_bits_per_sample;
    u32 channel_mask;
    u8 sub_format[16];
};
struct wave_chunk_header
{
    u32 id;
    u32 size;
};


internal b32 wave_load(s8* sound_file)
{
    io_file file = io_readfile(sound_file);
    if(file.source)
    {
	wave_header* header = (wave_header*)file.source;
	ASSERT(header->riff_id == WAVE_CHUNKID_RIFF);
	ASSERT(header->wave_id == WAVE_CHUNKID_WAVE);
	

	
    }
}

