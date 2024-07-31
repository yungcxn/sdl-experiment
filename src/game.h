#ifndef GAME_H
#define GAME_H

#include "./util/primitive.h"
#include "./gfx.h"
#include "./ingame/ingame.h"
#include "./ingame/world/world.h"
#include "./render.h"
#include "./event/event.h"
#include "./util/time.h"
#include "./util/debug.h"

#define GAME_LAG_TIMEOUT 0.25f

#define GAME_STATE_UNDEFINED 0
#define GAME_STATE_TITLE 1
#define GAME_STATE_GUI 2
#define GAME_STATE_CUTSCENE 3
#define GAME_STATE_INGAME 4

typedef struct {
  uint8_t state;
  ingame_data_t* ingame_data;
  gfx_tool_t* gt;
  event_input_t input;
} game_data_t;

int32_t game_mainloop();

#endif