#ifndef INPUT_H
#define INPUT_H

#include "../util/primitive.h"
#include <SDL2/SDL.h>

#include "../util/queue.h"


#define INPUT_MAX_QUEUED_STROKES 30
#define INPUT_KEYSTROKE_SAVE_TICK_TIME 2000

/* encodes for one single button it's code and metadata (pressed? angle?) */
typedef uint32_t input_keystroke_t;

typedef struct {
  uint32_t tickstamp;
  input_keystroke_t keystroke;
} input_timestamped_keystroke_t; // type of input_keystroke_queue

typedef queue input_keystroke_queue_t;

input_keystroke_queue_t* input_keystroke_queue_init();
void input_keystroke_queue_destroy(input_keystroke_queue_t* keystroke_queue);

void input_keystroke_queue_timed_clean(input_keystroke_queue_t* keystroke_queue, uint32_t current_ticks);
void input_event_handle(SDL_Event event, uint32_t current_ticks, input_keystroke_queue_t* input_keymap);

#endif 