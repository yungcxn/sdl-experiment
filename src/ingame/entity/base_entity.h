#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "../../util/common.h"
#include "../../util/vec.h"

#define BASE_ENTITY_NAME_LEN 15

typedef uint32_t entity_id; 
typedef uint8_t entity_type;

typedef struct {
  entity_type type;
  entity_id id;
  char name[BASE_ENTITY_NAME_LEN];
  vec2f pos; // this is ideally in the bottom center of the entity
  vec2f sprite_offset;
  mat22f collision_box; 
  mat22f alt_collision_box; 
  mat22f hurt_box;
} base_entity_t;

// TODO: lookup table'd update function

#endif