#ifndef ENTITY_H
#define ENTITY_H

#include "../../util/img.h"

typedef struct {
  char name[10];
  int id;
  int x;
  int y;
  int z;
  byte state_amount;
  byte* state_arr; // every entity should implement this by himself
  img_anim_sprite_ptr* animation_arr; // should match to state_arr
} entity_t;

#endif