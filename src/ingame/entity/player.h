#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <string.h>
#include "../../util/vec.h"
#include "./base_entity.h"
#include "../../gfx.h"
#include "../../event/event.h"
#include "../../util/math.h"
#include "../../util/anim.h"

#define PLAYER_TYPE 1

#define PLAYER_STATE_IDLE   0
#define PLAYER_STATE_RUN_U  0b0001
#define PLAYER_STATE_RUN_R  0b0010
#define PLAYER_STATE_RUN_D  0b0100
#define PLAYER_STATE_RUN_L  0b1000
#define PLAYER_STATE_RUN_UR 0b0011
#define PLAYER_STATE_RUN_RD 0b0110
#define PLAYER_STATE_RUN_DL 0b1100
#define PLAYER_STATE_RUN_LU 0b1001
#define PLAYER_STATE_ROLL   0b10000 //modificator

#define PLAYER_RUN_ANIM_TIME 0.1f
#define PLAYER_ROLL_ANIM_TIME 0.3f

typedef uint8_t player_state_t;

typedef struct {
  base_entity_t core;
  player_state_t state;
  player_state_t last_state;
  gfx_sprite_code_t sprite;
  float sprite_elapsed_time;
  vec2f sprite_bias;
  float diam_speed;
  float diag_speed;
  vec2f current_speed;
  uint8_t maxhealth;
  uint8_t health;
  uint8_t maxstamina;
  uint8_t stamina;
  bool anim_over;
} player_t;

player_t* player_init();
void player_destroy(player_t* player);
void player_spawn(player_t* player, vec2f pos);
void player_update(player_t* player, event_input_t input, float dt);

#endif