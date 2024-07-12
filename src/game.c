#include "./game.h"

STATUS game_update(game_data_t* game_data, float dt) {
  STATUS event_status = event_handle();
  return event_status;
}

STATUS game_mainloop() {

  game_data_t* game_data = (game_data_t*) malloc(sizeof(game_data_t));
  game_data->state = GAME_STATE_UNDEFINED;
  game_data->gt = gfx_init();
  // game_data->ingame_data = ingame_init(); TODO
  game_data->input_keystroke_queue = input_keystroke_queue_init();

  bool running = true;
  uint32_t current_ticks = time_get_ticks();
  float dt = 0.0f;

  debug_reset_fps_count();
  debug_joystick_count();
  
  while (running) {
    /* PRE */
    dt = (time_get_ticks() - current_ticks) / 1000.0f;
    current_ticks = time_get_ticks();

    debug_update_current_time();

    /* IN */
    STATUS game_status = game_update(game_data, dt);
    
    if (game_status == STATUS_INIT_QUIT) {
      printf("\nquitting the game...\n");
      running = false;
    }

    render_render(game_data->gt, dt);

    /* POST */
    debug_calc_and_print_fps();
  }

  // ingame_destroy(game_data->ingame_data); TODO
  input_keystroke_queue_destroy(game_data->input_keystroke_queue);
  gfx_destroy(game_data->gt);
  free(game_data);

  return STATUS_SUCCESS;
}