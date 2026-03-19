/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

Notice: (C) Copyright 2024 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/
#pragma once

#include <stdio.h>
// TODO: 
//  sprintf
//  fopen() / fclose()
//  fprintf

// load.

#pragma pack(push, 1)

#define WAVE_RIFF_CODE(a, b, c, d) (((u32)a << 0) | ((u32)b << 8) | ((u32)c << 16) | ((u32)d << 24))
enum
{
    WAVE_CHUNKID_DATA   = WAVE_RIFF_CODE('d', 'a', 't', 'a'),
    WAVE_CHUNKID_FORMAT = WAVE_RIFF_CODE('f', 'm', 't', ' '),
    WAVE_CHUNKID_RIFF   = WAVE_RIFF_CODE('R', 'I', 'F', 'F'),
    WAVE_CHUNKID_WAVE   = WAVE_RIFF_CODE('W', 'A', 'V', 'E')
};
struct wave_header        // @ sound
{
    u32 riff_id;
    u32  size;
    u32 wave_id;
};
struct wave_format_header // @ sound
{
    u16 audio_format;          // must be PCM (1)
    u16 channel_count;         // must be 2 (Stereo)
    u32 samples_per_sec;       // must be 48 000 Hz
    u32 average_bytes_per_sec; 
    u16 block_align;           // must be 4
    u16 bits_per_sample;       // must be 16
};
struct wave_chunk_header  // @ sound
{
    u32 id;
    u32 size;
};
struct       bitmap_header // @ texture
{
    // (A8 R8 G8 B8 only)
    // signature   - must be 'BM' (0x4d42)
    // reserved    - must be 0
    // byte_offset - refers to the offset into the file the actual pixel array starts
    // width       - bitmap width
    // height      - bitmap height
    
    u16   signature;   
    u32   file_size;
    u16  reserved_0; 
    u16  reserved_1; 
    u32 byte_offset;

    u32 header_size;            
    s32       width;           
    s32      height;

    // write.
    u16 planes;              // must be 1
    u16 bitsperpixel;        // must be 24
    u32 compression;         // must be BI_RGB
    u32 image_size;          // must be 0
    u32 x_pixels_per_meter;  // must be 0 (no preference)
    u32 y_pixels_per_meter;  // must be 0 (no preference)
    u32        used_colours; // must be 0
    u32 significant_colours; // must be 0
};

struct trianglemesh_header // @ trianglemesh
{
    s8 name[32];
    
    s32 size;
    
    s32   vertex_count;
    s32     list_count;

    s32 orientation_offset;
    s32      vertex_offset;
    s32      normal_offset;
    s32    binormal_offset;
    s32     tangent_offset;
    s32          uv_offset;
    
    s32        list_offset;
};
struct trianglelist_header // @ trainglelist
{
    s8 name[32];
    u32 offset;
    u32  count;

    // @ material
    v4 colour;
};

struct animation_header
{
    s32 keyframe_count;
    s32 keyframes_per_sec;
};
struct animation_keyframe_header
{
    r32 frame_time;
    
    r32 position_x;
    r32 position_y;
    r32 position_z;
    
    r32 rotation_x;
    r32 rotation_y;
    r32 rotation_z;
    
    r32 scale_x;
    r32 scale_y;
    r32 scale_z;
};

#pragma pack(pop)
//

struct transform
{
    v3 position;
    v3 rotation;
    v3 scale = { 1.0, 1.0, 1.0 };
};
enum asset_sort
{
    ASSET_SHADER            = 0x01,
    ASSET_TEXTURE           = 0x02,
    ASSET_MATERIAL          = 0x03,
    ASSET_TRIANGLEMESH      = 0x04,
    ASSET_TRIANGLELIST      = 0x05,
    ASSET_MATERIALLIST_PAIR = 0x06,
    ASSET_MATERIALLIST      = 0x07,
    ASSET_ENTITY            = 0x08,
    ASSET_SOUND             = 0x0C,
    ASSET_ANIMATION         = 0x0D,
    ASSET_KEYFRAME          = 0x0E,
    ASSET_GAME_PANEL        = 0x09,
    ASSET_COLLIDER          = 0x0F
};

#pragma pack(push, 1)
struct asset_header
{
    asset_sort sort;
    u32 handle;
    u32 struct_size;
};
struct asset_data_shader
{
    asset_header header;
    s8 vs_path[HANDMADE_STRING_LARGE];
    s8 ps_path[HANDMADE_STRING_LARGE];
};
struct asset_data_texture
{
    asset_header header;
    s8 bmp_path[HANDMADE_STRING_LARGE];
};
struct asset_data_sound
{
    asset_header header;
    s8 wave_path[HANDMADE_STRING_LARGE];
    r32 volume;
    r32 pan;
};
struct asset_data_animation
{
    asset_header header;
    s8 anim_path[HANDMADE_STRING_LARGE];
};
struct asset_data_collider
{
    asset_header header;
    v3 vertex0; 
    v3 vertex1;
    transform orientation;
};
struct asset_data_material
{
    asset_header header;
    u32  shader_handle;
    u32 texture_handle;
    s8   name[32];
    v4  colour;
    r32 shininess;
};
struct asset_data_trianglemesh
{
    asset_header header;
    s8 mesh_path[HANDMADE_STRING_LARGE];
};
struct asset_data_materiallist
{
    asset_header header;
    u32 trianglemesh_handle;
    s32 pair_count;
};
struct asset_data_materiallist_pair
{
    asset_header header;

    u32 materiallist_handle;
    u32 trianglelist_handle;
    u32     material_handle;
};
struct asset_data_entity
{
    asset_header header;

    u32 trianglemesh_handle;
    u32 materiallist_handle;
    u32    animation_handle;
    u32     collider_handle;

    transform orientation;
};

// GAME

struct asset_data_game_panel
{
    asset_header header;
    
