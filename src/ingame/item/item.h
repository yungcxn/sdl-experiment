#ifndef ITEM_H
#define ITEM_H

#define MAX_ITEM_NAME 10
#include "../../util/primitive.h"
#include "../../util/img.h"

typedef struct {
  char name[MAX_ITEM_NAME];
  int id;
  img_anim_sprite_ptr icon_animation;

  byte state_amount;
  byte* state_arr; // every item should implement it itself
  img_anim_sprite_ptr* animation_arr;
} item_t;

#endif 