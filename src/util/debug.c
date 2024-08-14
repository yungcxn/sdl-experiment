#ifdef DEBUG_GAME

#include "./debug.h"

#include "./time.h"
#include <stdio.h>
#include <SDL2/SDL.h>

uint32_t debug_start_time = 0;
int32_t debug_frames_per_sec = 0;
uint32_t debug_current_time = 0;
#endif


void debug_reset_fps_count() {
  #ifdef DEBUG_GAME
  debug_start_time = time_get_ticks();
  debug_frames_per_sec = 0;
  #endif
}


void debug_update_current_time() {
  #ifdef DEBUG_GAME
  debug_current_time = time_get_ticks();
  #endif
}


void debug_calc_and_print_fps() {
  #ifdef DEBUG_GAME
  debug_frames_per_sec++;
  if (debug_current_time - debug_start_time >= 1000) {
    float fps = debug_frames_per_sec / ((debug_current_time - debug_start_time) / 1000.0f);
    printf("FPS: %.2f\n", fps);
    debug_start_time = debug_current_time;
    debug_frames_per_sec = 0;
  }
  #endif
}


void debug_joystick_count() {
  #ifdef DEBUG_GAME
  debug_printf("%i joysticks were found.\n", SDL_NumJoysticks());
  #endif
}