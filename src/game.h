#ifndef GAME_H
#define GAME_H

#include "./util/primitive.h"
#include "./gfx.h"
#include "./ingame/ingame.h"
#include "./render.h"
#include "./event/event.h"
#include "./util/time.h"
#include "./util/debug.h"

#define GAME_LAG_TIMEOUT 0.25f

// TODO should be a state machine
typedef enum {
  GAME_STATE_UNDEFINED = 0,
  GAME_STATE_TITLE,
  GAME_STATE_GUI,
  GAME_STATE_CUTSCENE,
  GAME_STATE_INGAME
} game_state_t;

typedef struct {
  game_state_t state;
  ingame_data_t* ingame_data;
  input_keystroke_queue_t* input_keystroke_queue;
  gfx_tool_t* gt;
} game_data_t;

int game_mainloop();

#endif