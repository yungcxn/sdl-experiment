#include "./player.h"

player_t* player_init() {
  player_t* player = (player_t*) malloc(sizeof(player_t));
  player->core.type = PLAYER_TYPE;
  player->core.id = PLAYER_TYPE; // will be also 1
  strcpy(player->core.name, "can");
  player->core.pos = (vec2f) {0.0f, 0.0f};
  player->core.sprite_offset = (vec2f) {-0.5f, -1.875f};
  player->core.collision_box = (mat22f) {-0.4375f, -0.5625f, 0.875f, 0.625f};
  player->core.alt_collision_box = (mat22f) {0.0f, 0.0f, 0.0f, 0.0f};
  player->core.hurt_box = player->core.collision_box;
  player->state = PLAYER_STATE_NONE;
  player->sprite = GFX_SPRITE_NONE;
  return player;
}


void player_destroy(player_t* player) {
  free(player);
}


void player_spawn(player_t* player, vec2f pos) {
  player->core.pos = pos;
  player->state = PLAYER_STATE_IDLE;
  player->sprite = GFX_SPRITE_CAN_IDLE_D;
}


void player_update(player_t* player, float dt) {
  return;
}