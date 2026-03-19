
/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

Notice: (C) Copyright 2024 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/
#pragma once

struct lists_camera
{
    r32   phi;   // @ angle between y and z (look up / down) 0.0 - PI
    r32 theta;   // @ angle between z and x (look sideways)  0.0 - TAU
    v3 position;
    
    v3 focus;
    r32 zoom;
    v3 up;
    
    m4 m;

    r32 speed;
};
struct render_information_lists
{
    //    GLuint   basic_shader;
    GLuint    flat_shader;
    //GLuint  normal_shader; // internal.
    //GLuint     map_shader;
    
    GLuint plane_vao;
    GLuint plane_vbo;
    GLuint plane_vbo_uv;
    GLuint plane_vbo_normal;

    GLuint line3d_vao;
    GLuint line3d_vbo;

    // @ properties.
    GLuint      vao;
    GLuint   shader;  
    GLuint texture0;
    GLuint texture1;
    v4       colour;
    r32   shininess;
    r32 line3d_width;
    m4 model_space;

    // @ camera.
    GLuint camera_ubo;   
    m4     camera_space;
    m4 projection_space;
};

inline internal void graphics_list_set_vao        (render_information_lists* lists, GLuint vao)                 { lists->vao          = vao;            }
inline internal void graphics_list_set_modelspace (render_information_lists* lists, m4 model_space)             { lists->model_space  = model_space;    }
inline internal void graphics_list_set_shader     (render_information_lists* lists, GLuint shader)              { lists->shader       = shader;         }
inline internal void graphics_list_set_texture0   (render_information_lists* lists, GLuint texture0)            { lists->texture0     = texture0;       }
inline internal void graphics_list_set_texture1   (render_information_lists* lists, GLuint texture1)            { lists->texture1     = texture1;       }
inline internal void graphics_list_set_colour     (render_information_lists* lists, r32 r, r32 g, r32 b, r32 a) { lists->colour       = { r, g, b, a }; }
inline internal void graphics_list_set_shininess  (render_information_lists* lists, r32 shininess)              { lists->shininess    = shininess;      }
inline internal void graphics_list_set_linewidth  (render_information_lists* lists, r32 line_width)             { lists->line3d_width = line_width;     }

inline internal void graphics_list_set_cameraspace     (render_information_lists* lists, m4 camera_space)      { lists->camera_space     = camera_space; }
inline internal void graphics_list_set_projectionsspace(render_information_lists* lists, m4 projection_space)  { lists->projection_space = projection_space; }

#define graphics_update_framebuffer(frame)	\
    glBindFramebuffer(GL_FRAMEBUFFER, frame);
#define graphics_update_framebuffer_colour(red, green, blue)	\
    glClearColor((red), (green), (blue), 1.0);			\
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

struct plane
{
    // world spcace [-inf, inf]
    
    r32 x0; // left - forward
    r32 y0; 
    r32 z0;

    r32 x1; // right - forward
    r32 y1; 
    r32 z1;

    r32 x2; // left - backward 
    r32 y2; 
    r32 z2;

    r32 x3; // right - backward
    r32 y3; 
    r32 z3;
};
struct line3d
{
    // world space [-inf, inf]
    r32 x0; // beginning
    r32 y0;
    r32 z0;
    r32 x1; // end
    r32 y1;
    r32 z1;
};

