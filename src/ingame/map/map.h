#ifndef MAP_H
#define MAP_H

#include <stdint.h>

#define MAP_BASE_HEIGHT 1

typedef struct {
  uint16_t map_tile_x; // positioning is top left
  uint16_t map_tile_y;
  float map_tile_z; // height
  gfx_sprite_id sprite_id;
} map_tile_t; // for environment only!

typedef struct {
  uint16_t h_tiles; // height in tiles
  uint16_t w_tiles;
  map_tile_t* tile_arr;
} map_map_t;

#endif