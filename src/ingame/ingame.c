#include "./ingame.h"

ingame_data_t* ingame_init() {
  ingame_data_t* ingame_data = (ingame_data_t*) malloc(sizeof(ingame_data_t));
  ingame_data->player = player_init();
  ingame_data->world_handler = world_handler_init(ingame_data->player);
  ingame_data->hud = (hud_t) {ingame_data->player};
  return ingame_data; // TODO
}


void ingame_destroy(ingame_data_t* ingame_data) {
  player_destroy(ingame_data->player);
  world_handler_destroy(ingame_data->world_handler);
  SAFE_FREE(ingame_data);
}


void ingame_update(ingame_data_t* ingame_data, event_input_t input, float dt) {
  ingame_data->input = input;
  player_update(ingame_data->player, input, dt);
  cam_move_clean(&(ingame_data->cam), ingame_data->player->core.pos, dt);
}
