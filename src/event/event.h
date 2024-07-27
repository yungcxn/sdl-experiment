#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>
#include "../util/primitive.h"

void event_handle(bool* running, uint32_t current_ticks);

#endif 