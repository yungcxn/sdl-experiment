#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>
#include "../util/primitive.h"
#include "./input.h"

void event_handle(bool* running, uint32_t current_ticks, input_keystroke_queue_t* ikq);

#endif 