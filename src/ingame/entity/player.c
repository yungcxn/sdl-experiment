#include "./player.h"

player_t* player_init() {
  player_t* player = (player_t*) malloc(sizeof(player_t));
  player->core.type = PLAYER_TYPE;
  player->core.id = PLAYER_TYPE; // will be also 1
  strcpy(player->core.name, "can");
  vec2_set(player->core.pos, 0.0f, 0.0f);
  vec2_set(player->core.sprite_offset, -0.5f, -1.875f);
  mat22_set(player->core.collision_box, -0.4375f, -0.5625f, 0.875f, 0.625f);
  mat22_set(player->core.alt_collision_box, 0.0f, 0.0f, 0.0f, 0.0f);
  mat22_copy(player->core.hurt_box, player->core.collision_box);
  player->state = PLAYER_STATE_IDLE;
  player->last_state = PLAYER_STATE_IDLE;
  player->sprite = GFX_SPRITE_NONE;
  player->sprite_elapsed_time = 0.0f;
  player->diam_speed = 1.0f/16.0f * 50.0f; // 1/16 * 3
  player->diag_speed = math_fsqrt(
    math_fpow(player->diam_speed)/2.0f
  );
  vec2_set(player->current_speed, 0.0f, 0.0f);
  player->maxhealth = 4; // should be even
  player->health = 4;
  player->maxstamina = 5; // should be odd
  player->stamina = 5;
  return player;
}


void player_destroy(player_t* player) {
  safe_free(player);
}


void player_spawn(player_t* player, vec2f pos) {
  vec2_copy(player->core.pos, pos);
  player->state = PLAYER_STATE_IDLE;
  player->sprite = GFX_SPRITE_CAN_IDLE_D;
}


void player_update(player_t* player, event_input_t input, float dt) {

  player->sprite_elapsed_time += dt;
  
  /* STATE CHANGE SECTION */
  player_state_t state_to_be = 0;

  if (event_up_down(input))
    state_to_be |= PLAYER_STATE_RUN_U;
  if (event_right_down(input)) 
    state_to_be |= PLAYER_STATE_RUN_R;
  if (event_down_down(input)) 
    state_to_be |= PLAYER_STATE_RUN_D;
  if (event_left_down(input)) {
    state_to_be |= PLAYER_STATE_RUN_L;
  }
  if (state_to_be == 0) 
    state_to_be = PLAYER_STATE_IDLE;

  
  if ((!(state_to_be ^ 0b1010)) || (!(state_to_be ^ 0b0101))) {
    state_to_be = PLAYER_STATE_IDLE;
  }
  

  bool state_changed = state_to_be != player->state;

  if (state_changed) {
    player->last_state = player->state;
    player->state = state_to_be;
  }

  /* UPDATE SECTION  */
  
  if (player->state & PLAYER_STATE_RUN_D) {
    
    anim_loop(
      &(player->sprite), &(player->sprite_elapsed_time), PLAYER_RUN_ANIM_TIME,
      state_changed, 6, 
      GFX_SPRITE_CAN_RUN_D_1, GFX_SPRITE_CAN_RUN_D_2, GFX_SPRITE_CAN_RUN_D_3,
      GFX_SPRITE_CAN_RUN_D_4, GFX_SPRITE_CAN_RUN_D_5, GFX_SPRITE_CAN_RUN_D_6
    );

  } else if (player->state & PLAYER_STATE_RUN_U) {

    anim_loop(
      &(player->sprite), &(player->sprite_elapsed_time), PLAYER_RUN_ANIM_TIME,
      state_changed, 6, 
      GFX_SPRITE_CAN_RUN_U_1, GFX_SPRITE_CAN_RUN_U_2, GFX_SPRITE_CAN_RUN_U_3,
      GFX_SPRITE_CAN_RUN_U_4, GFX_SPRITE_CAN_RUN_U_5, GFX_SPRITE_CAN_RUN_U_6
    );

  } else if (player->state & PLAYER_STATE_RUN_R) {

    anim_loop(
      &(player->sprite), &(player->sprite_elapsed_time), PLAYER_RUN_ANIM_TIME,
      state_changed, 6, 
      GFX_SPRITE_CAN_RUN_R_1, GFX_SPRITE_CAN_RUN_R_2, GFX_SPRITE_CAN_RUN_R_3,
      GFX_SPRITE_CAN_RUN_R_4, GFX_SPRITE_CAN_RUN_R_5, GFX_SPRITE_CAN_RUN_R_6
    );

  } else if (player->state & PLAYER_STATE_RUN_L) {

    anim_loop(
      &(player->sprite), &(player->sprite_elapsed_time), PLAYER_RUN_ANIM_TIME,
      state_changed, 6, 
      GFX_SPRITE_CAN_RUN_L_1, GFX_SPRITE_CAN_RUN_L_2, GFX_SPRITE_CAN_RUN_L_3,
      GFX_SPRITE_CAN_RUN_L_4, GFX_SPRITE_CAN_RUN_L_5, GFX_SPRITE_CAN_RUN_L_6
    );

  } else if (player->state == PLAYER_STATE_IDLE) {

    if ((player->last_state & PLAYER_STATE_RUN_U) && state_changed) {
      player->sprite = GFX_SPRITE_CAN_IDLE_U;
    } else if ((player->last_state & PLAYER_STATE_RUN_D) && state_changed) {
      player->sprite = GFX_SPRITE_CAN_IDLE_D;
    } else if (player->last_state == PLAYER_STATE_RUN_R && state_changed) {
      player->sprite = GFX_SPRITE_CAN_IDLE_R;
    } else if (player->last_state == PLAYER_STATE_RUN_L && state_changed) {
      player->sprite = GFX_SPRITE_CAN_IDLE_L;
    }

  }

  switch (player->state) {
    case PLAYER_STATE_IDLE: 
      vec2_set(player->current_speed, 0, 0);
      break;
    case PLAYER_STATE_RUN_U: 
      vec2_set(player->current_speed, 0, -player->diam_speed);
      break;
    case PLAYER_STATE_RUN_R:
      vec2_set(player->current_speed, player->diam_speed, 0);
      break;
    case PLAYER_STATE_RUN_D:
      vec2_set(player->current_speed, 0, player->diam_speed);
      break;
    case PLAYER_STATE_RUN_L:
      vec2_set(player->current_speed, -player->diam_speed, 0);
      break;
    case PLAYER_STATE_RUN_UR:
      vec2_set(player->current_speed, player->diag_speed, -player->diag_speed);
      break;
    case PLAYER_STATE_RUN_RD:
      vec2_set(player->current_speed, player->diag_speed, player->diag_speed);
      break;
    case PLAYER_STATE_RUN_DL:
      vec2_set(player->current_speed, -player->diag_speed, player->diag_speed);
      break;
    case PLAYER_STATE_RUN_LU:
      vec2_set(player->current_speed, -player->diag_speed, -player->diag_speed);
      break;
  }

  // moving
  if ((player->state & 0b1111)) {
    vec2_scale(player->current_speed, dt);
    vec2_add(player->core.pos, player->current_speed);
  }

}