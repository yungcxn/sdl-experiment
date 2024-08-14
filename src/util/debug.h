#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG_GAME
#include <stdint.h>


#ifdef DEBUG_GAME
    #define debug_printf(fmt, ...)                                         \
    fprintf(stderr, "%s:%d - %s(): " fmt "\n", __FILE__, __LINE__, __func__, \
            ##__VA_ARGS__)
#else
    #define debug_printf(fmt, ...) ((void)0)
#endif

extern uint32_t debug_start_time;
extern int32_t debug_frames_per_sec;
extern uint32_t debug_current_time;
#endif

void debug_reset_fps_count();
void debug_update_current_time();
void debug_calc_and_print_fps();
void debug_joystick_count();


#endif 
