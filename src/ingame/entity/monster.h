#ifndef MONSTER_H
#define MONSTER_H

#include "../../util/vec.h"

#define MONSTER_MAX_NAME

typedef struct {
  char name[MONSTER_MAX_NAME];
  int id;
  vec3f pos; // this is ideally in the bottom center of the entity

  vec2f collision_box; // relative to bias
  vec2f collision_box_bias;

  vec2f hurt_box; // relative to bias
  vec2f hurt_box_bias; 

  vec2f alt_collision_box; // relative to bias
  vec2f alt_collision_box_bias;
  vec2f alt_hurt_box; // relative to bias
  vec2f alt_hurt_box_bias;

} monster_t;

#endif