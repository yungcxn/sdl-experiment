#ifndef INGAME_H
#define IMGAME_H

#include "./entity/player.h"
#include "./map/map.h"

typedef struct {
  player_t* player_ref;
  map_map_t* loaded_map;
} ingame_data_t;

void ingame_init(ingame_data_t** ingame_data);
void ingame_destroy(ingame_data_t** ingame_data);
void ingame_update();

#endif