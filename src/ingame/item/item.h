#ifndef ITEM_H
#define ITEM_H

#define MAX_ITEM_NAME 10
#include "../../util/primitive.h"

typedef struct {
  char name[MAX_ITEM_NAME];
  int32_t id;
  //img_anim_sprite* icon_animation;
} item_t;

#endif 