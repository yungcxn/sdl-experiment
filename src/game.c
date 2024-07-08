#include "./game.h"

STATUS game_setup() {
  return gfx_init();
}

STATUS game_destroy() {


  return gfx_destroy();
}

STATUS game_update(game_data_t* game_data) {
  STATUS event_status = event_handle();
  return event_status;
}

STATUS game_mainloop() {

  game_data_t* game_data = (game_data_t*) malloc(sizeof(game_data_t));
  game_data->state = GAME_STATE_UNDEFINED;

  bool running = true;

  /* for fps calculation */
  #ifdef DEBUG_GAME
    uint32_t start_time = time_get_ticks();
    int frames_per_sec = 0;
  #endif
  
  while (running) {
    /* PRE */
    #ifdef DEBUG_GAME
      uint32_t current_time = time_get_ticks();
    #endif

    /* IN */
    STATUS game_status = game_update(game_data);
    
    if (game_status == STATUS_INIT_QUIT) {
      printf("\nquitting the game...\n");
      running = false;
    }

    render_render();

    /* POST */
    #ifdef DEBUG_GAME
      frames_per_sec++;
      if (current_time - start_time >= 1000) {
        float fps = frames_per_sec / ((current_time - start_time) / 1000.0f);
        printf("FPS: %.2f\n", fps);
        start_time = current_time;
        frames_per_sec = 0;
      }
    #endif

  }

  free(game_data);
  game_data = NULL;

  return STATUS_SUCCESS;
}