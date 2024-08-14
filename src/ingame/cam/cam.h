#ifndef CAM_H
#define CAM_H

#include "../../util/vec.h"
#include "../../util/common.h"
#include "../../util/debug.h"

#define CAM_FIXED_FLAG     0b00000010
#define CAM_ACTIVATED_FLAG 0b00000001
#define CAM_DIST_PER_SEC (1.0f/16.0f * 1.0f)

typedef enum {
  CAM_NORMAL = 0,
  CAM_DARKNESS,
  CAM_FLASH
} cam_lighting_mode;

/* camera width and height is determined by gfx */
typedef struct {
  vec2f pos;
  float move_elapsed_ticks;
  uint8_t flags;
  uint32_t shake_ticks_left;
  uint8_t shake_mod;
  uint32_t freeze_ticks_left;
  uint8_t freeze_mod;
} cam_t;

void cam_move_clean(cam_t* cam, vec2f dest, float dt);

#endif