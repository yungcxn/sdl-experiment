#include "./ingame.h"

ingame_data_t* ingame_init() {
  ingame_data_t* ingame_data = (ingame_data_t*) malloc(sizeof(ingame_data_t));
  return ingame_data; // TODO
}


void ingame_destroy(ingame_data_t* ingame_data) {
  free(ingame_data);
}


void ingame_update(ingame_data_t* ingame_data) {
  // TODO
  return;
}
