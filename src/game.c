#include "./game.h"

STATUS game_setup() {
  return gfx_init();
}

STATUS game_destroy() {


  return gfx_destroy();
}

STATUS game_update(game_data_t* game_data, uint32_t dt) {
  STATUS event_status = event_handle();
  return event_status;
}

STATUS game_mainloop() {

  game_data_t* game_data = (game_data_t*) malloc(sizeof(game_data_t));
  game_data->state = GAME_STATE_UNDEFINED;

  bool running = true;
  uint32_t current_ticks = time_get_ticks();
  uint32_t dt = 0;

  debug_reset_fps_count();
  
  while (running) {
    /* PRE */
    dt = time_get_ticks() - current_ticks;
    current_ticks = time_get_ticks();

    debug_update_current_time();

    /* IN */
    STATUS game_status = game_update(game_data, dt);
    
    if (game_status == STATUS_INIT_QUIT) {
      printf("\nquitting the game...\n");
      running = false;
    }

    render_render(dt);

    /* POST */
    debug_calc_and_print_fps();
  }

  free(game_data);
  game_data = NULL;

  return STATUS_SUCCESS;
}