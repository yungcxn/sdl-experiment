#include "./ingame.h"

ingame_data_t* ingame_init() {
  ingame_data_t* ingame_data = (ingame_data_t*) malloc(sizeof(ingame_data_t));
  ingame_data->player = player_init();
  ingame_data->world_handler = world_handler_init(ingame_data->player);
  return ingame_data; // TODO
}


void ingame_destroy(ingame_data_t* ingame_data) {
  player_destroy(ingame_data->player);
  world_handler_destroy(ingame_data->world_handler);
  safe_free(ingame_data);
}


void ingame_update(ingame_data_t* ingame_data) {
  // TODO
  return;
}
