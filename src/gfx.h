#ifndef GFX_H
#define GFX_H

/* Low-level rendering Header */

#include "./util/primitive.h"
#include "./util/color.h"
#include <SDL2/SDL.h>

#define FPS 60.0
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 288
#define TILE_WIDTH 16 

typedef struct {
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* texture;
} gfx_tool_t;

extern gfx_tool_t g_gfx_tools;

STATUS gfx_init();
STATUS gfx_destroy();

void gfx_clear();

void gfx_draw_rect_c(int x, int y, int w, int h, rgba color);
void gfx_draw_rect_a(int x, int y, int w, int h, byte r, byte g, byte b, byte a);
void gfx_draw_rect(int x, int y, int w, int h, byte r, byte g, byte b); 

void gfx_fill_rect_c(int x, int y, int w, int h, rgba color);
void gfx_fill_rect_a(int x, int y, int w, int h, byte r, byte g, byte b, byte a);
void gfx_fill_rect(int x, int y, int w, int h, byte r, byte g, byte b); 

void gfx_draw_point_a(int x, int y, byte r, byte g, byte b, byte a);
void gfx_draw_point_c(int x, int y, rgba color);
void gfx_draw_point(int x, int y, byte r, byte g, byte b); 

void gfx_delay(uint32_t d);
void gfx_commit();

#endif 