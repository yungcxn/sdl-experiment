#ifndef CAM_H
#define CAM_H

#include "../../util/vec.h"

/* camera width and height is determined by gfx */
typedef struct {
  bool is_needed;
  bool fixed;
  vec2d pos;
} cam_t;

#endif