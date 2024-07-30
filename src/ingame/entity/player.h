#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <string.h>
#include "../../util/vec.h"
#include "./base_entity.h"
#include "../../gfx.h"

#define PLAYER_TYPE 1

#define PLAYER_STATE_NONE 0
#define PLAYER_STATE_IDLE 1

typedef uint8_t player_state_t;

typedef struct {
  base_entity_t core;
  player_state_t state;
  sprite_code_t sprite;
  vec2f sprite_bias;
} player_t;

player_t* player_init();
void player_destroy(player_t* player);
void player_spawn(player_t* player, vec2f pos);
void player_fsm_simulate(player_t* player, float dt);

#endif