#ifndef H_CUBOID_LEVEL
#define H_CUBOID_LEVEL


typedef enum {
  air = 0,
  solid = 1
} block_type_t;

typedef struct {
  int x;
  int y;
  block_type_t type;
} block_t;

typedef struct {
  block_t data[10]
} level_t;

level_t *cuboid_level_read(const char *path);

#endif
