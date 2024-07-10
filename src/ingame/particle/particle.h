#ifndef PARTICLE_H
#define PARTICLE_H

#include "../../util/primitive.h"
#include "../../util/img.h"

typedef struct {
  int id;
  img_anim_sprite* animation;
} particle_t;

#endif