inline internal void conversion_plane_to_data  (plane p, v3* vertex_data, v3* normal_data)
{
    vertex_data[0] = { p.x0, p.y0, p.z0 }; // left - forward
    vertex_data[1] = { p.x2, p.y2, p.z2 }; // left - backward
    vertex_data[2] = { p.x1, p.y1, p.z1 }; // right - forward
    
    vertex_data[3] = { p.x3, p.y3, p.z3 }; // right - backward
    vertex_data[4] = { p.x1, p.y1, p.z1 }; // right - forward
    vertex_data[5] = { p.x2, p.y2, p.z2 }; //  left - backward

    // calculate normals.
    v3 normal_0 = -calc_cross((vertex_data[1] - vertex_data[0]), (vertex_data[2] - vertex_data[0]));
    v3 normal_1 = -calc_cross((vertex_data[4] - vertex_data[3]), (vertex_data[5] - vertex_data[3]));
    
    normal_data[0] = normal_0;
    normal_data[1] = normal_0;
    normal_data[2] = normal_0;

    normal_data[3] = normal_1;
    normal_data[4] = normal_1;
    normal_data[5] = normal_1;
}
inline internal void conversion_line3d_to_data (line3d l, v3* data)
{
    data[0] = { l.x0, l.y0, l.z0 }; // vertex 0
    data[1] = { l.x1, l.y1, l.z1 }; // vertex 1 
}

internal void graphics_lists_opengl_compileplane(v3* vertex_data, v2* uv_data, v3* normal_data, GLuint* vao, GLuint* vbo, GLuint* uv_vbo, GLuint* normal_vbo)
{
    // PLANE
    glGenVertexArrays(1, vao);
    glBindVertexArray(*vao);

    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v3) * 6, vertex_data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glGenBuffers(1, uv_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *uv_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v2) * 6, uv_data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glGenBuffers(1, normal_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *normal_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v3) * 6, normal_data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
}
internal void graphics_lists_opengl_compileline (v3* vertex_data, GLuint* vao, GLuint* vbo)
{
    // LINE
    glGenVertexArrays(1, vao);
    glBindVertexArray(*vao);

    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v3) * 2, vertex_data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}
internal void graphics_lists_opengl_compilecamera(GLuint* camera_ubo)
{
    glGenBuffers(1, camera_ubo);
    glBindBuffer(GL_ARRAY_BUFFER, *camera_ubo);
    glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(m4), 0, GL_DYNAMIC_DRAW);
    glBindBufferRange(GL_UNIFORM_BUFFER, 0, *camera_ubo, 0, 2 * sizeof(m4));
}