    u32       entity_handle; // asset_entity

    u32      handscroll_handle; // (canvases)
};

#pragma pack(pop)

struct asset_shader
{
    asset_header header;
    GLuint obj;
};
struct asset_texture
{
    asset_header header;
    GLuint obj;
};
struct asset_sound
{
    asset_header header;
    
    s16* samples;
    s32  samples_size;
    r32  volume;
    r32  pan; //  0 is centre, -1 only left, 1 is only right.
    
    s32 current_sample;
};
struct asset_animation
{
    asset_header header;
    s32 keyframe_count;
    s32 keyframes_per_sec;
    s32 current_frame;
    r32 duration;
    r32 multiplier;
};
struct asset_keyframe
{
    asset_header header;
    
    u32 anim_handle;
    
    r32 keyframe;
    transform orientation;
};
struct asset_material
{
    asset_header header;

    // data.
    s8 name[HANDMADE_STRING_SMALL];
    v4 colour;
    r32 shininess;

    // handles.
    u32  shader_handle;
    u32 texture_handle;
};
struct asset_trianglemesh
{
    asset_header header;
    GLuint vao;
    u32   vertex_count;
    
    u32 list_handle;
    u32 list_count;

    u32 default_materiallist_handle; // ???
    
    transform orientation;
};
struct asset_trianglelist
{
    asset_header header;
    u32     trianglemesh_handle;

    u32  index;
    u32  count;
    u32 offset;
};
struct asset_materiallist
{
    asset_header header;
    u32 trianglemesh_handle;
    
    u32 pair_count;   
};
struct asset_materiallist_pair
{
    asset_header header;
    u32 materiallist_handle;
    
    u32      list_handle;
    u32  material_handle;
};
struct asset_collider // box collider.
{
    asset_header header;
    v3 vertex0; 
    v3 vertex1;
    transform orientation;
};
struct asset_entity
{
    asset_header header;

    u32 id;
    u32  trianglemesh_handle; 
    u32 material_list_handle;
    u32          anim_handle;
    u32 handle_collider;

    transform orientation;
};

// Game

struct asset_game_panel
{
    asset_header header;
    
    u32            entity_handle; // They are entites.
    
    u32 handscroll_handle;
    
};
struct assets_information
{
    asset_header* headers;
    s32 size;
    s32 used;
    s32 count;

    asset_header* data_headers;
    s32 data_size;
    s32 data_used;
    s32 data_count;

    memory_arena arena;

    // should this be here?
    asset_shader*       basic_shader;
    asset_shader*       basic_shader_flat;
    asset_texture*      basic_texture;
    asset_trianglemesh* basic_mesh;
    asset_material*     basic_material;
};

// hash.

#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
#define FIRSTH 37 /* also prime */

internal u32
assets_computehash(s8* str)
{ 
    u32 h = FIRSTH;
    while (*str) {
	h = (h * A) ^ (str[0] * B);
	str++;
    }
    return h; // or return h % C;
}

// get.

internal asset_header* assets_get(assets_information* Assets, u32 handle)
{
    asset_header* header = Assets->headers;
    s32 offset = 0;
    while(offset < Assets->used)
    {
	header = (asset_header*)((u8*)Assets->headers + offset);
	offset += header->struct_size;
	
	if(header->handle == handle) { return(header); }
    }
    return(0);
}
internal asset_header* assets_get_data(assets_information* Assets, u32 handle)
{
    asset_header* data_header = Assets->data_headers;
    s32 offset = 0;
    while(offset < Assets->data_used)
    {
	data_header = (asset_header*)((u8*)Assets->data_headers + offset);
	offset += data_header->struct_size;
	
	if(data_header->handle == handle) { return(data_header); }
    }
    
    return(0);
}

// get. (specific)

internal asset_materiallist_pair* assets_get_materiallist_pair(assets_information* Assets, u32 materiallist_handle, u32 list_handle)
{
    asset_header* header = Assets->headers;
    s32 offset = 0;
    while(offset < Assets->used)
    {
	header = (asset_header*)((u8*)Assets->headers + offset);
	offset += header->struct_size;

	if(header->sort == ASSET_MATERIALLIST_PAIR)
	{
	    asset_materiallist_pair* pair = (asset_materiallist_pair*)header;
	    if(pair->materiallist_handle == materiallist_handle &&
	       pair->list_handle         == list_handle)
	    {
		return(pair);
	    }
	}
    }
    return(0);
}

// sync.

internal asset_data_entity* assets_sync_entity(assets_information* Assets, asset_entity* entity)
{
    asset_data_entity* entity_data = (asset_data_entity*)assets_get_data(Assets, entity->header.handle);
    if(entity_data)
    {
	entity_data->trianglemesh_handle          = entity ->trianglemesh_handle;
	entity_data->materiallist_handle = entity->material_list_handle;
	entity_data->orientation          = entity->orientation;
    }
    return(entity_data);
}
internal asset_data_game_panel* assets_sync_game_panel(assets_information* Assets, asset_game_panel* panel)
{
    asset_data_game_panel* panel_data = (asset_data_game_panel*)assets_get_data(Assets, panel->header.handle);
    if(panel_data)
    {
	panel_data-> handscroll_handle = panel-> handscroll_handle;
	panel_data->  entity_handle = panel->  entity_handle;
    }
    return(panel_data);
}

// compile.

