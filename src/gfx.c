#include "./gfx.h"

gfx_tool_t g_gfx_tools = {
  .window = NULL,
  .renderer = NULL
};


STATUS gfx_init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return STATUS_SDL;
  }

  g_gfx_tools.window = SDL_CreateWindow("Minimal SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if (g_gfx_tools.window == NULL) {
    SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return STATUS_SDL;
  }

  g_gfx_tools.renderer = SDL_CreateRenderer(g_gfx_tools.window, -1, /*SDL_RENDERER_PRESENTVSYNC | */SDL_RENDERER_ACCELERATED);
  if (g_gfx_tools.renderer == NULL) {
    SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return STATUS_SDL;
  }
  SDL_SetRenderDrawColor(g_gfx_tools.renderer, 0, 0, 0, 255);
  SDL_RenderPresent(g_gfx_tools.renderer);
  //SDL_RenderClear(g_gfx_tools.renderer);
  SDL_RenderSetLogicalSize(g_gfx_tools.renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  return STATUS_SUCCESS;
}


STATUS gfx_destroy() {
  SDL_DestroyRenderer(g_gfx_tools.renderer);
  SDL_DestroyWindow(g_gfx_tools.window);
  SDL_Quit();

  return STATUS_SUCCESS;
}


void gfx_clear() {
  SDL_SetRenderDrawColor(g_gfx_tools.renderer, 255, 255, 255, 255);
  SDL_RenderClear(g_gfx_tools.renderer);  
}


void gfx_draw_rect_a(int x, int y, int w, int h, byte r, byte g, byte b, byte a) {
  SDL_Rect rect = {x,y,w,h};
  SDL_SetRenderDrawColor(g_gfx_tools.renderer, r, g, b, a);
  SDL_RenderDrawRect(g_gfx_tools.renderer, &rect);
}


void gfx_draw_rect(int x, int y, int w, int h, byte r, byte g, byte b) {
  gfx_draw_rect_a(x, y, w, h, r, g, b, 255);
}


void gfx_draw_rect_c(int x, int y, int w, int h, rgba color) {
  gfx_draw_rect_a(x, y, w, h, color.r, color.g, color.b, color.a);
}


void gfx_fill_rect_a(int x, int y, int w, int h, byte r, byte g, byte b, byte a) {
  SDL_Rect rect = {x,y,w,h};
  SDL_SetRenderDrawColor(g_gfx_tools.renderer, r, g, b, a);
  SDL_RenderFillRect(g_gfx_tools.renderer, &rect);
}


void gfx_fill_rect(int x, int y, int w, int h, byte r, byte g, byte b) {
  gfx_fill_rect_a(x, y, w, h, r, g, b, 255);
}


void gfx_fill_rect_c(int x, int y, int w, int h, rgba color) {
  gfx_fill_rect_a(x, y, w, h, color.r, color.g, color.b, color.a);
}


void gfx_draw_point_a(int x, int y, byte r, byte g, byte b, byte a) {
  SDL_SetRenderDrawColor(g_gfx_tools.renderer, r, g, b, a);
  SDL_RenderDrawPoint(g_gfx_tools.renderer, x, y);
}


void gfx_draw_point(int x, int y, byte r, byte g, byte b) {
  gfx_draw_point_a(x, y, r, g, b, 255);
}


void gfx_draw_point_c(int x, int y, rgba color) {
  gfx_draw_point_a(x, y, color.r, color.g, color.b, color.a);
}


void gfx_delay(uint32_t d) {
  SDL_Delay(d);
}


void gfx_commit() {
  SDL_RenderPresent(g_gfx_tools.renderer);
}