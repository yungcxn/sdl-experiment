
#include "./anim.h"

// returns whether animation is over
bool anim(gfx_sprite_code_t* var, float* elapsed_timer, float duration, 
          bool reset, uint8_t argc, ...) {

  if (*elapsed_timer < duration)
    return false;

  va_list argptr;
  va_start(argptr, argc);

  gfx_sprite_code_t x = (gfx_sprite_code_t) va_arg(argptr, int);

  if (reset) {
    *var = x;
    va_end(argptr);
    return false;
  }

  for (uint8_t i = 0; i < argc; i++) {
    if (*var == x) {
      if (i == argc - 1) {
        va_end(argptr);
        return true;
      }
      else {
        *var = (gfx_sprite_code_t) va_arg(argptr, int);
        va_end(argptr);
        *elapsed_timer = 0;
        return false;
      }
    }

    x = (gfx_sprite_code_t) va_arg(argptr, int);
  } 

  va_end(argptr);
  return false;
}

void anim_loop(gfx_sprite_code_t* var, float* elapsed_timer, float duration, 
               bool reset, uint8_t argc, ...) {

  if (reset) {
    va_list argptr;
    va_start(argptr, argc);
    *var = (gfx_sprite_code_t) va_arg(argptr, int);
    va_end(argptr);
    return;
  }

  if (*elapsed_timer < duration)
    return;

  /* second part with code duplicates since handling needed to be fast above */

  va_list argptr;
  va_start(argptr, argc);

  gfx_sprite_code_t x = (gfx_sprite_code_t) va_arg(argptr, int);
  gfx_sprite_code_t start = x;

  for (uint8_t i = 1; i < argc; i++) {
    if (*var == x) {
      if (i == argc - 1) {
        *var = start;
        *elapsed_timer = 0;
      }
      else {
        *var = (gfx_sprite_code_t) va_arg(argptr, int);
        *elapsed_timer = 0;
      }

      va_end(argptr);
      return;
    }

    x = (gfx_sprite_code_t) va_arg(argptr, int);
  } 

  va_end(argptr);
}