internal GLuint assets_opengl_compileshader (s8* vs_source, u32 vs_size,
					     s8* ps_source, u32 ps_size)
{
    GLuint program = 0;
    
    GLuint v_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource (v_shader, 1, &(GLchar*)vs_source, &(GLint)vs_size);
    glCompileShader(v_shader);
    
    GLint v_status = 0;
    glGetShaderiv(v_shader, GL_COMPILE_STATUS, &v_status);

    if(v_status)
    {
	GLuint p_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(p_shader, 1, &(GLchar*)ps_source, &(GLint)ps_size);
	glCompileShader(p_shader);
	
	GLint p_status = 0;
	glGetShaderiv(p_shader, GL_COMPILE_STATUS, &p_status);

	if(p_status)
	{
	    program = glCreateProgram();
	
	    glAttachShader(program, v_shader);
	    glAttachShader(program, p_shader);
	    glLinkProgram(program);

	    glDeleteShader(p_shader);
	}
	else
	{
	    GLint shader_log_size;
	    glGetShaderiv(p_shader, GL_INFO_LOG_LENGTH, &shader_log_size);

	    GLchar shader_info[1024];
	    glGetShaderInfoLog(p_shader, shader_log_size, &shader_log_size, shader_info);

	    //TEMP!
	    io_writefile("../data/ps_shader_log.txt", shader_log_size, shader_info);

	    //os_debug("'glCompileShader' failed! (pixel shader)\n");
	    //os_debug(shader_info);
	}
	
	glDeleteShader(v_shader);
    }
    else
    {
	GLint shader_log_size;
	glGetShaderiv(v_shader, GL_INFO_LOG_LENGTH, &shader_log_size);

	GLchar shader_info[1024];
	glGetShaderInfoLog(v_shader, shader_log_size, &shader_log_size, shader_info);

	//TEMP!
	io_writefile("../data/vs_shader_log.txt", shader_log_size, shader_info);

	//os_debug("'glCompileShader' failed! (vertex shader)\n");
	//os_debug(shader_info);
    }

    return(program);
}
internal GLuint assets_opengl_compiletexture(s8* source, u32 width, u32 height)
{
    GLuint obj = 0;

    glGenTextures(1, &obj);
    glBindTexture(GL_TEXTURE_2D, obj);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, source);
    glGenerateMipmap(GL_TEXTURE_2D);	

    return(obj);
}
internal GLuint assets_opengl_compilemesh   (u32 vertex_count, v3* vertices, v2* uvs, v3* normals)
{
    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v3) * vertex_count, vertices, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    GLuint uv_vbo = 0;
    glGenBuffers(1, &uv_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, uv_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v2) * vertex_count, uvs, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    GLuint normal_vbo = 0;
    glGenBuffers(1, &normal_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, normal_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v3) * vertex_count, normals, GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    return(vao);
}
internal void   assets_sound_compilesound(void* sound_data, void* sample_data, s32* sample_size)
{
    b32 found_format = false;
    b32 found_data   = false;
	
    wave_header* header = (wave_header*)sound_data;
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
	    // *sample_data = (s16*)((s8*)chunk + sizeof(wave_chunk_header));
	    // *sample_size = chunk->size;

	    //samples     = (s16*)((s8*)chunk + sizeof(wave_chunk_header));
	    //*sample_size = chunk->size;
		
	    mem_copy((s8*)chunk + sizeof(wave_chunk_header), sample_data, chunk->size);
	    *sample_size = chunk->size;

	    found_data = true;
	}
    }
}

// check.

internal asset_header* asset_check(assets_information* Assets, u32 hash)
{
    s32 size = 0;
    while(size < Assets->used)
    {
	asset_header* header = (asset_header*)((u8*)Assets->headers + size);

	if(header->handle == hash) { return(header); }
	
	size += header->struct_size;
    }
    return(0);
}
internal asset_header* asset_data_check(assets_information* Assets, u32 hash)
{
    s32 size = 0;
    while(size < Assets->data_used)
    {
	asset_header* data_header = (asset_header*)((u8*)Assets->data_headers + size);

	if(data_header->handle == hash) { return(data_header); }
	
	size += data_header->struct_size;
    }
    return(0);
}

// append.

internal asset_header* asset_append(assets_information* Assets, asset_sort sort, void* _struct, u32 struct_size, u32 handle)
{
    ASSERT((Assets->used + (sizeof(asset_header) + struct_size)) <= Assets->size)

    asset_header* header = (asset_header*)((u8*)Assets->headers + Assets->used);
    
    ((asset_header*)_struct)->sort        = sort;
    ((asset_header*)_struct)->handle      = handle;
    ((asset_header*)_struct)->struct_size = struct_size;

    mem_copy(_struct, (u8*)header, struct_size);

    Assets->count++;
    Assets->used += header->struct_size;

    return(header);

    // note, could we do away with the data size parameter 
    // and just look up the asset type and use the corresponding struct size?
}
internal asset_header* asset_data_append(assets_information* Assets, asset_sort sort, void* _struct, u32 struct_size, u32 handle)
{
    ASSERT((Assets->data_used + (sizeof(asset_header) + struct_size)) <= Assets->data_size)

    asset_header* data_header = (asset_header*)((u8*)Assets->data_headers + Assets->data_used);

    ((asset_header*)_struct)->sort        = sort;
    ((asset_header*)_struct)->handle      = handle;
    ((asset_header*)_struct)->struct_size = struct_size;

    mem_copy(_struct, (u8*)data_header, struct_size);

    Assets->data_count++;
    Assets->data_used += data_header->struct_size;
    
    return(data_header);
}

// create. (data)