internal void graphics_3d_initialise(render_information_lists* lists, assets_information* assets)
{
    // LIST DATA
    
    v3 plane_vertexdata [6] = {}; // @ plane
    v2 plane_uvdata     [6] = {}; // @ plane
    v3 plane_normaldata [6] = {}; // @ plane
    v3 line3d_vertexdata[2] = {}; // @ line3d
    
    plane  _plane     = { -1.0, -1.0, 1.0, 1.0, -1.0,  1.0, -1.0, -1.0, -1.0, 1.0, -1.0, -1.0 }; // @ plane
    rect   _plane_uv  = {  0.0,  1.0, 1.0, 0.0 };                                                // @ plane
    line3d _line3d    = { -1.0, -1.0, -1.0, 1.0, 1.0, 1.0 };                                     // @ line3d

    conversion_plane_to_data (_plane, plane_vertexdata, plane_normaldata); // @ plane
    conversion_rect_to_data  (_plane_uv, plane_uvdata);                    // @ plane
    conversion_line3d_to_data(_line3d, line3d_vertexdata);                 // @ plane

    graphics_lists_opengl_compileplane(plane_vertexdata, plane_uvdata, plane_normaldata, // @ plane
				       &lists->plane_vao,                        // @ plane
				       &lists->plane_vbo,                        // @ plane
				       &lists->plane_vbo_uv,                     // @ plane
	                               &lists->plane_vbo_normal);                // @ plane
    graphics_lists_opengl_compileline(line3d_vertexdata, &lists->line3d_vao, &lists->line3d_vbo); // @ line3d
	
    ASSERT(lists->plane_vao)  // @ plane
    ASSERT(lists->line3d_vao) // @ line3d

    glEnable(GL_CULL_FACE); // @ culling
    glCullFace(GL_BACK);    // @ culling
    
    glEnable(GL_DEPTH_TEST);                           // @ depth                            
    glEnable(GL_BLEND);                                // @ transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // @ transparency
	
    // MATRICES (PROJECTION)
    graphics_lists_opengl_compilecamera(&lists->camera_ubo);

    lists->projection_space = calc_perspective(0.1f, 30.0f, 84.0f, 16.0f/9.0f);
    //lists->camera_space     = calc_camera();
    
    // // // // ASSETS // // // //
    assets->basic_shader      = assets_create_shader(assets, assets_data_create_shader(assets, "../data/basic.vert", "../data/basic.frag"));
    assets->basic_shader_flat = assets_create_shader(assets, assets_data_create_shader(assets, "../data/flat.vert" ,  "../data/flat.frag"));
    asset_shader* normal_shader     = assets_create_shader(assets, assets_data_create_shader(assets, "../data/basic.vert","../data/normal.frag"));
    asset_shader* map_shader        = assets_create_shader(assets, assets_data_create_shader(assets, "../data/basic.vert","../data/map.frag"));

    
    ASSERT(     assets->basic_shader)
    ASSERT(      assets->basic_shader_flat)
    ASSERT(    normal_shader)
    ASSERT(       map_shader)
    
    //lists-> basic_shader = basic_shader ->obj;
    lists->  flat_shader = assets->basic_shader_flat->obj;
    //lists->normal_shader = normal_shader->obj;
    //lists->   map_shader = map_shader   ->obj;
    
    // BASIC TEXTURE
    assets->basic_texture = assets_create_texture(assets, assets_data_create_texture(assets, "../data/test (debug).bmp"));
    ASSERT(assets->basic_texture)

    assets->basic_material = assets_create_material(assets, assets_data_create_material(assets, "basic", 0, 0, vec4(0.7f, 0.7f, 0.7f,1.0f), 64));
    ASSERT(assets->basic_material)

    // BASIC MESH
    assets->basic_mesh = assets_create_trianglemesh(assets, assets_data_create_trianglemesh(assets, "../data/cube.km"));
    ASSERT(assets->basic_mesh)
    assets->basic_mesh->orientation.scale    = { 1.0, 1.0, 1.0 };
    assets->basic_mesh->orientation.position = { 0.0, 0.0, 0.0 };
    assets->basic_mesh->orientation.rotation = { 0.0, 0.0, 0.0 }; 
    // // // // //    
}

internal void graphics_list_update_data(render_information_lists* list)
{
    glUseProgram(list->shader);

    graphics_set_parameter_v4("colour", list->shader, list->colour.r, list->colour.g, list->colour.b, list->colour.a);
    graphics_set_parameter_r32("shininess", list->shader, list->shininess);
    graphics_set_parameter_b32("use_colour_tex", list->shader, list->texture0);
    graphics_set_parameter_texture("colour_tex", list->shader, 0, list->texture0);
    graphics_set_parameter_texture("normal_tex", list->shader, 1, list->texture1);
    
    GLint sl_modelspace    = glGetUniformLocation(list->shader, "model_space");
    glUniformMatrix4fv(sl_modelspace, 1, GL_FALSE, &list->model_space[0]);

    glLineWidth(list->line3d_width);
}
internal void graphics_list_update_camera(render_information_lists* lists)
{
    glBindBuffer(GL_ARRAY_BUFFER, lists->camera_ubo);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(m4),          &lists->    camera_space);
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(m4), sizeof(m4), &lists->projection_space);
}

