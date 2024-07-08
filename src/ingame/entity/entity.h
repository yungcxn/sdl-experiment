#ifndef ENTITY_H
#define ENTITY_H

#include "../../util/img.h"
#include "../../util/bb.h"

#define MAX_ENTITY_NAME 20
#define ENTITY_DEAD 0


typedef enum {
  ENTITY_TYPE_PLAYER = 0,
  ENTITY_TYPE_MONSTER,
  ENTITY_TYPE_FRIEND,
  ENTITY_TYPE_BOSS
} entity_type_t;

typedef struct {
  char name[MAX_ENTITY_NAME];
  entity_type_t type;
  int id;
  int x;
  int y;
  int z;

  bool has_health;
  int health;

  byte state_amount;
  byte* state_arr; // every entity should implement this by himself
  img_anim_sprite_ptr* animation_arr; // should match to state_arr

  bb_t* collision_box;
  bb_t* damage_box;
} entity_t;

typedef void* entity_raw_ptr;

#endif