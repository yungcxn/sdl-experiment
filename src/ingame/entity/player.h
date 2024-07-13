#ifndef PLAYER_H
#define PLAYER_H

#include "../../gfx.h"
#include "../../util/vec.h"
#include "./base_entity.h"

#define PLAYER_MAX_NAME 5

typedef uint32_t player_state_t;

typedef struct {
  base_entity_t* core;
  player_state_t current_state;
  gfx_sprite_id state_sprite;
  vec2f sprite_bias;
} player_t;

player_state_t player_fsm_get_next(player_state_t p, float dt);
void player_fsm_simulate(player_t* p, float dt);

#endif