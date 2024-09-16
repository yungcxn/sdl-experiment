#include "./player.h"

player_t* player_init() {
  player_t* player = (player_t*) malloc(sizeof(player_t));
  player->core.type = PLAYER_TYPE;
  player->core.id = PLAYER_TYPE; // will be also 1
  strcpy(player->core.name, "can");
  VEC2_SET(player->core.pos, 0.0f, 0.0f);
  VEC2_SET(player->core.sprite_offset, -0.5f, -1.875f);
  MAT22_SET(player->core.collision_box, -0.4375f, -0.5625f, 0.875f, 0.625f);
  MAT22_SET(player->core.alt_collision_box, 0.0f, 0.0f, 0.0f, 0.0f);
  MAT22_COPY(player->core.hurt_box, player->core.collision_box);
  player->state = PLAYER_STATE_IDLE;
  player->last_state = PLAYER_STATE_IDLE;
  player->sprite = GFX_SPRITE_NONE;
  player->sprite_elapsed_time = 0.0f;
  player->diam_speed = 1.0f/16.0f * 50.0f; // 1/16 * 3
  player->diag_speed = math_fsqrt(
    math_fpow(player->diam_speed)/2.0f
  );
  VEC2_SET(player->current_speed, 0.0f, 0.0f);
  player->maxhealth = 4; // should be even
  player->health = 4;
  player->maxstamina = 5; // should be odd
  player->stamina = 5;
  player->anim_over = false;
  return player;
}


void player_destroy(player_t* player) {
  SAFE_FREE(player);
}


void player_spawn(player_t* player, vec2f pos) {
  VEC2_COPY(player->core.pos, pos);
  player->state = PLAYER_STATE_IDLE;
  player->sprite = GFX_SPRITE_CAN_IDLE_D;
}

// returns whether the state changed this time
static inline bool _player_update_state(player_t* player, event_input_t input,
                                        float dt) {
  player_state_t state_to_be = 0;

  if (!(player->state & PLAYER_STATE_ROLL)) {
    if (event_a_down(input))
      state_to_be |= PLAYER_STATE_ROLL;
    if (event_up_down(input))
      state_to_be |= PLAYER_STATE_RUN_U;
    if (event_right_down(input)) 
      state_to_be |= PLAYER_STATE_RUN_R;
    if (event_down_down(input)) 
      state_to_be |= PLAYER_STATE_RUN_D;
    if (event_left_down(input))
      state_to_be |= PLAYER_STATE_RUN_L;
  }
  
  if (state_to_be == PLAYER_STATE_ROLL) // rolling without direction
    state_to_be |= (player->last_state & 0b1111); // direction he is looking

  bool state_changed = state_to_be != player->state;

  if (state_changed) {
    player->last_state = player->state;
    player->state = state_to_be;
  }

  return state_changed;
}

