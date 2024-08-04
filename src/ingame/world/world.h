#ifndef world_H
#define world_H

#include <stdint.h>
#include <stdlib.h>
#include "../../util/primitive.h"
#include "../../util/debug.h"
#include "../../gfx.h"
#include "../entity/base_entity.h"
#include "../entity/player.h"

#define world_OVERWORLD_ID 1

typedef struct {
  uint32_t world_tile_x; // positioning is top left
  uint32_t world_tile_y;
  uint16_t sprite_id;
} world_tile_t; // for environment only!

// TODO
// monsters
// nonlive_interact
// live_interact
typedef struct {
  uint16_t base_tile_width; // height in tiles
  uint16_t base_tile_height;
  gfx_sprite_code_t* base;
  gfx_sprite_code_t base2_len;
  world_tile_t* base2;
  uint16_t bg_len;
  world_tile_t* bg;
  uint16_t fg_len;
  world_tile_t* fg;
} world_world_t;


typedef struct {
  world_world_t current_loaded_world;
  uint16_t current_world_number;
  //particle_t* loaded_particles_array;
  player_t* player;
  uint16_t entity_count; // player excluded
  base_entity_t* entity_array;
} world_handler_t;


world_handler_t* world_handler_init(player_t* player);
void world_handler_destroy(world_handler_t* world_handler);
void world_load_world(world_handler_t* world_handler, uint16_t world_number);
 
#endif