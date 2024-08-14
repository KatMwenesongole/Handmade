struct bitmap_header_v4
{
    // can only load & save (A8 R8 G8 B8) - BITMAP V4
    
    u16   signature; // must be 'BM' (0x4d42)
    u32   file_size;
    u16  reserved_0; // must be 0
    u16  reserved_1; // must be 0
    u32 byte_offset; // offset into the file the actual pixel array begins (must be 122)

    u32 header_size; // sizeof(BITMAPV4HEADER)
    s32       width;  
    s32      height; // positive (bottom-up DIB)
    
    u16 planes;              // must be 1
    u16 bits_per_pixel;      // must be 32    
    u32 compression;         // must be BI_BITFIELDS (3)
    u32 image_size;          // must be 0
    s32 x_pixels_per_meter;  // must be 0 (no preference)
    s32 y_pixels_per_meter;  // must be 0 (no preference)
    u32        used_colours; // must be 0
    u32 significant_colours; // must be 0
    
    u32   red_mask; // must be 0x00FF0000
    u32 green_mask; // must be 0x0000FF00
    u32  blue_mask; // must be 0x000000FF
    u32 alpha_mask; // must be 0xFF000000

    u32          colour_space;     // must be 0
    CIEXYZTRIPLE colour_endpoints; // must be 0
    
    u32   red_tone; // must be 0
    u32 green_tone; // must be 0
    u32  blue_tone; // must be 0
};

struct bitmap_header
{
    u16   signature; // must be 'BM' (0x4d42)
    u32   file_size;
    u16  reserved_0; // must be 0
    u16  reserved_1; // must be 0
    u32 byte_offset; // offset into the file the actual pixel array begins (must be )

    u32 header_size; // sizeof(BITMAPINFOHEADER)
    s32       width;  
    s32      height; // positive (bottom-up DIB)
    
    u16 planes;              // must be 1
    u16 bits_per_pixel;      // must be 32    
    u32 compression;         // must be BI_RGB (0)
    u32 image_size;          // must be 0
    s32 x_pixels_per_meter;  // must be 0 (no preference)
    s32 y_pixels_per_meter;  // must be 0 (no preference)
    u32        used_colours; // must be 0
    u32 significant_colours; // must be 0
};
