#include <stdio.h>
#include <stdbool.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cglm/mat4.h>
#include <cglm/affine.h>
#include <cglm/vec3.h>

#include "cuboid/level.h"
#include "cuboid/shader.h"
#include "cuboid/player.h"


void glfw_error_callback(int error, const char *description) {
  printf("Error: %s\n", description);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}


int main() {

  glfwSetErrorCallback(glfw_error_callback);
  glewExperimental = true;

  if(!glfwInit()) {
    printf("Failed to initalize glfw\n");
    return 1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "Cuboid", NULL, NULL);

  if(!window) {
    printf("Failed to initalize opengql context\n");
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  if(glewInit() != GLEW_OK) {
    printf("Failed to initalize glew\n");
    glfwTerminate();
    return 1;
  }

  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  glViewport(0, 0, 800, 600);

  cuboid_vertex_shader_t *vertex_shader = cuboid_vertex_shader_load("./src/shaders/vertex.glsl");
  cuboid_fragment_shader_t *fragment_shader = cuboid_fragment_shader_load("./src/shaders/fragment.glsl");

  printf("after shader\n");

  unsigned int shader_program;
  shader_program = glCreateProgram();
  glAttachShader(shader_program, vertex_shader->shader_id);
  glAttachShader(shader_program, fragment_shader->shader_id);
  glLinkProgram(shader_program);


  cuboid_player_t *player = cuboid_player_create();


  do {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    int vertex_color_location = glGetUniformLocation(shader_program, "customColor");
    int transform_location = glGetUniformLocation(shader_program, "transform");

    glUseProgram(shader_program);
    glUniform4f(vertex_color_location, 0.0f, 1.0f, 0.0f, 1.0f);

    mat4 transform_matrix;
    glm_mat4_identity(transform_matrix);
    vec3 a = {1.5f, 0.5f, 0.5f};
    glm_scale(transform_matrix, a);
    glUniformMatrix4fv(transform_location, 1, GL_FALSE, transform_matrix);

    cuboid_player_draw(player);


    if(glfwGetKey(window, GLFW_KEY_SPACE) != GLFW_PRESS) {
      cuboid_player_move(player, -0.001f, -0.001f);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
  } while(
    glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
    glfwWindowShouldClose(window) == 0
  );

  glfwTerminate();
}
