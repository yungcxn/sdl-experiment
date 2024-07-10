#ifndef PLAYER_H
#define PLAYER_H

#include "./entity.h"

typedef uint32_t player_state_t;

typedef struct {
  entity_t player_entity;
  player_state_t current_state;
  img_sprite_ptr states_sprite;
  vec2d sprite_bias;
  biased_bb collision_box; // relative to player_entity.pos
  biased_bb hurt_box; // relative to player_entity.pos
} player_t;

player_state_t player_fsm_get_next(player_state_t p, uint32_t dt);
void player_fsm_simulate(player_t* p, uint32_t dt);

#endif