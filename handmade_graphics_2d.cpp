#pragma once

//
// z_index 
//
//  1 - above
//  0 - middle (default)
// -1 - below
//

#define ANSI_OFFSET 32
#define ANSI_COUNT  233

// TEXT

#pragma pack(push, 1)
struct glyph_header
{
    s8  character;
    s32 offset;
    
    s32     spacing;
    s32 pre_spacing;
    
    u32  width;
    u32 height;

    r32 u0;
    r32 u1;
    r32 v0;
    r32 v1;
};
struct font_header
{
    s32   size;
    s32  width;
    s32 height;
    
    s32 glyph_count;
    s32 glyph_height;
    s32 glyph_width;

    s32 line_spacing;

    s32 glyph_offset;
    s32  byte_offset;
};
#pragma pack(pop)


// PRIMITIVES
struct rect
{
    r32 x0; // ndc[-1.0, 1.0] or standard[0.0, 16.0], ndc[-1.0, 1.0] or standard[0.0,  9.0]
    r32 y0;
    r32 x1;
    r32 y1;
};
struct rect_u32
{
    s32 x0; // pixel perfect [0, window_width], [0, window_height]
    s32 y0;
    s32 x1;
    s32 y1;
};
struct circle
{
    r32 x;  // ndc[-1.0, 1.0] or standard[0.0, 16.0], ndc[-1.0, 1.0] or standard[0.0,  9.0]
    r32 y;
    r32 r_x; // ndc screen width [0.0, 2.0] or standard width (radius) [0.0, 16.0]   
    r32 r_y; // ndc screen height[0.0, 2.0] or standard height[0.0,  9.0] -> only used in conversion to ndc
};
struct line2d
{
    r32 x0;  // beginning
    r32 y0;
    r32 x1;  // end
    r32 y1;
};
struct triangle
{
    r32 x0;
    r32 y0;

    r32 x1;
    r32 y1;
    
    r32 x2;
    r32 y2;
};

struct render_information_glyph
{
    s32  dy;
    
    s32  width;
    s32  height;
    
    s32      spacing;
    s32  pre_spacing;
    
    rect uv;
};
struct render_information_font
{
    GLuint texture;
    v4     colour;
    
    s32 line_spacing;

    render_information_glyph glyphs[ANSI_COUNT]; 
};

struct render_information_primitive
{
    s32 window_width;
    s32 window_height;
    
    GLuint rect_vao;    
    GLuint rect_vbo;    
    GLuint rect_uv_vbo; 

    GLuint line2d_vao;   
    GLuint line2d_vbo;
    
    r32    line2d_width; 

    GLuint circle_vao; 
    GLuint circle_vbo;

    GLuint triangle_vao;
    GLuint triangle_vbo;

    GLuint  shader;  
    GLuint texture; 
    v4      colour;
    
    r32 z_index;

    // TEXT
    // WINDOWS-1252 (32 - 255) 223 CHARACTERS, 8 NOT PRINTABLE

    render_information_font font;
};

inline internal void graphics_primitive_set_window_width     (render_information_primitive* primitive, s32 width)  { primitive->window_width = width;  }
inline internal void graphics_primitive_set_window_height    (render_information_primitive* primitive, s32 height) { primitive->window_height = height; }
inline internal void graphics_primitive_set_window_dimensions(render_information_primitive* primitive, s32 width, s32 height)
{
    graphics_primitive_set_window_width(primitive, width);
    graphics_primitive_set_window_height(primitive, height);
}

inline internal void graphics_primitive_set_colour    (render_information_primitive* primitive, r32 r, r32 g, r32 b, r32 a) { primitive->colour       = { r, g, b, a }; }
inline internal void graphics_primitive_set_colour    (render_information_primitive* primitive, v4 colour)                  { primitive->colour       = colour;         }
inline internal void graphics_primitive_set_texture   (render_information_primitive* primitive, GLuint texture)             { primitive->texture      = texture;        } 
inline internal void graphics_primitive_set_linewidth (render_information_primitive* primitive, r32 line_width)             { primitive->line2d_width = line_width;     }
inline internal void graphics_primitive_set_zindex    (render_information_primitive* primitive, s32 z_index)
{
    switch(z_index)
    {
    case  1:
	primitive->z_index = -1.0f; // above
	break;
    case  0:
	primitive->z_index = 0.98f; // middle
	break;
    case -1:
	primitive->z_index = 0.96f; // below
	break;
    }
}

