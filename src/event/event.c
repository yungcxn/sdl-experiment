#include "./event.h"

void event_handle(bool* running, uint32_t current_ticks, event_input_t* input) {
  SDL_Event event = {0};
  const uint8_t* state = SDL_GetKeyboardState(NULL);
  *input = 0;
  while(SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT)
      *running = false;
  }
   
  if (state[SDL_SCANCODE_W]) 
    *input |= EVENT_KEY_UP;
  if (state[SDL_SCANCODE_D])
    *input |= EVENT_KEY_RIGHT;
  if (state[SDL_SCANCODE_S]) 
    *input |= EVENT_KEY_DOWN;
  if (state[SDL_SCANCODE_A]) 
    *input |= EVENT_KEY_LEFT;
  if (state[SDL_SCANCODE_M]) 
    *input |= EVENT_KEY_A;
  if (state[SDL_SCANCODE_N]) 
    *input |= EVENT_KEY_B;
  if (state[SDL_SCANCODE_J]) 
    *input |= EVENT_KEY_X;
  if (state[SDL_SCANCODE_H]) 
    *input |= EVENT_KEY_Y;
  if (state[SDL_SCANCODE_U]) 
    *input |= EVENT_KEY_R;
  if (state[SDL_SCANCODE_Z]) 
    *input |= EVENT_KEY_L;
  if (state[SDL_SCANCODE_I]) 
    *input |= EVENT_KEY_ZR;
  if (state[SDL_SCANCODE_T]) 
    *input |= EVENT_KEY_ZL;
  if (state[SDL_SCANCODE_ESCAPE]) 
    *input |= EVENT_KEY_START;
  if (state[SDL_SCANCODE_SPACE])
    *input |= EVENT_KEY_SELECT;

}