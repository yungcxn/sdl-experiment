#include "./event.h"


void event_handle(bool* running, event_input_t* input,
                  event_controller_t** event_controller) {
  SDL_Event event = {0};
  const uint8_t* state = SDL_GetKeyboardState(NULL);
  *input = 0;
  while(SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      SDL_GameControllerClose(*event_controller);
      *event_controller = 0;
      *running = false;
    } else if (event.type == SDL_CONTROLLERDEVICEADDED) {
      if (*event_controller) {
        SDL_GameControllerClose(*event_controller);
        DEBUG_PRINTF("removed controller");
      }

      *event_controller = SDL_GameControllerOpen(event.cdevice.which);
      if (!(*event_controller)) {
        DEBUG_PRINTF("error adding controller");
      } 

      DEBUG_PRINTF("added controller");
    } else if (event.type == SDL_CONTROLLERDEVICEREMOVED) {
      if (SDL_GameControllerFromInstanceID(event.cdevice.which) 
          != *event_controller) return;
         
      SDL_GameControllerClose(*event_controller);
      *event_controller = 0;
      DEBUG_PRINTF("removed controller");
    }
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

  // if controller is not connected
  if (!(*event_controller)) return;

  if (SDL_GameControllerGetButton(*event_controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
    *input |= EVENT_KEY_UP;
  
  if (SDL_GameControllerGetButton(*event_controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT))
    *input |= EVENT_KEY_RIGHT;

  if (SDL_GameControllerGetButton(*event_controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN))
    *input |= EVENT_KEY_DOWN;

  if (SDL_GameControllerGetButton(*event_controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT))
    *input |= EVENT_KEY_LEFT;

  if (SDL_GameControllerGetButton(*event_controller, SDL_CONTROLLER_BUTTON_A))
    *input |= EVENT_KEY_A;

  if (SDL_GameControllerGetButton(*event_controller, SDL_CONTROLLER_BUTTON_B))
    *input |= EVENT_KEY_B;

  if (SDL_GameControllerGetButton(*event_controller, SDL_CONTROLLER_BUTTON_Y))
    *input |= EVENT_KEY_Y;

  if (SDL_GameControllerGetButton(*event_controller, SDL_CONTROLLER_BUTTON_X))
    *input |= EVENT_KEY_X;

  if (SDL_GameControllerGetButton(*event_controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER))
    *input |= EVENT_KEY_R;

  if (SDL_GameControllerGetButton(*event_controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER))
    *input |= EVENT_KEY_L;

  if (SDL_GameControllerGetAxis(*event_controller, SDL_CONTROLLER_AXIS_TRIGGERRIGHT))
    *input |= EVENT_KEY_ZR;

  if (SDL_GameControllerGetAxis(*event_controller, SDL_CONTROLLER_AXIS_TRIGGERLEFT))
    *input |= EVENT_KEY_ZL;

}