#ifndef CAM_H
#define CAM_H

#include "../../util/vec.h"
#include "../../util/primitive.h"

typedef enum {
  CAM_NORMAL = 0,
  CAM_DARKNESS,
  CAM_FLASH
} cam_lighting_mode;

/* camera width and height is determined by gfx */
typedef struct {
  bool is_needed;
  bool fixed;
  uint32_t shake_ticks_left;
  byte shake_mod;
  uint32_t lag_ticks_left;
  byte lag_mod;
  vec2f pos;
  
} cam_t;

#endif