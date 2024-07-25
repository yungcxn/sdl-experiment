#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <string.h>
#include "../../util/vec.h"
#include "./base_entity.h"
#include "../../gfx.h"

#define PLAYER_TYPE 1

#define PLAYER_STATE_NONE 0

typedef uint32_t player_state_t;

typedef struct {
  base_entity_t core;
  player_state_t state;
  sprite_code_t state_sprite;
  vec2f sprite_bias;
} player_t;

player_t* player_init();
void player_destroy();
player_state_t player_fsm_get_next(player_state_t p, float dt);
void player_fsm_simulate(player_t* p, float dt);

#endif