#ifndef BB_H
#define BB_H

#include "./vec.h"

/* this bounding box type as pixel values relative to the loaded sprite */
/* this is usually referenced by pointer since this replicates for many entites/proj/etc. */
typedef struct {
  vec2d i;  // ---->
            // |
  vec2d j;  // V
} bb;

typedef struct {
  vec2d b_i;
  vec2d i;
  vec2d b_j;
  vec2d j;
} biased_bb;

#endif 