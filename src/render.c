#include "./render.h"

STATUS render_render(gfx_tool_t* gt, float dt) {
  gfx_clear(gt);
  gfx_fill_rect_a(gt, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 255, 200, 32, 255);
  gfx_commit(gt);

  return STATUS_SUCCESS; 
}