internal asset_data_shader*            assets_data_create_shader           (assets_information* Assets, s8* vs_path, s8* ps_path)
{
    // combine.
    s8 hash_string[HANDMADE_STRING_LARGE];
    sprintf(hash_string, "%s#%s", vs_path, ps_path);
    u32 shader_hash = assets_computehash(hash_string);

    asset_data_shader* return_data = (asset_data_shader*)asset_data_check(Assets, shader_hash); // check.
    if(!return_data) 
    {
	asset_data_shader shader_data = {};
	mem_copy(vs_path, shader_data.vs_path, HANDMADE_STRING_LARGE);
	mem_copy(ps_path, shader_data.ps_path, HANDMADE_STRING_LARGE);
	
	return((asset_data_shader*)asset_data_append(Assets, ASSET_SHADER, &shader_data, sizeof(asset_data_shader), shader_hash));
    }
    return(return_data);
}
internal asset_data_texture*           assets_data_create_texture          (assets_information* Assets, s8* bmp_path)
{
    u32 texture_hash = assets_computehash(bmp_path);

    asset_data_texture* return_data = (asset_data_texture*)asset_data_check(Assets, texture_hash);
    if(!return_data) // check.
    {
	asset_data_texture texture_data = {};
	mem_copy(bmp_path, texture_data.bmp_path, HANDMADE_STRING_LARGE);
	return((asset_data_texture*)asset_data_append(Assets, ASSET_TEXTURE, &texture_data, sizeof(asset_data_texture), texture_hash));
    }
    return(return_data);
}
internal asset_data_sound*             assets_data_create_sound            (assets_information* Assets, s8* wave_path, r32 volume, r32 pan)
{
    u32 hash = assets_computehash(wave_path);

    asset_data_sound* return_data = (asset_data_sound*)asset_data_check(Assets, hash);
    if(!return_data) // check.
    {
	asset_data_sound sound_data = {};
	mem_copy(wave_path, sound_data.wave_path, HANDMADE_STRING_LARGE);
	sound_data.volume = volume;
	sound_data.pan = pan;
	return((asset_data_sound*)asset_data_append(Assets, ASSET_SOUND, &sound_data, sizeof(asset_data_sound), hash));
    }
    return(return_data);
}
internal asset_data_animation*         assets_data_create_animation        (assets_information* Assets, s8* anim_path)
{
    u32 hash = assets_computehash(anim_path);

    asset_data_animation* return_data = (asset_data_animation*)asset_data_check(Assets, hash);
    if(!return_data) // check.
    {
	asset_data_animation anim_data = {};
	mem_copy(anim_path, anim_data.anim_path, HANDMADE_STRING_LARGE);
	return((asset_data_animation*)asset_data_append(Assets, ASSET_ANIMATION, &anim_data, sizeof(asset_data_animation), hash));
    }
    return(return_data);
}
internal asset_data_material*          assets_data_create_material         (assets_information* Assets, s8* name, u32 shader_handle, u32 texture_handle, v4 colour, r32 shininess)
{
    u32 material_hash = assets_computehash(name);

    asset_data_material* return_data = (asset_data_material*)asset_data_check(Assets, material_hash);  // check.
    if(!return_data)
    {
	asset_data_material material_data = {};

	material_data. shader_handle =  shader_handle;
	material_data.texture_handle = texture_handle;
	material_data.colour         = colour;
	material_data.shininess      = shininess;
	mem_copy(name, material_data.name, 32);
	
	return((asset_data_material*)asset_data_append(Assets, ASSET_MATERIAL, &material_data, sizeof(asset_data_material), material_hash));
    }
    return(return_data);
}
internal asset_data_trianglemesh*      assets_data_create_trianglemesh     (assets_information* Assets, s8* mesh_path)
{
    u32 mesh_hash = assets_computehash(mesh_path);

    asset_data_trianglemesh* return_data = (asset_data_trianglemesh*)asset_data_check(Assets, mesh_hash); // check.
    if(!return_data) 
    {
	asset_data_trianglemesh trianglemesh_data = {};
	mem_copy(mesh_path, trianglemesh_data.mesh_path, HANDMADE_STRING_LARGE);
	
	return((asset_data_trianglemesh*)asset_data_append(Assets, ASSET_TRIANGLEMESH, &trianglemesh_data, sizeof(asset_data_trianglemesh), mesh_hash));
    }
    return(return_data);
}
internal asset_data_materiallist*      assets_data_create_materiallist     (assets_information* Assets, u32 mesh_handle, s32 pair_count)
{
    s8 hash_string[HANDMADE_STRING_LARGE];
    sprintf(hash_string, "%i", mesh_handle);
    u32 material_list_hash = assets_computehash(hash_string) + Assets->count;

    asset_data_materiallist* return_data = (asset_data_materiallist*)asset_data_check(Assets, material_list_hash);// check.
    if(!return_data) 
    {
	asset_data_materiallist materiallist_data = {};
	materiallist_data.trianglemesh_handle = mesh_handle;
	materiallist_data.pair_count = pair_count;

	return((asset_data_materiallist*)asset_data_append(Assets, ASSET_MATERIALLIST, &materiallist_data, sizeof(asset_data_materiallist), material_list_hash));
    }
    return(return_data);
}
internal asset_data_materiallist_pair* assets_data_create_materiallist_pair(assets_information* Assets, u32 materiallist_handle, u32 trianglelist_handle, u32 material_handle)
{
    s8 hash_string[HANDMADE_STRING_LARGE];
    sprintf(hash_string, "%i#%i#%i", materiallist_handle, trianglelist_handle, material_handle);
    u32 materiallist_pair_hash = assets_computehash(hash_string);

    asset_data_materiallist_pair* return_data = (asset_data_materiallist_pair*)asset_data_check(Assets, materiallist_pair_hash); // check.
    if(!return_data) 
    {
	asset_data_materiallist_pair materiallist_pair_data = {};

	materiallist_pair_data.materiallist_handle = materiallist_handle;
	materiallist_pair_data.trianglelist_handle = trianglelist_handle;
	materiallist_pair_data.material_handle     = material_handle;
	    
	return((asset_data_materiallist_pair*)asset_data_append(Assets, ASSET_MATERIALLIST_PAIR, &materiallist_pair_data, sizeof(asset_data_materiallist_pair), materiallist_pair_hash));
    }
    return(return_data);
}
internal asset_data_entity*            assets_data_create_entity           (assets_information* Assets, u32 mesh_handle, u32 materiallist_handle, transform orientation, s32 id)
{
    s8 hash_string[HANDMADE_STRING_LARGE];
    sprintf(hash_string, "%i#%i#%i", mesh_handle, materiallist_handle, id);
    u32 entity_hash = assets_computehash(hash_string);

    asset_data_entity* return_data = (asset_data_entity*)asset_data_check(Assets, entity_hash); // check.
    if(!return_data) 
    {
	asset_data_entity entity_data = {};
	    
	entity_data.trianglemesh_handle = mesh_handle;
	entity_data.materiallist_handle = materiallist_handle;
	entity_data.orientation = orientation;
	    
	return((asset_data_entity*)asset_data_append(Assets, ASSET_ENTITY, &entity_data, sizeof(asset_data_entity), entity_hash));
    }
    return(return_data);
}

