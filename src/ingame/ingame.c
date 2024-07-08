#include "./ingame.h"

/**
    player_t* player_ref;
    map_map_t* loaded_map;
    
       ingame_data_t;
 */
//     0x33           0x555
//    üüüü**        *ingame_data     ->         data
void ingame_init(ingame_data_t** ingame_data) {
  *ingame_data = (ingame_data_t*) malloc(sizeof(ingame_data_t));
  //player_init(&(*ingame_data).player_ref);
}

void ingame_destroy(ingame_data_t** ingame_data) {
  free(*ingame_data);
  *ingame_data = NULL;
}