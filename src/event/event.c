#include "./event.h"

STATUS event_handle() {
  SDL_Event event = {0};

  while(SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return STATUS_INIT_QUIT;
    }
    
    //input_handle();
  }

  return STATUS_NO_EVENT;
}