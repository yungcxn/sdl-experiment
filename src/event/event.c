#include "./event.h"

void event_handle(bool* running, uint32_t current_ticks) {
  SDL_Event event = {0};

  while(SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT)
      *running = false;
    else {}
      
  }

}