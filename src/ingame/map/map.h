#ifndef MAP_H
#define MAP_H

#include <stdint.h>
#include <stdlib.h>
#include "../../util/primitive.h"

#define MAP_OVERWORLD_ID 1

typedef struct {
  uint32_t map_tile_x; // positioning is top left
  uint32_t map_tile_y;
  uint16_t sprite_id;
} map_tile_t; // for environment only!

// TODO
// monsters
// nonlive_interact
// live_interact
typedef struct {
  uint16_t base_tile_width; // height in tiles
  uint16_t base_tile_height;
  uint16_t* base;
  uint16_t base2_len;
  map_tile_t* base2;
  uint16_t bg_len;
  map_tile_t* bg;
  uint16_t fg_len;
  map_tile_t* fg;
} map_map_t;


typedef struct {
  map_map_t current_loaded_map;
  uint16_t current_map_number;
} map_handler_t;


map_handler_t* map_handler_init();
void map_handler_destroy(map_handler_t* map_handler);
void map_load_map(map_handler_t* map_handler, uint16_t map_number);
 
#endif