inline internal void graphics_primitive_set_font_texture(render_information_font* font, GLuint texture) { font->texture = texture; }
inline internal void graphics_primitive_set_font_colour(render_information_font* font, r32 r, r32 g, r32 b, r32 a) { font->colour = { r, g, b, a }; }
inline internal void graphics_primitive_set_font_colour(render_information_font* font, v4 colour) { font->colour = colour; }
inline internal void graphics_primitive_set_font_linespacing(render_information_font* font, s32 line_spacing) { font->line_spacing = line_spacing; }
inline internal void graphics_primitive_set_font_glyph(render_information_font* font, u8 character,
						       s32 width, s32 height, s32 dy,
						       s32 spacing, s32 pre_spacing,
						       r32 u0, r32 v0, r32 u1, r32 v1)
{
    font->glyphs[character - ANSI_OFFSET].width       = width;
    font->glyphs[character - ANSI_OFFSET].height      = height;
    font->glyphs[character - ANSI_OFFSET].dy          = dy;
    font->glyphs[character - ANSI_OFFSET].    spacing =     spacing; // CONSOLIDATE!
    font->glyphs[character - ANSI_OFFSET].pre_spacing = pre_spacing;
    font->glyphs[character - ANSI_OFFSET].uv = { u0, v0, u1, v1 };
}




#define graphics_set_backgroundcolour(param_r, param_g, param_b)	\
    glClearColor((param_r), (param_g), (param_b), 1.0);			\
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			\

