#ifndef INGAME_H
#define INGAME_H

#include "./entity/player.h"
#include "./world/world.h"
#include "./particle/particle.h" //currently unused
#include "./cam/cam.h"
#include "./gui/hud.h"
#include "../event/event.h"

typedef struct {
  player_t* player; // in world_handler as base_entity_t
  world_handler_t* world_handler;
  cam_t cam;
  event_input_t input;
  hud_t hud;
} ingame_data_t;

ingame_data_t* ingame_init();
void ingame_destroy(ingame_data_t* ingame_data);
void ingame_update(ingame_data_t* ingame_data, event_input_t input, float dt); // TODO needs input dequeued in this frame


#endif