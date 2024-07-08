#include "./time.h"
#include <stdint.h> // linter ... :(

uint32_t time_get_ticks() {
  return SDL_GetTicks();
}