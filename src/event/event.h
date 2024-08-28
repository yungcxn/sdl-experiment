#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>

#include "../util/common.h"
#include "../util/debug.h"

#define EVENT_KEY_UP      0b0000000000000001
#define EVENT_KEY_RIGHT   0b0000000000000010
#define EVENT_KEY_DOWN    0b0000000000000100
#define EVENT_KEY_LEFT    0b0000000000001000
#define EVENT_KEY_A       0b0000000000010000
#define EVENT_KEY_B       0b0000000000100000
#define EVENT_KEY_X       0b0000000001000000
#define EVENT_KEY_Y       0b0000000010000000
#define EVENT_KEY_R       0b0000000100000000
#define EVENT_KEY_L       0b0000001000000000
#define EVENT_KEY_ZR      0b0000010000000000
#define EVENT_KEY_ZL      0b0000100000000000
#define EVENT_KEY_START   0b0001000000000000
#define EVENT_KEY_SELECT  0b0010000000000000
 
// is key down?
#define event_up_down(i)      (i & 0b0000000000000001)
#define event_right_down(i)   (i & 0b0000000000000010)
#define event_down_down(i)    (i & 0b0000000000000100)
#define event_left_down(i)    (i & 0b0000000000001000)
#define event_a_down(i)       (i & 0b0000000000010000)
#define event_b_down(i)       (i & 0b0000000000100000)
#define event_x_down(i)       (i & 0b0000000001000000)
#define event_y_down(i)       (i & 0b0000000010000000)
#define event_r_down(i)       (i & 0b0000000100000000)
#define event_l_down(i)       (i & 0b0000001000000000)
#define event_zr_down(i)      (i & 0b0000010000000000)
#define event_zl_down(i)      (i & 0b0000100000000000)
#define event_start_down(i)   (i & 0b0001000000000000)
#define event_select_down(i)  (i & 0b0010000000000000)

typedef uint16_t event_input_t;
typedef SDL_GameController event_controller_t;

void event_handle(bool* running, event_input_t* input,
                  event_controller_t** event_controller);

#endif 