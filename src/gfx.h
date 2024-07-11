#ifndef GFX_H
#define GFX_H

/* Low-level rendering Header */

#include <SDL2/SDL.h>
#include "./util/primitive.h"
#include "./util/color.h"
#include "./gmem.h"

#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 288

typedef struct {
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* texture;
  gmem_ptr_route_t* gmem_tools;
} gfx_tool_t;

extern gfx_tool_t g_gfx_tools;

STATUS gfx_init();
STATUS gfx_destroy();

void gfx_clear();

void gfx_draw_rect_a(int x, int y, int w, int h, byte r, byte g, byte b, byte a);
void gfx_draw_rect_rgba(int x, int y, int w, int h, rgba color);
void gfx_draw_rect(int x, int y, int w, int h, byte r, byte g, byte b); 

void gfx_fill_rect_a(int x, int y, int w, int h, byte r, byte g, byte b, byte a);
void gfx_fill_rect_rgba(int x, int y, int w, int h, rgba color);
void gfx_fill_rect(int x, int y, int w, int h, byte r, byte g, byte b); 
void gfx_fill_rect_c16_split(int x, int y, int w, int h,  byte ref, byte a);
void gfx_fill_rect_c16(int x, int y, int w, int h, c16 c);


void gfx_draw_point_a(int x, int y, byte r, byte g, byte b, byte a);
void gfx_draw_point_rgba(int x, int y, rgba color);
void gfx_draw_point(int x, int y, byte r, byte g, byte b); 

// p = paletted
void gfx_draw_point_c16_split(int x, int y, byte ref, byte a);
void gfx_draw_point_c16(int x, int y, c16 c);

void gfx_delay(uint32_t d);
void gfx_commit();

#endif 