internal m4 graphics_calc_firstperson_camera(lists_camera* camera, action_information* actions)
{
    r32 mouse_x = 8.0 - actions->mouse_position.x;
    r32 mouse_y = 4.5 - actions->mouse_position.y;

    actions->actions[ACTION_LOOK_RIGHTWARD].magnitude += (mouse_x > 0) ? calc_lerp(mouse_x, 8.0f, 0.0f): -calc_lerp(calc_abs(mouse_x), 8.0, 0.0);
    actions->actions[ACTION_LOOK_UPWARD].magnitude    -= (mouse_y > 0) ? calc_lerp(mouse_y, 4.5f, 0.0f): -calc_lerp(calc_abs(mouse_y), 4.5, 0.0);
    
    camera->theta = calc_wrap (camera->theta + actions->actions[ACTION_LOOK_RIGHTWARD].magnitude, TAU, 0.0f);
    camera->phi   = calc_clamp(camera->phi   + actions->actions[ACTION_LOOK_UPWARD].magnitude, PI - 0.05f, 0.05f);

    if(actions->actions[ACTION_MOVE_FORWARD].down)
    {
	camera->position.x += (camera->m[ 8] * actions->actions[ACTION_MOVE_FORWARD].magnitude) * 0.05f;
	camera->position.z += (camera->m[10] * actions->actions[ACTION_MOVE_FORWARD].magnitude) * 0.05f;
    }
    if(actions->actions[ACTION_MOVE_RIGHTWARD].down)
    {
	camera->position.x += (camera->m[0] * actions->actions[ACTION_MOVE_RIGHTWARD].magnitude) * 0.05f;
	camera->position.z += (camera->m[2] * actions->actions[ACTION_MOVE_RIGHTWARD].magnitude) * 0.05f;
    }

    // build camera space 
    
    camera->m[ 8] = -sinf(camera->phi) * sinf(camera->theta);
    camera->m[ 9] =  cosf(camera->phi);
    camera->m[10] =  sinf(camera->phi) * cosf(camera->theta);

    v3 vec = { 0.0, 1.0, 0.0 };
    
    v3 camera_right =  calc_normalise(calc_cross(vec,          vec3(camera->m[8], camera->m[9], camera->m[10])));
    v3 camera_up    = -calc_normalise(calc_cross(camera_right, vec3(camera->m[8], camera->m[9], camera->m[10])));
    camera_right    =  calc_normalise(calc_cross(camera_up,    vec3(camera->m[8], camera->m[9], camera->m[10])));

    camera->m[0] = camera_right.x;
    camera->m[1] = camera_right.y;
    camera->m[2] = camera_right.z;

    camera->m[4] = camera_up.x;
    camera->m[5] = camera_up.y;
    camera->m[6] = camera_up.z;

    camera->m[12] = camera->position.x;
    camera->m[13] = camera->position.y;
    camera->m[14] = camera->position.z;

    return(camera->m);
}
internal m4 graphics_calc_freeroam_camera(lists_camera* camera, action_information* actions)
{
    // rotate around focus. (parallel)
    camera->position.x = camera->focus.x + (camera->zoom * cosf(camera->theta));
    camera->position.z = camera->focus.z + (camera->zoom * sinf(camera->theta));

    if(actions->actions[ACTION_SHIFT].down)
    {
	camera->zoom = calc_max(camera->zoom - actions->scroll, 1.0);
    }
    
    if(actions->actions[ACTION_SHIFT].down && actions->actions[ACTION_LMOUSE].down)
    {
	v3 camera_right = { camera->m[0], camera->m[4], camera->m[8] };
	v3 camera_up    = { camera->m[1], camera->m[5], camera->m[9] };

	v3 camera_delta_x = camera_right * (actions->mouse_offset.x * 5);
	v3 camera_delta_y = camera_up    * (actions->mouse_offset.y * 5);

	// pan.
	camera->position = camera->position + camera_delta_x - camera_delta_y;
	camera->focus    = camera->focus    + camera_delta_x - camera_delta_y;
    }
    
    if(!actions->actions[ACTION_SHIFT].down && actions->actions[ACTION_LMOUSE].down)
    {
	camera->theta = calc_wrap(camera->theta + (actions->mouse_offset.x), TAU, 0);
    }

    // build camera space

    camera->m = calc_camera(camera->position, camera->up, camera->focus);

    return(camera->m);
}

