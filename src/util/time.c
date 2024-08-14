#include "./time.h"

#include <stdint.h>

uint32_t time_get_ticks() {
  return SDL_GetTicks();
}