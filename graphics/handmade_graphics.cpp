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

struct render_information
{
    render_information_primitive primitives;
    render_information_lists     lists;
};
