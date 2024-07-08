#ifndef INGAME_H
#define IMGAME_H

#include "./entity/entity.h"
#include "./entity/player.h"
#include "./map/map.h"
#include "./particle/particle.h"

typedef struct {
  player_t player_ref;
  map_map_t loaded_map;
  int loaded_entities_amount;
  /* this is encapsulated in another pointer to   */
  /* 1. reference the mem block                   */
  /* 2. cast based on the enum what the entity is */
  entity_raw_ptr* loaded_entities_arr;

  int loaded_particles_amount;
  particle_t* loaded_particles_arr;
} ingame_data_t;

void ingame_init(ingame_data_t** ingame_data);
void ingame_destroy(ingame_data_t** ingame_data);
void ingame_update(ingame_data_t* ingame_data);

#endif