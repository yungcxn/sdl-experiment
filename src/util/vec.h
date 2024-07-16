#ifndef VEC_H
#define VEC_H

#include "./math.h"

typedef struct{
  float x,y;
} vec2f;

typedef struct{
  vec2f b, v; //bias vec, value v
} mat22f;

typedef struct{
  float x,y,z;
} vec3f;

// TODO export

#endif 