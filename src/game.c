#include "./game.h"

static void game_update(bool* running, game_data_t* game_data, float dt) {
  event_handle(running, dt);

  if ((game_data->state == GAME_STATE_TITLE) || (game_data->state == GAME_STATE_UNDEFINED))
    return;

  ingame_update(game_data->ingame_data);
}


int game_mainloop() {

  game_data_t* game_data = (game_data_t*) malloc(sizeof(game_data_t));
  game_data->state = GAME_STATE_UNDEFINED;
  game_data->gt = gfx_init();

  if (game_data->gt == 0)
    return 0;

  game_data->ingame_data = ingame_init();

  bool running = true;
  uint32_t current_ticks = time_get_ticks();
  float dt = 0.0f;

  debug_reset_fps_count();
  debug_joystick_count();
  // TEST 
  world_load_world(game_data->ingame_data->world_handler, world_OVERWORLD_ID);
  game_data->ingame_data->cam.pos = (vec2f) {100.0f, 100.0f};
  
  while (running) {
    /* PRE */
    dt = (time_get_ticks() - current_ticks) / 1000.0f;
    dt = dt > GAME_LAG_TIMEOUT ? GAME_LAG_TIMEOUT : dt;
    current_ticks = time_get_ticks();

    debug_update_current_time();

    /* IN */
    game_update(&running, game_data, dt);
    render_render(game_data->gt, game_data->ingame_data, dt);

    /* POST */
    debug_calc_and_print_fps();
  }

  ingame_destroy(game_data->ingame_data);
  gfx_destroy(game_data->gt);
  free(game_data);

  return 0;
}