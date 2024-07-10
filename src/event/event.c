#include "./event.h"

#include "./input.h"

STATUS event_handle(uint32_t current_ticks, input_keystroke_queue_t* ikq) {
  SDL_Event event = {0};

  STATUS env_status = STATUS_NO_EVENT;

  while(SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT)
      env_status = STATUS_INIT_QUIT;
    else
      input_event_handle(event, current_ticks, ikq);
  }

  return env_status;
}