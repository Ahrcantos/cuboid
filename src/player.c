#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>

#include "cuboid/player.h"

cuboid_player_t *cuboid_player_create() {
  cuboid_player_t *player = malloc(sizeof(cuboid_player_t));

  player->vertices[0] = 0.5f;
  player->vertices[1] = 0.5f;
  player->vertices[2] = 0.0f;
  player->vertices[3] = 0.5f;
  player->vertices[4] = -0.5f;
  player->vertices[5] = 0.0f;
  player->vertices[6] = -0.5f;
  player->vertices[7] = 0.5f;
  player->vertices[8] = 0.0f;
  player->vertices[9] = 0.5f;
  player->vertices[10] = -0.5f;
  player->vertices[11] = 0.0f;
  player->vertices[12] = -0.5f;
  player->vertices[13] = -0.5f;
  player->vertices[14] = 0.0f;
  player->vertices[15] = -0.5f;
  player->vertices[16] = 0.5f;
  player->vertices[17] = 0.0f;

  glGenVertexArrays(1, &player->vao);
  glBindVertexArray(player->vao);

  glGenBuffers(1, &player->vbo);
  glBindBuffer(GL_ARRAY_BUFFER, player->vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(player->vertices), player->vertices, GL_DYNAMIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
  glEnableVertexAttribArray(0);

  return player;
}

void cuboid_player_draw(cuboid_player_t *player) {
  glBindVertexArray(player->vao);
  glBindBuffer(GL_ARRAY_BUFFER, player->vbo);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}

void cuboid_player_move(cuboid_player_t *player, float x, float y) {
  player->vertices[0] += x;
  player->vertices[1] += y;
  player->vertices[3] += x;
  player->vertices[4] += y;
  player->vertices[6] += x;
  player->vertices[7] += y;
  player->vertices[9] += x;
  player->vertices[10] += y;
  player->vertices[12] += x;
  player->vertices[13] += y;
  player->vertices[15] += x;
  player->vertices[16] += y;

  glBindVertexArray(player->vao);
  glBindBuffer(GL_ARRAY_BUFFER, player->vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(player->vertices), player->vertices, GL_DYNAMIC_DRAW);
}
