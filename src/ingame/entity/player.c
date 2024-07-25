#include "./player.h"

player_t* player_init() {
  player_t* player = (player_t*) malloc(sizeof(player_t));
  player->core.type = PLAYER_TYPE;
  player->core.id = PLAYER_TYPE; // will be also 1
  strcpy(player->core.name, "can");
  player->core.pos = (vec2f) {0.0f, 0.0f};
  player->core.collision_box = (mat22f) {0.0f, 0.0f, 0.0f, 0.0f};
  player->core.alt_collision_box = (mat22f) {0.0f, 0.0f, 0.0f, 0.0f};
  player->core.hurt_box = (mat22f) {0.0f, 0.0f, 0.0f, 0.0f};
  player->state = PLAYER_STATE_NONE;
  //player->state_sprite = GFX_
  return player;
}


void player_destroy(player_t* player) {
  free(player);
}

player_state_t player_fsm_get_next(player_state_t p, float dt) {
  return 0;
}

void player_fsm_simulate(player_t* p, float dt) {
  (*p).state = player_fsm_get_next((*p).state, dt);
}