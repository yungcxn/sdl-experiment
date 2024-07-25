#ifndef INGAME_H
#define INGAME_H

#include "./entity/player.h"
#include "./map/map.h"
#include "./particle/particle.h"
#include "./cam/cam.h"


typedef struct {
  player_t* player_ref;
  map_handler_t* map_handler;
  cam_t cam;
  //base_entity_t TODO
  int loaded_entities_amount;
  int loaded_particles_amount;
  particle_t* loaded_particles_arr;
} ingame_data_t;

ingame_data_t* ingame_init();
void ingame_destroy(ingame_data_t* ingame_data);
void ingame_update(ingame_data_t* ingame_data); // TODO needs input dequeued in this frame


#endif