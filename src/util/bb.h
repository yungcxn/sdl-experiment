#ifndef BB_H
#define BB_H

#include "./vec.h"

/* this bounding box type as pixel values relative to the loaded sprite */
/* this is usually referenced by pointer since this replicates for many entites/proj/etc. */
typedef struct {
  vec2f i;  // ---->
            // |
  vec2f j;  // V
} bb;

typedef struct {
  vec2f b;
  vec2f i;
  vec2f j;
} biased_bb;

#endif 