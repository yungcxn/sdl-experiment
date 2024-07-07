#include "./render.h"

STATUS render_render() {
  gfx_clear();
  gfx_draw_rect(10, 10, 20, 20, 0, 255, 255);
  gfx_commit();
  gfx_delay(16);

  return STATUS_SUCCESS; 
}