internal void graphics_list_render_plane(render_information_lists* list, plane p, rect* uv)
{
    //m4 m = {};
    //graphics_list_set_modelspace(list, m);
    graphics_list_set_vao       (list, list->plane_vao);
    //graphics_list_set_shader    (list, list->basic_shader);
    
    graphics_list_update_data(list);

    // update.
    v3 vertex_data[6] = {};
    v3 normal_data[6] = {};
    
    // conversion plane to data (vertex & re-calculate normals)
    conversion_plane_to_data(p, vertex_data, normal_data);

    glBindBuffer(GL_ARRAY_BUFFER, list->plane_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v3) * 6, vertex_data);

    glBindBuffer(GL_ARRAY_BUFFER, list->plane_vbo_normal);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v3) * 6, normal_data);

    if(uv)
    {
	v2 uv_data[6] = {};
	conversion_rect_to_data(*uv, uv_data);
	
	glBindBuffer(GL_ARRAY_BUFFER, list->plane_vbo_uv);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v2) * 6, uv_data);
    }

    // draw
    glBindVertexArray(list->plane_vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}
internal void graphics_list_render_line (render_information_lists* list, line3d l)
{
    m4 m = {};
    graphics_list_set_modelspace(list, m);
    graphics_list_set_vao       (list, list->line3d_vao);
    graphics_list_set_shader    (list, list->flat_shader);
    
    graphics_list_update_data(list);

    // update.
    v3 vertex_data[2] = {};
    conversion_line3d_to_data(l, vertex_data);
    glBindBuffer(GL_ARRAY_BUFFER, list->line3d_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v3) * 2, vertex_data);

    // draw
    glLineWidth(list->line3d_width);
    glBindVertexArray(list->line3d_vao);
    glDrawArrays(GL_LINES, 0, 2);
}
internal void graphics_list_render_meshlist(render_information_lists* list,
					    u32 vertex_count,
					    u32 vertex_offset)
{
    graphics_list_update_data(list);
    
    // draw.
    glBindVertexArray(list->vao);
    glDrawArrays(GL_TRIANGLES, vertex_offset, vertex_count);
}
internal void graphics_list_render_meshlist_line(render_information_lists* list,
                                                 u32 vertex_count,
						 u32 vertex_offset)
{
    graphics_list_update_data(list);
    
    // draw.
    glBindVertexArray(list->vao);
    glDrawArrays(GL_LINE_STRIP, vertex_offset, vertex_count);
}


// GENERAL

