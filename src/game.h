#ifndef GAME_H
#define GAME_H

#include "./util/primitive.h"
#include "./gfx.h"
#include "./render.h"
#include "./event/event.h"
#include "./util/time.h"
#include "./ingame/ingame.h"
#include "./util/debug.h"

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
} game_data_t;

STATUS game_setup();
STATUS game_destroy();
STATUS game_update(game_data_t* game_data, uint32_t dt);
STATUS game_mainloop();

#endif