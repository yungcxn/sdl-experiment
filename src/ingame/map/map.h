#ifndef MAP_H
#define MAP_H

#include <stdint.h>

#define MAP_BASE_HEIGHT 1

typedef struct {
  uint32_t map_tile_x; // positioning is top left
  uint32_t map_tile_y;
  gfx_sprite_id sprite_id;
} map_tile_t; // for environment only!

// TODO
// monsters
// nonlive_interact
// live_interact
typedef struct {
  uint32_t h_tiles; // height in tiles
  uint32_t w_tiles;
  map_tile_t* base1;
  map_tile_t* base2;
  map_tile_t* bg;
  map_tile_t* fg;
} map_map_t;

#endif