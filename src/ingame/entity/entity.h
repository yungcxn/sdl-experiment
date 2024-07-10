#ifndef ENTITY_H
#define ENTITY_H

#include "../../util/img.h"
#include "../../util/bb.h"
#include "../../util/vec.h"

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
  vec3f pos; // this is ideally in the bottom center of the entity
} entity_t;

typedef void* entity_raw_ptr;

#endif