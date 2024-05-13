#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <GL/glew.h>

#include <cuboid/shader.h>

char *load_shader_file(const char *path);

cuboid_vertex_shader_t *cuboid_vertex_shader_load(const char *path) {
  int success;
  char info_log[512];

  char *source_code = load_shader_file(path);

  cuboid_vertex_shader_t *shader = malloc(sizeof(cuboid_vertex_shader_t));

  shader->shader_id = glCreateShader(GL_VERTEX_SHADER);
  shader->source_code = source_code;
  
  glShaderSource(shader->shader_id, 1, &shader->source_code, NULL);
  glCompileShader(shader->shader_id);

  glGetShaderiv(shader->shader_id, GL_COMPILE_STATUS, &success);

  if(!success) {
    glGetShaderInfoLog(shader->shader_id, 512, NULL, info_log);
    printf("Vertex shader compilation failed: path=%s; %s\n", path, info_log);
    cuboid_vertex_shader_free(shader);
  }

  return shader;
}

void cuboid_vertex_shader_free(cuboid_vertex_shader_t *shader) {
  glDeleteShader(shader->shader_id);
  free(shader->source_code);
  free(shader);
}

cuboid_fragment_shader_t *cuboid_fragment_shader_load(const char *path) {
  int success;
  char info_log[512];

  char *source_code = load_shader_file(path);

  cuboid_fragment_shader_t *shader = malloc(sizeof(cuboid_fragment_shader_t));

  shader->shader_id = glCreateShader(GL_FRAGMENT_SHADER);
  shader->source_code = source_code;
  
  glShaderSource(shader->shader_id, 1, &shader->source_code, NULL);
  glCompileShader(shader->shader_id);

  glGetShaderiv(shader->shader_id, GL_COMPILE_STATUS, &success);

  if(!success) {
    glGetShaderInfoLog(shader->shader_id, 512, NULL, info_log);
    printf("Vertex shader compilation failed: path=%s; %s\n", path, info_log);
    cuboid_fragment_shader_free(shader);
  }

  return shader;
}

void cuboid_fragment_shader_free(cuboid_fragment_shader_t *shader) {
  glDeleteShader(shader->shader_id);
  free(shader->source_code);
  free(shader);
}

char *load_shader_file(const char *path) {
  // TODO: loading of bigger files + error handling
  FILE *shader_file_ptr;
  char buffer[1024];
  size_t read_bytes, total_read_bytes = 0;
  char *loaded_shader = NULL;

  shader_file_ptr = fopen(path, "rb");

  while((read_bytes = fread(buffer, 1, 1024, shader_file_ptr)) != 0) {
    total_read_bytes += read_bytes;

    if(loaded_shader == NULL) {
      loaded_shader = malloc(read_bytes + 1);
      memcpy(loaded_shader, buffer, read_bytes);
      loaded_shader[read_bytes] = '\0';
    }
  }

  fclose(shader_file_ptr);

  return loaded_shader;
}
