#ifndef ANIM_H
#define ANIM_H

#include "../gfx.h"
#include <stdarg.h>

bool anim(gfx_sprite_code_t* var, float* elapsed_timer, float duration, 
          bool reset, uint8_t argc, ...);

void anim_loop(gfx_sprite_code_t* var, float* elapsed_timer, float duration, 
               bool reset, uint8_t argc, ...);

#endif