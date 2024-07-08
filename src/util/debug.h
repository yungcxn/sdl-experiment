#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG_GAME
#include "./time.h"
#include <stdint.h>
#include <stdio.h>


extern uint32_t debug_start_time;
extern int debug_frames_per_sec;
extern uint32_t debug_current_time;
#endif

void debug_reset_fps_count();
void debug_update_current_time();
void debug_calc_and_print_fps();


#endif 
