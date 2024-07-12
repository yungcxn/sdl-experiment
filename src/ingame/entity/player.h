#ifndef PLAYER_H
#define PLAYER_H

#include "../../gfx.h"
#include "../../util/vec.h"

#define PLAYER_MAX_NAME 5

typedef uint32_t player_state_t;

typedef struct {
  char name[PLAYER_MAX_NAME];
  vec3f pos; //z is height
  player_state_t current_state;
  gfx_sprite_id state_sprite;
  vec2f sprite_bias;

  vec2f collision_box; // relative to bias
  vec2f collision_box_bias; // relative to player_entity.pos

  vec2f hurt_box; // relative to bias
  vec2f hurt_box_bias; // relative to player_entity.pos

  vec2f alt_collision_box; // relative to bias
  vec2f alt_collision_box_bias; // relative to player_entity.pos
  
  vec2f alt_hurt_box; // relative to bias
  vec2f alt_hurt_box_bias; // relative to player_entity.pos
} player_t;

player_state_t player_fsm_get_next(player_state_t p, float dt);
void player_fsm_simulate(player_t* p, float dt);

#endif