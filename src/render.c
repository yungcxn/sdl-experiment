#include "./render.h"

STATUS render_render() {
  gfx_clear();
  gfx_fill_rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0);
  gfx_draw_rect(10, 10, 20, 20, 0, 255, 255);
  gfx_commit();

  return STATUS_SUCCESS; 
}