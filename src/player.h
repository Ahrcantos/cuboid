#ifndef H_CUBOID_PLAYER
#define H_CUBOID_PLAYER


typedef struct {
  unsigned int vao;
  unsigned int vbo;
  float vertices[18];
} cuboid_player_t;

cuboid_player_t *cuboid_player_create();
void cuboid_player_draw(cuboid_player_t *player);
void cuboid_player_move(cuboid_player_t *player, float x, float y);
void cuboid_player_free(cuboid_player_t *player);


#endif
