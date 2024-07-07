#include "./game.h"

STATUS game_setup() {
  return gfx_init();
}

STATUS game_destroy() {
  return gfx_destroy();
}

STATUS game_update() {
  STATUS event_status = event_handle();
  return event_status;
}

STATUS game_mainloop() {
  bool running = true;
  while (running) {
    STATUS game_status = game_update();
    
    if (game_status == STATUS_INIT_QUIT) {
      printf("\nquitting the game...\n");
      running = false;
    }

    render_render();
  }

  return STATUS_SUCCESS;
}