static inline bool _player_update_sprite(player_t* player, bool state_changed,
                                         float dt) {

  // return when animover?
  if (player->anim_over && !state_changed) return true;

  if (player->state & PLAYER_STATE_RUN_D) {
    
    if (player->state & PLAYER_STATE_ROLL)
      return anim(
        &(player->sprite), &(player->sprite_elapsed_time), PLAYER_ROLL_ANIM_TIME,
        state_changed, 9, GFX_SPRITE_CAN_ROLL_D_1, GFX_SPRITE_CAN_ROLL_D_2,
        GFX_SPRITE_CAN_ROLL_D_3, GFX_SPRITE_CAN_ROLL_D_4,
        GFX_SPRITE_CAN_ROLL_D_5, GFX_SPRITE_CAN_ROLL_D_6,
        GFX_SPRITE_CAN_ROLL_D_7, GFX_SPRITE_CAN_ROLL_D_8,
        GFX_SPRITE_CAN_ROLL_D_9
      );

    anim_loop(
      &(player->sprite), &(player->sprite_elapsed_time), PLAYER_RUN_ANIM_TIME,
      state_changed, 6, 
      GFX_SPRITE_CAN_RUN_D_1, GFX_SPRITE_CAN_RUN_D_2, GFX_SPRITE_CAN_RUN_D_3,
      GFX_SPRITE_CAN_RUN_D_4, GFX_SPRITE_CAN_RUN_D_5, GFX_SPRITE_CAN_RUN_D_6
    );
    return false;

  } else if (player->state & PLAYER_STATE_RUN_U) {
    
    if (player->state & PLAYER_STATE_ROLL)
      return anim(
        &(player->sprite), &(player->sprite_elapsed_time), PLAYER_ROLL_ANIM_TIME,
        state_changed, 9, GFX_SPRITE_CAN_ROLL_U_1, GFX_SPRITE_CAN_ROLL_U_2,
        GFX_SPRITE_CAN_ROLL_U_3, GFX_SPRITE_CAN_ROLL_U_4,
        GFX_SPRITE_CAN_ROLL_U_5, GFX_SPRITE_CAN_ROLL_U_6,
        GFX_SPRITE_CAN_ROLL_U_7, GFX_SPRITE_CAN_ROLL_U_8,
        GFX_SPRITE_CAN_ROLL_U_9
      );

    anim_loop(
      &(player->sprite), &(player->sprite_elapsed_time), PLAYER_RUN_ANIM_TIME,
      state_changed, 6, 
      GFX_SPRITE_CAN_RUN_U_1, GFX_SPRITE_CAN_RUN_U_2, GFX_SPRITE_CAN_RUN_U_3,
      GFX_SPRITE_CAN_RUN_U_4, GFX_SPRITE_CAN_RUN_U_5, GFX_SPRITE_CAN_RUN_U_6
    );
    return false;

  } else if (player->state & PLAYER_STATE_RUN_R) {

    if (player->state & PLAYER_STATE_ROLL)
      return anim(
        &(player->sprite), &(player->sprite_elapsed_time), PLAYER_ROLL_ANIM_TIME,
        state_changed, 9, GFX_SPRITE_CAN_ROLL_R_1, GFX_SPRITE_CAN_ROLL_R_2,
        GFX_SPRITE_CAN_ROLL_R_3, GFX_SPRITE_CAN_ROLL_R_4,
        GFX_SPRITE_CAN_ROLL_R_5, GFX_SPRITE_CAN_ROLL_R_6,
        GFX_SPRITE_CAN_ROLL_R_7, GFX_SPRITE_CAN_ROLL_R_8,
        GFX_SPRITE_CAN_ROLL_R_9
      );

    anim_loop(
      &(player->sprite), &(player->sprite_elapsed_time), PLAYER_RUN_ANIM_TIME,
      state_changed, 6, 
      GFX_SPRITE_CAN_RUN_R_1, GFX_SPRITE_CAN_RUN_R_2, GFX_SPRITE_CAN_RUN_R_3,
      GFX_SPRITE_CAN_RUN_R_4, GFX_SPRITE_CAN_RUN_R_5, GFX_SPRITE_CAN_RUN_R_6
    );
    return false;

  } else if (player->state & PLAYER_STATE_RUN_L) {

    if (player->state & PLAYER_STATE_ROLL)
      return anim(
        &(player->sprite), &(player->sprite_elapsed_time), PLAYER_ROLL_ANIM_TIME,
        state_changed, 9, GFX_SPRITE_CAN_ROLL_L_1, GFX_SPRITE_CAN_ROLL_L_2,
        GFX_SPRITE_CAN_ROLL_L_3, GFX_SPRITE_CAN_ROLL_L_4,
        GFX_SPRITE_CAN_ROLL_L_5, GFX_SPRITE_CAN_ROLL_L_6,
        GFX_SPRITE_CAN_ROLL_L_7, GFX_SPRITE_CAN_ROLL_L_8,
        GFX_SPRITE_CAN_ROLL_L_9
      );

    anim_loop(
      &(player->sprite), &(player->sprite_elapsed_time), PLAYER_RUN_ANIM_TIME,
      state_changed, 6, 
      GFX_SPRITE_CAN_RUN_L_1, GFX_SPRITE_CAN_RUN_L_2, GFX_SPRITE_CAN_RUN_L_3,
      GFX_SPRITE_CAN_RUN_L_4, GFX_SPRITE_CAN_RUN_L_5, GFX_SPRITE_CAN_RUN_L_6
    );
    return false;

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
    return false;
  }

  return false;
}

static inline void _player_update_movement(player_t* player, float dt) {

  switch (player->state & 0b1111) {
    case PLAYER_STATE_IDLE: 
      VEC2_SET(player->current_speed, 0, 0);
      break;
    case PLAYER_STATE_RUN_U: 
      VEC2_SET(player->current_speed, 0, -player->diam_speed);
      break;
    case PLAYER_STATE_RUN_R:
      VEC2_SET(player->current_speed, player->diam_speed, 0);
      break;
    case PLAYER_STATE_RUN_D:
      VEC2_SET(player->current_speed, 0, player->diam_speed);
      break;
    case PLAYER_STATE_RUN_L:
      VEC2_SET(player->current_speed, -player->diam_speed, 0);
      break;
    case PLAYER_STATE_RUN_UR:
      VEC2_SET(player->current_speed, player->diag_speed, -player->diag_speed);
      break;
    case PLAYER_STATE_RUN_RD:
      VEC2_SET(player->current_speed, player->diag_speed, player->diag_speed);
      break;
    case PLAYER_STATE_RUN_DL:
      VEC2_SET(player->current_speed, -player->diag_speed, player->diag_speed);
      break;
    case PLAYER_STATE_RUN_LU:
      VEC2_SET(player->current_speed, -player->diag_speed, -player->diag_speed);
      break;
  }

  VEC2_SCALE(player->current_speed, dt);
  VEC2_ADD(player->core.pos, player->current_speed);

}


void player_update(player_t* player, event_input_t input, float dt) {
  DEBUG_PRINTF("%d", player->state);
  player->sprite_elapsed_time += dt;
  bool state_changed = _player_update_state(player, input, dt);
  player->anim_over = _player_update_sprite(player, state_changed, dt);
  _player_update_movement(player, dt);
}
