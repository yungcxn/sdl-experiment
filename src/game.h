#ifndef GAME_H
#define GAME_H

#include "./util/primitive.h"
#include "./gfx.h"
#include "./render.h"
#include "./event/event.h"

STATUS game_setup();
STATUS game_destroy();
STATUS game_update();
STATUS game_mainloop();

#endif