#include <stdio.h>

#include <cuboid/level.h>

level_t *cuboid_level_read(const char *path) {
  FILE *level_file_ptr;

  level_file_ptr = fopen(path, "rb");
  printf("Reading level");
}
