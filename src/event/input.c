#include "./input.h"


input_keystroke_queue_t* input_keystroke_queue_init(int size) {
  return queue_init(size);
} 

void input_keystroke_queue_destroy(input_keystroke_queue_t* keystroke_queue) {
  queue_destroy(keystroke_queue);
} 

void input_keystroke_queue_timed_clean(input_keystroke_queue_t* keystroke_queue, uint32_t current_ticks) {

  while(!queue_is_empty(*keystroke_queue)) {
    uint32_t tickstamp = queue_peak(*keystroke_queue) >> 32;
    if (tickstamp < current_ticks - INPUT_KEYSTROKE_SAVE_TICK_TIME) {
      queue_de(keystroke_queue);
    }
  }
}

void input_event_handle(SDL_Event event, uint32_t current_ticks, input_keystroke_queue_t* keystroke_queue){
  // TODONEXT
}