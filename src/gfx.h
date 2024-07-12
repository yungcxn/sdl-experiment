#ifndef GFX_H
#define GFX_H

/* Low-level rendering Header */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./util/primitive.h"
#include "./resource/res.h"

#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 288
#define TILE_WIDTH 16 

typedef struct {
  uint16_t x,y,w,h;
} gfx_sprite_info;

typedef struct {
  SDL_Window* window;
  SDL_Renderer* renderer;
  uint32_t pixels;
  uint32_t* pixel_array; // rgba
  SDL_Texture* spritesheet;
  gfx_sprite_info* si_array; // sprite info array
} gfx_tool_t;

typedef uint16_t gfx_sprite_id;

gfx_tool_t* gfx_init();
void gfx_destroy(gfx_tool_t*);


uint32_t* gfx_pixel_array_init();
void gfx_pixel_array_destroy(uint32_t* pixel_array);

gfx_sprite_info* gfx_sprite_info_init();
void gfx_sprite_info_destroy(gfx_sprite_info* si);


void gfx_clear(gfx_tool_t* t);

void gfx_draw_rect_a(gfx_tool_t* t, int x, int y, int w, int h, byte r, byte g, byte b, byte a);
void gfx_draw_rect(gfx_tool_t* t, int x, int y, int w, int h, byte r, byte g, byte b); 

void gfx_fill_rect_a(gfx_tool_t* t, int x, int y, int w, int h, byte r, byte g, byte b, byte a);
void gfx_fill_rect(gfx_tool_t* t, int x, int y, int w, int h, byte r, byte g, byte b); 


void gfx_draw_point_a(gfx_tool_t* t, int x, int y, byte r, byte g, byte b, byte a);
void gfx_draw_point(gfx_tool_t* t, int x, int y, byte r, byte g, byte b); 

// p = paletted
void gfx_draw_point_c16_split(gfx_tool_t* t, int x, int y, byte ref, byte a);

void gfx_delay(uint32_t d);
void gfx_commit(gfx_tool_t* t);

#endif 