#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "../../util/primitive.h"
#include "../../util/vec.h"

#define BASE_ENTITY_NAME_LEN 15

typedef uint32_t entity_id; 

typedef struct {
  entity_id id;
  char name[BASE_ENTITY_NAME_LEN];
  vec3f pos; // this is ideally in the bottom center of the entity
  mat22f collision_box; 
  mat22f alt_collision_box; 
  mat22f hurt_box;
} base_entity_t;


#endif