internal void graphics_render_mesh_wireframe(render_information_primitive* primitive,
					     render_information_lists* lists,
					     assets_information* assets,
					     asset_trianglemesh mesh,
					     m4 model_space,
                                             v4 colour)
{
    graphics_list_set_modelspace(lists, model_space);
    graphics_list_set_vao       (lists, mesh.vao);

    graphics_list_set_shader   (lists,assets->basic_shader_flat->obj);
    graphics_list_set_texture0 (lists, 0);
    graphics_list_set_colour   (lists, colour.r, colour.g, colour.b, colour.a);
    graphics_list_set_linewidth(lists, 0.5);
    
    for(u32 l = 0; l < mesh.list_count; l++)
    {
	asset_trianglelist* list = (asset_trianglelist*)assets_get(assets, mesh.list_handle+l);
	graphics_list_render_meshlist_line(lists, list->count, list->offset);
    }
    
}
internal void graphics_render_mesh(render_information_primitive* primitive,
				   render_information_lists* lists,
				   assets_information* assets,
				   asset_trianglemesh mesh,
				   m4 model_space,
                                   asset_materiallist* materials)
{
    // m4 model_space =
    // calc_translate(mesh.orientation.position)   *
    // calc_scale    (mesh.orientation.scale)      *
    // calc_rotate_z (mesh.orientation.rotation.z) *
    // calc_rotate_y (mesh.orientation.rotation.y) *
    // calc_rotate_x (mesh.orientation.rotation.x);
    
    graphics_list_set_modelspace(lists, model_space);
    graphics_list_set_vao       (lists, mesh.vao);

    if(!materials)
    {
	materials = (asset_materiallist*)assets_get(assets, mesh.default_materiallist_handle);
    }

    
    for(u32 l = 0; l < mesh.list_count; l++)
    {
	asset_trianglelist* list = (asset_trianglelist*)assets_get(assets, mesh.list_handle+l);

	//asset_material* material = assets->basic_material;

	asset_materiallist_pair* pair = assets_get_materiallist_pair(assets, materials->header.handle, list->header.handle);
	
	asset_material* material = (asset_material*)assets_get(assets, pair->material_handle);


	{ // material properties
	    asset_shader*  shader  = (asset_shader*) assets_get(assets, material-> shader_handle);
	    asset_texture* texture = (asset_texture*)assets_get(assets, material->texture_handle);
	    
	    if(shader) graphics_list_set_shader(lists, shader->obj);
	    else       graphics_list_set_shader(lists, assets->basic_shader->obj); // @render, default.
	    
	    if(texture) graphics_list_set_texture0(lists, texture->obj);
	    else        graphics_list_set_texture0(lists, 0);

	    graphics_list_set_colour   (lists, material->colour.r, material->colour.g, material->colour.b, material->colour.a);
	    graphics_list_set_shininess(lists, material->shininess);
	}

	graphics_list_render_meshlist(lists, list->count, list->offset);
    }
}
internal void graphics_render_mesh(render_information_primitive* primitive,
				   render_information_lists* lists,
				   assets_information* assets,
				   asset_trianglemesh mesh,
                                   asset_materiallist* materials)
{
    m4 model_space =
    calc_translate(mesh.orientation.position)   *
    calc_scale    (mesh.orientation.scale)      *
    calc_rotate_z (mesh.orientation.rotation.z) *
    calc_rotate_y (mesh.orientation.rotation.y) *
    calc_rotate_x (mesh.orientation.rotation.x);

    graphics_render_mesh(primitive, lists, assets, mesh, model_space, materials);
}


internal void graphics_render_entity_wireframe(render_information_primitive* primitive,
					       render_information_lists* lists,
					       assets_information* Assets,
					       asset_entity entity, v4 colour)
{
    asset_trianglemesh* mesh = (asset_trianglemesh*)assets_get(Assets, entity.trianglemesh_handle);
    if(mesh)
    {
	m4 model_space =
	calc_translate(entity.orientation.position)   *
	calc_scale    (entity.orientation.scale)      *
	calc_rotate_z (entity.orientation.rotation.z) *
	calc_rotate_y (entity.orientation.rotation.y) *
	calc_rotate_x (entity.orientation.rotation.x);
    
	graphics_render_mesh_wireframe(primitive, lists, Assets, *mesh, model_space, colour);
    }
}
internal void graphics_render_entity(render_information_primitive* primitive,
				     render_information_lists* lists,
				     assets_information* Assets,
				     asset_entity entity)
{
    asset_trianglemesh* mesh = (asset_trianglemesh*)assets_get(Assets, entity.trianglemesh_handle);

    if(mesh)
    {
	asset_materiallist* materials = (asset_materiallist*)assets_get(Assets, entity.material_list_handle);

	if(!materials)
	{
	    materials = (asset_materiallist*)assets_get(Assets, mesh->default_materiallist_handle);
	}

	m4 model_space =
	calc_translate(entity.orientation.position)   *
	calc_scale    (entity.orientation.scale)      *
	calc_rotate_z (entity.orientation.rotation.z) *
	calc_rotate_y (entity.orientation.rotation.y) *
	calc_rotate_x (entity.orientation.rotation.x);
    
	graphics_render_mesh(primitive, lists, Assets, *mesh, model_space, materials);
    }
}


