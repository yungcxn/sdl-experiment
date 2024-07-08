#ifndef GFX_H
#define GFX_H

#include "./util/primitive.h"
#include "./util/color.h"
#include <SDL2/SDL.h>

#define FPS 60.0
#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 224
#define TILE_WIDTH 8 

typedef struct {
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* texture;
} gfx_tool_t;

extern gfx_tool_t g_gfx_tools;

STATUS gfx_init();
STATUS gfx_destroy();

void gfx_clear();

void gfx_draw_rect_c(int x, int y, int w, int h, rgba_t color);
void gfx_draw_rect_a(int x, int y, int w, int h, byte r, byte g, byte b, byte a);
void gfx_draw_rect(int x, int y, int w, int h, byte r, byte g, byte b); 

void gfx_fill_rect_c(int x, int y, int w, int h, rgba_t color);
void gfx_fill_rect_a(int x, int y, int w, int h, byte r, byte g, byte b, byte a);
void gfx_fill_rect(int x, int y, int w, int h, byte r, byte g, byte b); 

void gfx_delay(uint32_t d);
void gfx_commit();

#endif 