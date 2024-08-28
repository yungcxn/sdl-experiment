#ifndef GAME_H
#define GAME_H

#include "./util/common.h"
#include "./gfx.h"
#include "./ingame/ingame.h"
#include "./event/event.h"


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
  event_controller_t* event_controller;
} game_data_t;

int32_t game_mainloop();

#endif