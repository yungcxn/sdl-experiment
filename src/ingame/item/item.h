#ifndef ITEM_H
#define ITEM_H

#define MAX_ITEM_NAME 10
#include "../../util/primitive.h"
#include "../../util/img.h"

typedef struct {
  char name[MAX_ITEM_NAME];
  int id;
  img_anim_sprite* icon_animation;
} item_t;

#endif 