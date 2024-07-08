#ifndef BB_H
#define BB_H

#include "./vec.h"

/* this bounding box type as pixel values relative to the loaded sprite */
/* this is usually referenced by pointer since this replicates for many entites/proj/etc. */
typedef struct {
  vec2d_t i;  // ---->
              // |
  vec2d_t j;  // V
} bb_t;

#endif 