#define graphics_set_parameter_texture(param_name, param_shader, param_textureid, param_texture) \
    glUniform1i(glGetUniformLocation((param_shader), (param_name)), (param_textureid)); \
    glActiveTexture(GL_TEXTURE##param_textureid);			\
    glBindTexture  (GL_TEXTURE_2D, (param_texture));			
#define graphics_set_parameter_v4(param_name, param_shader, param_x, param_y, param_z, param_w) \
    glUniform4f(glGetUniformLocation((param_shader), (param_name)), (param_x), (param_y), (param_z), (param_w)); 
#define graphics_set_parameter_v3(param_name, param_shader, param_x, param_y, param_z) \
    glUniform3f(glGetUniformLocation((param_shader), (param_name)), (param_x), (param_y), (param_z)); 
#define graphics_set_parameter_v2(param_name, param_shader, param_x, param_y) \
    glUniform2f(glGetUniformLocation((param_shader), (param_name)), (param_x), (param_y)); 
#define graphics_set_parameter_r32(param_name, param_shader, param)	\
    glUniform1f(glGetUniformLocation((param_shader), (param_name)), (param)); 
#define graphics_set_parameter_s32(param_name, param_shader, param)	\
    glUniform1i(glGetUniformLocation((param_shader), (param_name)), (param)); 
#define graphics_set_parameter_b32(param_name, param_shader, param)	\
    glUniform1i(glGetUniformLocation((param_shader), (param_name)), (param)); \

#define graphics_rgb_norm(red, green, blue) (red)/(r32)255, (green)/(r32)255, (blue)/(r32)255

// PRIMITIVE
inline internal void conversion_rect_to_data   (rect r, v3* data)
{
    r.x0 = ((r.x0 / 16.0) * 2.0) - 1.0;
    r.x1 = ((r.x1 / 16.0) * 2.0) - 1.0;
    r.y0 = (((9.0 - r.y0) / 9.0) * 2.0) - 1.0;
    r.y1 = (((9.0 - r.y1) / 9.0) * 2.0) - 1.0;

    data[0] = { r.x0, r.y0, 0.0 }; // top    - left
    data[1] = { r.x0, r.y1, 0.0 }; // bottom - left 
    data[2] = { r.x1, r.y0, 0.0 }; // top    - right
    data[3] = { r.x1, r.y1, 0.0 }; // bottom - right
    data[4] = { r.x1, r.y0, 0.0 }; // top    - right
    data[5] = { r.x0, r.y1, 0.0 }; // bottom - left
}
inline internal void conversion_rect_to_data   (rect r, v2* data)
{
    data[0] = { r.x0, r.y0 }; // top    - left
    data[1] = { r.x0, r.y1 }; // bottom - left 
    data[2] = { r.x1, r.y0 }; // top    - right
    data[3] = { r.x1, r.y1 }; // bottom - right
    data[4] = { r.x1, r.y0 }; // top    - right
    data[5] = { r.x0, r.y1 }; // bottom - left
}
inline internal void conversion_rect_to_data   (rect_u32 r_u32, s32 window_width, s32 window_height, v3* data)
{
    rect r = {};
    r.x0 = ((r_u32.x0 / (r32)window_width) * 2.0) - 1.0;
    r.x1 = ((r_u32.x1 / (r32)window_width) * 2.0) - 1.0;
    r.y0 = (((window_height - r_u32.y0) / (r32)window_height) * 2.0) - 1.0;
    r.y1 = (((window_height - r_u32.y1) / (r32)window_height) * 2.0) - 1.0;

    data[0] = { r.x0, r.y0, 0.0 }; // top    - left
    data[1] = { r.x0, r.y1, 0.0 }; // bottom - left 
    data[2] = { r.x1, r.y0, 0.0 }; // top    - right
    data[3] = { r.x1, r.y1, 0.0 }; // bottom - right
    data[4] = { r.x1, r.y0, 0.0 }; // top    - right
    data[5] = { r.x0, r.y1, 0.0 }; // bottom - left
}
inline internal void conversion_line2d_to_data (line2d l, v3* data)
{
    l.x0 = ((l.x0 / 16.0) * 2.0) - 1.0;
    l.x1 = ((l.x1 / 16.0) * 2.0) - 1.0;
    l.y0 = (((9.0 - l.y0) / 9.0) * 2.0) - 1.0;
    l.y1 = (((9.0 - l.y1) / 9.0) * 2.0) - 1.0;
    
    data[0] = { l.x0, l.y0, 0.0 }; // vertex 0
    data[1] = { l.x1, l.y1, 0.0 }; // vertex 1 
}
inline internal void conversion_circle_to_data (circle c, v3* data)
{
    c.x   = ((c.x / 16.0) * 2.0) - 1.0;
    c.y   = (((9.0 - c.y) / 9.0) * 2.0) - 1.0;
    c.r_y = (c.r_x /  9.0) * 2.0;
    c.r_x = (c.r_x / 16.0) * 2.0;
    
    // SUBDIVISION COUNT: 1
    // TOTAL VERTICES = 1 + ((4 * SUBDIVISION COUNT) + 1)

    u32 subdivision_count = 10;
    r32 increment = (TAU/4.0)/subdivision_count;

    data[0] = { c.x, c.y, 0 };
    data[1] = { c.x, c.y + c.r_y, 0 };
    for(u32 vertex_i = 2; vertex_i < ((4 * subdivision_count) + 1); vertex_i++)
    {
	data[vertex_i] =
	{
	    c.x + (c.r_x * cosf( (TAU/4.0) + (increment * (vertex_i - 1)) )),
	    c.y + (c.r_y * sinf( (TAU/4.0) + (increment * (vertex_i - 1)) )),
	    0
	};
    }
    data[(4 * subdivision_count) + 1] = { c.x, c.y + c.r_y, 0 };
}
inline internal void conversion_triangle_to_data(triangle t, v3* data)
{
    t.x0 = ((t.x0 / 16.0) * 2.0) - 1.0;
    t.x1 = ((t.x1 / 16.0) * 2.0) - 1.0;
    t.x2 = ((t.x2 / 16.0) * 2.0) - 1.0;
    
    t.y0 = (((9.0 - t.y0) / 9.0) * 2.0) - 1.0;
    t.y1 = (((9.0 - t.y1) / 9.0) * 2.0) - 1.0;
    t.y2 = (((9.0 - t.y2) / 9.0) * 2.0) - 1.0;
    
    data[0] = { t.x0, t.y0, 0.0 };
    data[1] = { t.x1, t.y1, 0.0 };
    data[2] = { t.x2, t.y2, 0.0 };
}

internal void graphics_primitive_opengl_compileprimitives(v3* rect_vertexdata,
							  v2* rect_uvdata,
							  GLuint* rect_vao,
							  GLuint* rect_vbo,
							  GLuint* rect_uv_vbo,
							  v3* line2d_vertexdata,
							  GLuint* line2d_vao,
							  GLuint* line2d_vbo,
							  v3* circle_vertexdata,
							  GLuint* circle_vao,
							  GLuint* circle_vbo,
                                                          v3* triangle_vertexdata,
                                                          GLuint* triangle_vao,
                                                          GLuint* triangle_vbo)
{
    // RECT
    glGenVertexArrays(1, rect_vao);
    glBindVertexArray(*rect_vao);

    glGenBuffers(1, rect_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *rect_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v3) * 6, rect_vertexdata, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glGenBuffers(1, rect_uv_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *rect_uv_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v2) * 6, rect_uvdata, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    // LINE
    glGenVertexArrays(1, line2d_vao);
    glBindVertexArray(*line2d_vao);

    glGenBuffers(1, line2d_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *line2d_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v3) * 2, line2d_vertexdata, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // CIRCLE
    glGenVertexArrays(1, circle_vao);
    glBindVertexArray(*circle_vao);

    glGenBuffers(1, circle_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *circle_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v3) * 42, circle_vertexdata, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // TRIANGLE
    glGenVertexArrays(1, triangle_vao);
    glBindVertexArray(*triangle_vao);

    glGenBuffers(1, triangle_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *triangle_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v3) * 3, triangle_vertexdata, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

internal void graphics_primitives_initialise(render_information_primitive* primitive, s32 window_width, s32 window_height)
{
    graphics_primitive_set_window_dimensions(primitive, window_width, window_height);
     
    // PRIMITIVE DATA
    
    v3 rect_vertexdata  [6]   = {}; // @ rect 
    v2 rect_uvdata      [6]   = {}; // @ rect
    v3 line2d_vertexdata[2]   = {}; // @ line2d
    v3 circle_vertexdata[42]  = {}; // @ circle
    v3 triangle_vertexdata[3] = {}; // @ triangle
    
    rect     _rect     = { 4.0, 2.25, 12.0, 6.75 }; // @ rect
    rect     _rect_uv  = { 0.0, 1.0 ,  1.0, 0.0  }; // @ rect
    line2d   _line2d   = { 4.0, 4.5 , 12.0, 4.5  }; // @ line2d
    circle   _circle   = { 8.0, 4.5 ,  2.0, 2.0  }; // @ circle
    triangle _triangle = { 8.0, 3.0, 4.0, 6.0, 12.0, 6.0 }; // @ triangle
    
    conversion_rect_to_data  (_rect,     rect_vertexdata); // @ rect
    conversion_rect_to_data  (_rect_uv,      rect_uvdata); // @ rect
    conversion_line2d_to_data(_line2d, line2d_vertexdata); // @ line2d
    conversion_circle_to_data(_circle, circle_vertexdata); // @ circle
    conversion_triangle_to_data(_triangle, triangle_vertexdata); // @ triangle
    
    graphics_primitive_opengl_compileprimitives(rect_vertexdata,          // @ rect
						rect_uvdata,              // @ rect
						&primitive->rect_vao,     // @ rect
						&primitive->rect_vbo,     // @ rect
						&primitive->rect_uv_vbo,  // @ rect
						line2d_vertexdata,        // @ line2d
						&primitive->line2d_vao,   // @ line2d
						&primitive->line2d_vbo,   // @ line2d
						circle_vertexdata,        // @ circle
						&primitive->circle_vao,   // @ circle
						&primitive->circle_vbo,   // @ circle
	                                        triangle_vertexdata,      // @ triangle
	                                        &primitive->triangle_vao,  // @ triangle
	                                        &primitive->triangle_vbo); // @ triangle
    
    ASSERT(primitive->    rect_vao) // @ rect
    ASSERT(primitive->  line2d_vao) // @ line2d
    ASSERT(primitive->  circle_vao) // @ circle
    ASSERT(primitive->triangle_vao) // @ triangle

    glEnable(GL_DEPTH_TEST);                           // @ depth
    glEnable(GL_BLEND);                                // @ transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // @ transparency

    // shaders
    const s8 vert_source[] =
    "#version 330 core\n"
    "layout (location = 0) in vec3  in_vertex;\n"
    "layout (location = 1) in vec2  in_uv;\n"
    "uniform float z_index;\n"
    "out vec2 uv;\n"
    "void main()\n"
    "{\n"
    "	uv          = in_uv;\n"
    "	gl_Position = vec4(in_vertex.x, in_vertex.y, z_index, 1.0);\n"
    "}\n";
    
    const s8 frag_source[] =
    "#version 330 core\n"
    "in vec2 uv;\n"
    "uniform vec4 colour;\n"
    "uniform sampler2D colour_tex;\n"
    "uniform bool                       use_colour_tex;\n"
    "void main()\n"
    "{\n"
    "gl_FragColor = colour;\n"
    "if(use_colour_tex)\n"
    "{\n"
    "gl_FragColor *= texture(colour_tex, uv);\n"
    "}\n"
    "}\n";

    primitive->shader = opengl_shader_compile_program(
	opengl_shader_compile_vertex  ((s8*)vert_source, sizeof(vert_source)),
	opengl_shader_compile_fragment((s8*)frag_source, sizeof(frag_source)));
}

internal void graphics_primitive_update_data(render_information_primitive* primitive)
{
    glUseProgram(primitive->shader);
    graphics_set_parameter_v4("colour", primitive->shader, primitive->colour.r, primitive->colour.g, primitive->colour.b, primitive->colour.a);
    graphics_set_parameter_b32("use_colour_tex", primitive->shader, primitive->texture);
    graphics_set_parameter_texture("colour_tex", primitive->shader, 0, primitive->texture);
    graphics_set_parameter_r32("z_index", primitive->shader, primitive->z_index);
}

// SHAPES

internal void graphics_primitive_render_rect  (render_information_primitive* primitive, rect r, rect* uv)
{
    graphics_primitive_update_data(primitive);

    // update.
    v3 vertex_data[6] = {};
    conversion_rect_to_data(r, vertex_data);
    
    glBindBuffer(GL_ARRAY_BUFFER, primitive->rect_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v3) * 6, vertex_data);

    if(uv)
    {
	v2 uv_data[6] = {};
	conversion_rect_to_data(*uv, uv_data);
	
	glBindBuffer(GL_ARRAY_BUFFER, primitive->rect_uv_vbo);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v2) * 6, uv_data);
    }

    // draw.
    glBindVertexArray(primitive->rect_vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}
