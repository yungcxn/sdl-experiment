#include "./render.h"

STATUS render_render(float dt) {
  gfx_clear();
  //gfx_fill_rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0);
  //gfx_draw_rect(10, 10, 20, 20, 0, 255, 255);
  //gfx_draw_point(SCREEN_WIDTH-1,SCREEN_HEIGHT-1,255,0,0);
  gfx_fill_rect_c16(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0b00011111);
  gfx_commit();

  return STATUS_SUCCESS; 
}