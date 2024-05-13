#ifndef H_CUBOID_SHADER
#define H_CUBOID_SHADER

typedef struct {
  unsigned int shader_id;
  char *source_code;
} cuboid_vertex_shader_t;

typedef struct {
  unsigned int shader_id;
  char *source_code;
} cuboid_fragment_shader_t;



cuboid_vertex_shader_t *cuboid_vertex_shader_load(const char *path);
void cuboid_vertex_shader_free(cuboid_vertex_shader_t *shader);

cuboid_fragment_shader_t *cuboid_fragment_shader_load(const char *path);
void cuboid_fragment_shader_free(cuboid_fragment_shader_t *shader);

#endif
