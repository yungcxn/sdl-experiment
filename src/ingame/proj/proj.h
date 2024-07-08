#ifndef PROJ_H
#define PROJ_H

#include "../../util/primitive.h"
#include "../../util/img.h"
#include "../../util/bb.h"

typedef struct {
  int id;

  byte state_amount;
  byte* state_arr; // every item should implement it itself
  img_anim_sprite_ptr* animation_arr;

  bb_t* damage_box; // is collision_box aswell
} proj_t; // projectile

#endif 