internal void graphics_primitive_render_rect  (render_information_primitive* primitive, rect_u32 r, rect* uv)
{
    graphics_primitive_update_data(primitive);

    // update.
    v3 vertex_data[6] = {};
    conversion_rect_to_data(r, primitive->window_width, primitive->window_height, vertex_data);
    
    glBindBuffer(GL_ARRAY_BUFFER, primitive->rect_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v3) * 6, vertex_data);

    if(uv)
    {
	v2 uv_data[6] = {};
	conversion_rect_to_data(*uv, uv_data);
	
	glBindBuffer(GL_ARRAY_BUFFER, primitive->rect_uv_vbo);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v2) * 6, uv_data);
    }

    // draw.
    glBindVertexArray(primitive->rect_vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}
internal void graphics_primitive_render_line  (render_information_primitive* primitive, line2d l)
{
    graphics_primitive_update_data(primitive);

    // update.
    v3 vertex_data[2] = {};
    conversion_line2d_to_data(l, vertex_data);
     
    glBindBuffer(GL_ARRAY_BUFFER, primitive->line2d_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v3) * 2, vertex_data);

    // draw.
    glLineWidth(primitive->line2d_width);
    glBindVertexArray(primitive->line2d_vao);
    glDrawArrays(GL_LINES, 0, 2);
}
internal void graphics_primitive_render_circle(render_information_primitive* primitive, circle c)
{
    graphics_primitive_update_data(primitive);

    // update.
    v3 vertex_data[42] = {};
    conversion_circle_to_data(c, vertex_data);
    
    glBindBuffer(GL_ARRAY_BUFFER, primitive->circle_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v3) * 42, vertex_data);

    // draw.
    glBindVertexArray(primitive->circle_vao);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 42);
}
internal void graphics_primitive_render_triangle(render_information_primitive* primitive, triangle t)
{
    graphics_primitive_update_data(primitive);

    // update.
    v3 vertex_data[3] = {};
    conversion_triangle_to_data(t, vertex_data);

    glBindBuffer(GL_ARRAY_BUFFER, primitive->triangle_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v3) * 3, vertex_data);

    // draw.
    glBindVertexArray(primitive->triangle_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

// TEXT

internal void graphics_primitive_render_glyph (render_information_primitive* primitive, u8 character, s32 x, s32 y)
{
    graphics_primitive_set_colour (primitive, primitive->font.colour);
    graphics_primitive_set_texture(primitive, primitive->font.texture);

    rect_u32 r = {
	x,
	y,
	primitive->font.glyphs[character - ANSI_OFFSET]. width + x,
	primitive->font.glyphs[character - ANSI_OFFSET].height + y,
    }; 
    
    graphics_primitive_render_rect(primitive, r, &primitive->font.glyphs[character - ANSI_OFFSET].uv);
    graphics_primitive_set_texture(primitive, 0);
}
internal void graphics_primitive_render_text(render_information_primitive* primitive, s8* text, s32 text_length, v2 position)
{
    // @ [0, pixel width], [0, pixel height]
    
    s32 px = (position.x/16.0) * primitive->window_width;
    s32 py = (position.y/9.0)  * primitive->window_height;
    
    s32 dx = px;
    s32 dy = py;
    
    for(s32 c = 0; c < text_length; c++)
    {
	if     (text[c] == '\0') { return; }
	else if(text[c] == '\n') {
	    dx  = px; 
	    dy += primitive->font.line_spacing; 
	}
	else
	{
	    render_information_glyph* glyph = &primitive->font.glyphs[text[c] - ANSI_OFFSET];
	    
	    graphics_primitive_render_glyph(primitive, text[c],
					    dx + glyph->pre_spacing,
					    dy + glyph->dy);

	    dx += glyph->width + glyph->spacing + glyph->pre_spacing;
	}
    }
}

internal void graphics_primitive_metrics_text(render_information_primitive* primitive, s8* text, s32 text_length, r32* max_width, r32* max_height)
{
    s32 px = 0;
    s32 py = 0;
    
    s32 dx = 0;
    s32 dy = 0;
    
    for(s32 c = 0; c < text_length; c++)
    {
	if     (text[c] == '\0') { break; }
	else if(text[c] == '\n') {
	    dx  = 0; 
	    dy += primitive->font.line_spacing;

	    py += primitive->font.line_spacing; 
	}
	else
	{
	    render_information_glyph* glyph = &primitive->font.glyphs[text[c] - ANSI_OFFSET];
	    
	    dx += glyph->width + glyph->spacing + glyph->pre_spacing;
	    
	    px = (dx > px) ? dx : px;
	    py = ((dy + glyph->height) > py) ? (dy + glyph->height) : py; 
	}
    }

    // @ [0, 16.0], [0, 9.0]
    
    *max_width  = (px/(r32)primitive->window_width) * 16.0;
    *max_height = (py/(r32)primitive->window_height) * 9.0;
}
