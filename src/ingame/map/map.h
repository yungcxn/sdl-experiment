#ifndef MAP_H
#define MAP_H

#define MAP_BASE_HEIGHT 1

#include "../../util/img.h"

typedef struct {
  int map_pixel_x; // positioning is top left
  int map_pixel_y;
  img_sprite_ptr sprite_ref;
} map_random_sprite_t; // for environment only!
 
typedef struct {
  int map_id;
  int tile_width;
  int tile_height;
  float* heights_arr; // array, i can make use of floats to implement special stuff
  img_tile_ptr* tiles_arr;

  int free_sprites;
  map_random_sprite_t* free_sprites_arr;
} map_map_t;

#endif