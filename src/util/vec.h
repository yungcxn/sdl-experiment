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

vec2f vec2f_normalized(vec2f v);
vec3f vec3f_normalized(vec3f v);

#endif 