// create. (data) - game.

internal asset_data_game_panel* assets_data_create_game_panel(assets_information* Assets,
							  u32   handscroll_handle,
							      u32    entity_handle)
{
    s8 hash_string[HANDMADE_STRING_LARGE];
    sprintf(hash_string, "%i#%i", handscroll_handle, entity_handle);
    u32 hash = assets_computehash(hash_string);

    asset_data_game_panel* return_data = (asset_data_game_panel*)asset_data_check(Assets, hash); // check.
    if(!return_data) 
    {
	asset_data_game_panel panel_data = {};	    
	panel_data.handscroll_handle = handscroll_handle;
	panel_data.    entity_handle =     entity_handle;
	return((asset_data_game_panel*)asset_data_append(Assets, ASSET_GAME_PANEL, &panel_data, sizeof(asset_data_game_panel), hash));
    }
    return(return_data);
}

// create.

internal asset_shader*            assets_create_shader           (assets_information* Assets, asset_data_shader* shader_data)
{
    asset_shader* return_shader = (asset_shader*)asset_check(Assets, shader_data->header.handle); // check.
    if(!return_shader) 
    {
	io_file vs_file = io_readfile(shader_data->vs_path);
	io_file ps_file = io_readfile(shader_data->ps_path);
	if(vs_file.source && ps_file.source)
	{
	    asset_shader shader = {};
	
	    shader.obj = assets_opengl_compileshader((s8*)vs_file.source, vs_file.size, (s8*)ps_file.source, ps_file.size);
	    io_freefile(vs_file);
	    io_freefile(ps_file);

	    if(!shader.obj) return(0);

	    return((asset_shader*)asset_append(Assets, ASSET_SHADER, &shader, sizeof(asset_shader), shader_data->header.handle));
	}
    }
    return(return_shader);
}
internal asset_texture*           assets_create_texture          (assets_information* Assets, asset_data_texture* texture_data)
{
    asset_texture* return_texture = (asset_texture*)asset_check(Assets, texture_data->header.handle); // check.
    if(!return_texture) 
    {
	io_file file = io_readfile(texture_data->bmp_path);
	if(file.source)
	{
	    asset_texture texture = {};
	
	    bitmap_header* bitmap = (bitmap_header*)file.source;
	    u8* source = (u8*)bitmap + bitmap->byte_offset;
	
	    texture.obj = assets_opengl_compiletexture((s8*)source, bitmap->width, bitmap->height);
	    io_freefile(file);
	
	    if(!texture.obj) return(0);

	    return((asset_texture*)asset_append(Assets, ASSET_TEXTURE, &texture, sizeof(asset_texture), texture_data->header.handle));
	}
    }
    return(return_texture);
}
internal asset_sound*             assets_create_sound            (assets_information* Assets, asset_data_sound* sound_data)
{
    asset_sound* return_sound = (asset_sound*)asset_check(Assets, sound_data->header.handle); // check.
    if(!return_sound) 
    {
	io_file file = io_readfile(sound_data->wave_path);
	if(file.source)
	{
	    asset_sound sound = {};

	    void* sound_buffer = stack_push(&Assets->arena, megabytes(50));

	    assets_sound_compilesound(file.source, sound_buffer, &sound.samples_size);

	    stack_pop(&Assets->arena, megabytes(50));  

	    sound.samples = (s16*)stack_push(&Assets->arena, sound.samples_size);

	    assets_sound_compilesound(file.source, sound.samples, &sound.samples_size);
	    
	    sound.volume = sound_data->volume;
	    sound.pan = sound_data->pan;

	    if(!sound.samples) return(0);

	    io_freefile(file);

	    return((asset_sound*)asset_append(Assets, ASSET_SOUND, &sound, sizeof(asset_sound), sound_data->header.handle));
	}
    }
    return(return_sound);
}
internal asset_animation*         assets_create_animation        (assets_information* Assets, asset_data_animation* anim_data)
{
    asset_animation* return_anim = (asset_animation*)asset_check(Assets, anim_data->header.handle); // check.
    if(!return_anim) 
    {
	io_file file = io_readfile(anim_data->anim_path);
	if(file.source)
	{
	    asset_animation anim = {};
	    
	    animation_header* header = (animation_header*)file.source;

	    anim.keyframe_count    = header->keyframe_count;
	    anim.keyframes_per_sec = header->keyframes_per_sec;
	    anim.multiplier        = 1.0f;

	    asset_append(Assets, ASSET_ANIMATION, &anim, sizeof(asset_animation), anim_data->header.handle);

	    animation_keyframe_header* keyframe_header = (animation_keyframe_header*)((u8*)header + sizeof(animation_header));
	    for(s32 frame = 1; frame <= header->keyframe_count; frame++)
	    {
		asset_keyframe keyframe = {};
		
		keyframe.keyframe = keyframe_header->frame_time;
		keyframe.orientation.position = { keyframe_header->position_x, keyframe_header->position_y, keyframe_header->position_z };
		keyframe.orientation.rotation = { keyframe_header->rotation_x, keyframe_header->rotation_y, keyframe_header->rotation_z };
		keyframe.orientation.scale    = { keyframe_header->scale_x,    keyframe_header->scale_y,    keyframe_header->scale_z };
		
		asset_append(Assets, ASSET_KEYFRAME, &keyframe, sizeof(keyframe), anim_data->header.handle + frame);
	    }
	    io_freefile(file);
	}
    }
    return(return_anim);
}
internal asset_material*          assets_create_material         (assets_information* Assets, asset_data_material* material_data)
{
    asset_material* return_material = (asset_material*)asset_check(Assets, material_data->header.handle); // check.
    if(!return_material) 
    {
	asset_material material = {};

	mem_copy(material_data->name, material.name, 32);
	material. shader_handle = material_data->shader_handle;
	material.texture_handle = material_data->texture_handle;
	material.colour         = material_data->colour;
	material.shininess      = material_data->shininess;

	return((asset_material*)asset_append(Assets, ASSET_MATERIAL, &material, sizeof(asset_material), material_data->header.handle));
    }
    return(return_material);
}
internal asset_materiallist*      assets_create_materiallist     (assets_information* Assets, asset_data_materiallist* materiallist_data)
{
    asset_materiallist* return_materiallist = (asset_materiallist*)asset_check(Assets, materiallist_data->header.handle); // check.
    if(!return_materiallist) 
    {
	asset_materiallist materiallist = {};
    
	materiallist.trianglemesh_handle = materiallist_data->trianglemesh_handle;
	materiallist.pair_count = materiallist_data->pair_count;
	
	return((asset_materiallist*)asset_append(Assets, ASSET_MATERIALLIST, &materiallist, sizeof(asset_materiallist), materiallist_data->header.handle));
    }
    return(return_materiallist);
}
internal asset_materiallist_pair* assets_create_materiallist_pair(assets_information* Assets, asset_data_materiallist_pair* materiallist_pair_data)
{
    asset_materiallist_pair* return_materiallist_pair = (asset_materiallist_pair*)asset_check(Assets, materiallist_pair_data->header.handle); // check.
    if(!return_materiallist_pair)
    {
	asset_materiallist_pair materiallist_pair = {};
    
	materiallist_pair.materiallist_handle = materiallist_pair_data->materiallist_handle;
	materiallist_pair.        list_handle = materiallist_pair_data->        trianglelist_handle;
	materiallist_pair.    material_handle = materiallist_pair_data->    material_handle;

	return((asset_materiallist_pair*)asset_append(Assets, ASSET_MATERIALLIST_PAIR, &materiallist_pair, sizeof(asset_materiallist_pair), materiallist_pair_data->header.handle));
    }
    return(return_materiallist_pair);
}
internal asset_trianglemesh*      assets_create_trianglemesh     (assets_information* Assets, asset_data_trianglemesh* mesh_data)
{
    asset_trianglemesh* return_trianglemesh = (asset_trianglemesh*)asset_check(Assets, mesh_data->header.handle); // check.
    if(!return_trianglemesh) 
    {
	io_file file = io_readfile(mesh_data->mesh_path);
	if(file.source)
	{
	    asset_trianglemesh data = {};

	    trianglemesh_header* header = (trianglemesh_header*)file.source;
	    v3* vertices  = (v3*)((u8*)header + header->vertex_offset);
	    v2* uvs       = (v2*)((u8*)header + header->    uv_offset);
	    v3* normals   = (v3*)((u8*)header + header->normal_offset);

	    data.vertex_count = header->vertex_count;
	    data.  list_count = header->list_count;
	    data. orientation = *((transform*)((u8*)header + header->orientation_offset));
	    data.vao          = assets_opengl_compilemesh(header->vertex_count, vertices, uvs, normals);

	    if(!data.vao)
	    {
		io_freefile(file);
		return(0);
	    }

	    asset_trianglemesh* mesh = (asset_trianglemesh*)asset_append(Assets, ASSET_TRIANGLEMESH, &data, sizeof(asset_trianglemesh), mesh_data->header.handle);
	    ASSERT(mesh)

	    // TRIANGLE LISTS

	    // material list.
	    asset_data_materiallist* materiallist_data = assets_data_create_materiallist(Assets, mesh_data->header.handle, header->list_count);

	    //?
	    assets_create_materiallist(Assets, materiallist_data);

	    // temporary.
	    mesh->default_materiallist_handle = materiallist_data->header.handle;

	    u32 list_hash = mesh_data->header.handle+1;

	    trianglelist_header* list_header = (trianglelist_header*)((u8*)header + header->list_offset);
	    for(s32 l = 0; l < header->list_count; l++)
	    {
		if(!asset_check(Assets, list_hash+l))
		{
		    asset_trianglelist trianglelist = {};
		    trianglelist.trianglemesh_handle = mesh_data->header.handle;
		    trianglelist.index       = l;
		    trianglelist.count       = list_header->count;
		    trianglelist.offset      = list_header->offset;

		    (asset_trianglelist*)asset_append(Assets, ASSET_TRIANGLELIST, &trianglelist, sizeof(asset_trianglelist), list_hash+l);
		    
		    if(!l) { mesh->list_handle = list_hash+l; }

		    // material & material list.
		    asset_data_material* material_data = assets_data_create_material(Assets, list_header->name, 0, 0, list_header->colour, 2048);
		    assets_create_material(Assets, material_data);
		    asset_data_materiallist_pair* materiallist_pair_data = assets_data_create_materiallist_pair(Assets, materiallist_data->header.handle, list_hash+l, material_data->header.handle);
		    assets_create_materiallist_pair(Assets, materiallist_pair_data);
		}
		list_header++;
	    }

	    // important, we know that the trianglelist assets that belong to the same object will always to contiguous,
	    // therefore we only need to provide the mesh with the handle to the first list for look-up,
	    // the pointers to the other lists can be found through pointer arithmatic.

	    io_freefile(file);
	    return(mesh);
	}
    }
    return(return_trianglemesh);
    
}
internal asset_entity*            assets_create_entity           (assets_information* Assets, asset_data_entity* entity_data)
{
    asset_entity* return_entity = (asset_entity*)asset_check(Assets, entity_data->header.handle); // check.
    if(!return_entity) 
    {
	asset_entity entity = {};
	entity.trianglemesh_handle          = entity_data->trianglemesh_handle;
	entity.material_list_handle = entity_data->materiallist_handle;
	entity.orientation          = entity_data->orientation;
	return((asset_entity*)asset_append(Assets, ASSET_ENTITY, &entity, sizeof(asset_entity), entity_data->header.handle));
    }
    return(return_entity);
}

