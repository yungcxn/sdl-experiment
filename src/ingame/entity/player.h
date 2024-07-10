#ifndef PLAYER_H
#define PLAYER_H

#include "./entity.h"

typedef uint32_t player_state_t;

typedef struct {
  entity_t player_entity;
  player_state_t current_state;
  img_sprite* states_sprite;
  vec2f sprite_bias;
  biased_bb collision_box; // relative to player_entity.pos
  biased_bb hurt_box; // relative to player_entity.pos
} player_t;

player_state_t player_fsm_get_next(player_state_t p, float dt);
void player_fsm_simulate(player_t* p, float dt);

#endif