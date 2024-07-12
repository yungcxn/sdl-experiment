#include "./event.h"

#include "./input.h"

void event_handle(bool* running, uint32_t current_ticks, input_keystroke_queue_t* ikq) {
  SDL_Event event = {0};

  while(SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT)
      *running = false;
    else
      input_event_handle(event, current_ticks, ikq);
  }

}