// create. (game)

internal asset_game_panel* assets_create_game_panel(assets_information* Assets, asset_data_game_panel* panel_data)
{
    asset_game_panel* return_panel = (asset_game_panel*)asset_check(Assets, panel_data->header.handle); // check.
    if(!return_panel) 
    {
	asset_game_panel panel = {};
	panel.handscroll_handle = panel_data->handscroll_handle;
	panel.    entity_handle = panel_data->entity_handle;
	return((asset_game_panel*)asset_append(Assets, ASSET_GAME_PANEL, &panel, sizeof(asset_game_panel), panel_data->header.handle));
    }
    return(return_panel);
}

internal void assets_savepack_readable(assets_information* Assets)
{
    FILE* file = fopen("../data/savepack_read.pack", "w");
    if(file)
    {
	s32 size = 0;

	asset_header* header = Assets->data_headers;
	while(size < Assets->data_used)
	{
	    header = (asset_header*)((u8*)Assets->data_headers + size);

	    switch(header->sort)
	    {
	    case ASSET_SHADER:
		fprintf(file, "\n[%i]", header->handle);
		fprintf(file, "ASSET SHADER");
		fprintf(file, "(%i)\n", header->struct_size);
		break;
	    case ASSET_TEXTURE:
		fprintf(file, "\n[%i]", header->handle);
		fprintf(file, "ASSET TEXTURE");
		fprintf(file, "(%i)\n", header->struct_size);
		break;
	    case ASSET_MATERIAL:
		fprintf(file, "\n[%i]", header->handle);
		fprintf(file, "ASSET MATERIAL");
		fprintf(file, "(%i)\n", header->struct_size);
		break;
	    case ASSET_TRIANGLEMESH:
		fprintf(file, "\n[%i]", header->handle);
		fprintf(file, "ASSET TRIANGLEMESH");
		fprintf(file, "(%i)\n", header->struct_size);
		break;
	    case ASSET_MATERIALLIST:
	    {
		fprintf(file, "\n[%i]", header->handle);
		fprintf(file, "ASSET MATERIAL LIST");
		fprintf(file, "(%i)\n", header->struct_size);
	    }
	    break;
	    case ASSET_ENTITY:
	    {
		fprintf(file, "\n[%i]", header->handle);
		fprintf(file, "ASSET ENTITY");
		fprintf(file, "(%i)\n", header->struct_size);
	    }
	    break;
	    case ASSET_SOUND:
	    {
		fprintf(file, "\n[%i]", header->handle);
		fprintf(file, "ASSET SOUND");
		fprintf(file, "(%i)\n", header->struct_size);
	    }
	    break;
	    case ASSET_ANIMATION:
	    {
		fprintf(file, "\n[%i]", header->handle);
		fprintf(file, "ASSET ANIMATION");
		fprintf(file, "(%i)\n", header->struct_size);
	    }
	    break;
	    case ASSET_GAME_PANEL:
		fprintf(file, "\n[%i]", header->handle);
		fprintf(file, "ASSET GAME PANEL");
		fprintf(file, "(%i)\n", header->struct_size);
		break;
	    }
	    
	    switch(header->sort)
	    {
	    case ASSET_SHADER:
	    {
		asset_data_shader* shader = (asset_data_shader*)header;
		fprintf(file, "   (vertex shader: %s) (pixel shader: %s)\n", shader->vs_path, shader->ps_path);
	    }
	    break;
	    case ASSET_TEXTURE:
	    {
		asset_data_texture* texture = (asset_data_texture*)header;
		fprintf(file, "   (bitmap: %s)\n", texture->bmp_path);
	    }
	    break;
	    case ASSET_SOUND:
	    {
		asset_data_sound* sound = (asset_data_sound*)header;
		fprintf(file, "   (wave file: %s)\n", sound->wave_path);
	    }
	    break;
	    case ASSET_ANIMATION:
	    {
		asset_data_animation* anim = (asset_data_animation*)header;
		fprintf(file, "   (anim file: %s)\n", anim->anim_path);
	    }
	    break;
	    case ASSET_MATERIAL:
	    {
		asset_data_material* material = (asset_data_material*)header;
		fprintf(file, "   (name: %s)(shader:  [%i]) (texture: [%i])\n   (colour: %f,%f,%f,%f & shininess: %f)\n",
			material->name, material->shader_handle, material->texture_handle,
			material->colour.r, material->colour.g, material->colour.b, material->colour.a, material->shininess);
	    }
	    break;
	    case ASSET_TRIANGLEMESH:
	    {
		asset_data_trianglemesh* trianglemesh = (asset_data_trianglemesh*)header;
		fprintf(file, "   (mesh: %s)\n", trianglemesh->mesh_path);

		asset_trianglemesh* mesh = (asset_trianglemesh*)assets_get(Assets, trianglemesh->header.handle);
		for(u32 l = 0; l < mesh->list_count; l++)
		{
		    asset_trianglelist* list = (asset_trianglelist*)assets_get(Assets, mesh->list_handle+l);

		    fprintf(file, "      [%i]", list->header.handle);
		    fprintf(file, "ASSET TRIANGLELIST");
		    fprintf(file, "(%i)\n", list->header.struct_size);
		    fprintf(file, "         (list index: %i) (mesh: [%i])\n", list->index, list->trianglemesh_handle);
		}
	    }
	    break;
	    case ASSET_MATERIALLIST:
	    {
		asset_data_materiallist* materiallist = (asset_data_materiallist*)header;
		fprintf(file, "   (mesh:  [%i])\n",
			materiallist->trianglemesh_handle);

		s32 used = 0;
		while(used < Assets->data_used)
		{
		    asset_header* pair_header = (asset_header*)((u8*)Assets->data_headers + used);

		    if(pair_header->sort == ASSET_MATERIALLIST_PAIR)
		    {
			asset_data_materiallist_pair* material_list_pair = (asset_data_materiallist_pair*)pair_header;

			if(material_list_pair->materiallist_handle == materiallist->header.handle)
			{
			    fprintf(file, "   [%i]", material_list_pair->header.handle);
			    fprintf(file, "ASSET MATERIAL-TRIANGLELIST PAIR");
			    fprintf(file, "(%i)\n", material_list_pair->header.struct_size);
		
			    fprintf(file, "   (material list: [%i]) (list:  [%i]) (material: [%i])\n",
				    materiallist->header.handle, material_list_pair->trianglelist_handle, material_list_pair->material_handle);
			}
		    }   
		    used += pair_header->struct_size;
		}
	    }
	    break;
	    case ASSET_ENTITY:
	    {
		asset_data_entity* entity = (asset_data_entity*)header;
		fprintf(file, "   (mesh: [%i]) (material list: [%i])\n   (transform: pos(%f,%f,%f) rot(%f,%f,%f) scale(%f,%f,%f))\n",
			entity->trianglemesh_handle, entity->materiallist_handle,
			entity->orientation.position.x, entity->orientation.position.y, entity->orientation.position.z,
			entity->orientation.rotation.x, entity->orientation.rotation.y, entity->orientation.rotation.z,
			entity->orientation.scale.x, entity->orientation.scale.y, entity->orientation.scale.z);
	    }
	    break;
	    case ASSET_GAME_PANEL:
	    {
		asset_data_game_panel* panel = (asset_data_game_panel*)header;
		fprintf(file, "   (entity: [%i]) (handscroll: [%i])\n", panel->entity_handle, panel->handscroll_handle);
	    }
	    break;
	    }
	    size += header->struct_size;
	}
	fclose(file);
    }
}
internal void assets_savepack         (assets_information* Assets, s8* save_path)
{
    assets_savepack_readable(Assets);
    
    io_writefile(save_path, Assets->data_used, Assets->data_headers);
}
internal b32  assets_loadpack         (assets_information* Assets, s8* save_path)
{
    b32 success = false;
    
    io_file file = io_readfile(save_path);
    if(file.source)
    {
	mem_copy(file.source, Assets->data_headers, file.size);

	Assets->data_used = file.size;

	s32 size = 0;
	while(size < Assets->data_used)
	{
	    asset_header* header = (asset_header*)((u8*)Assets->data_headers + size);

	    switch(header->sort)
	    {
	    case ASSET_SHADER:
	    {
		if(header->struct_size == sizeof(asset_data_shader))
		{
		    assets_create_shader(Assets, (asset_data_shader*)header);
		}
	    }
	    break;
	    case ASSET_TEXTURE:
	    {
		if(header->struct_size == sizeof(asset_data_texture))
		{
		    assets_create_texture(Assets, (asset_data_texture*)header);
		}
	    }
	    break;
	    case ASSET_SOUND:
	    {
		if(header->struct_size == sizeof(asset_data_sound))
		{
		    assets_create_sound(Assets, (asset_data_sound*)header);
		}
	    }
	    break;
	    case ASSET_ANIMATION:
	    {
		if(header->struct_size == sizeof(asset_data_animation))
		{
		    assets_create_animation(Assets, (asset_data_animation*)header);
		}
	    }
	    break;
	    case ASSET_MATERIAL:
	    {
		if(header->struct_size == sizeof(asset_data_material))
		{
		    assets_create_material(Assets, (asset_data_material*)header);
		}
	    }
	    break;
	    case ASSET_TRIANGLEMESH:
	    {
		if(header->struct_size == sizeof(asset_data_trianglemesh))
		{
		    assets_create_trianglemesh(Assets, (asset_data_trianglemesh*)header);
		}
	    }
	    break;
	    case ASSET_MATERIALLIST_PAIR:
	    {
		if(header->struct_size == sizeof(asset_data_materiallist_pair))
		{
		    assets_create_materiallist_pair(Assets, (asset_data_materiallist_pair*)header);
		}
	    }
	    case ASSET_MATERIALLIST:
	    {
		if(header->struct_size == sizeof(asset_data_materiallist))
		{
		    assets_create_materiallist(Assets, (asset_data_materiallist*)header);
		}
	    }
	    break;
	    case ASSET_ENTITY:
	    {
		if(header->struct_size == sizeof(asset_data_entity))
		{
		    assets_create_entity(Assets, (asset_data_entity*)header);
		}
	    }
	    break;
	    case ASSET_GAME_PANEL:
	    {
		if(header->struct_size == sizeof(asset_data_game_panel))
		{
		    assets_create_game_panel(Assets, (asset_data_game_panel*)header);
		}
	    }
	    break;
	    }
	    Assets->data_count++;
	    size += header->struct_size;
	}
	success = true;
	
	io_freefile(file);
    }
    
    return(success);
}

internal void assets_initialise(assets_information* Assets)
{
    Assets->size      = kilobytes(512);
    Assets->data_size = kilobytes(512);
    
    Assets->headers      = (asset_header*)stack_push(&Assets->arena, Assets->size);
    Assets->data_headers = (asset_header*)stack_push(&Assets->arena, Assets->data_size);

    assets_loadpack(Assets, "../data/savepack.pack");
}
