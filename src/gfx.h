#ifndef GFX_H
#define GFX_H

/* Low-level rendering Header */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdint.h>
#include "./util/primitive.h"
#include "./resource/res.h"
#include "./resource/palette.h"

#define GFX_SCREEN_WIDTH 512 // 32 tiles
#define GFX_SCREEN_HEIGHT 288 // 18
#define GFX_SCREEN_TILES_HOR 32
#define GFX_SCREEN_TILES_VERT 18
#define GFX_SCREEN_TILES_HOR_H 16
#define GFX_SCREEN_TILES_VERT_H 9

#define GFX_SPRITE_NONE -1
#define GFX_SPRITE_GRASS_A 0
#define GFX_SPRITE_GRASS_B 1
#define GFX_SPRITE_GRASS_C 2

typedef uint16_t sprite_code_t;

typedef struct {
  uint16_t x,y,w,h;
} gfx_sprite_info;

typedef struct {
  SDL_Window* window;
  SDL_Renderer* renderer;
  uint32_t* pixel_array; // rgba
  SDL_Texture* spritesheet;
  gfx_sprite_info* si_array; // sprite info array
} gfx_tool_t;

gfx_tool_t* gfx_init();
void gfx_destroy(gfx_tool_t*);
void gfx_clear(gfx_tool_t* t);
void gfx_draw_rect_a(gfx_tool_t* t, int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void gfx_draw_rect(gfx_tool_t* t, int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b); 
void gfx_fill_rect_a(gfx_tool_t* t, int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void gfx_fill_rect(gfx_tool_t* t, int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b); 
void gfx_draw_point_a(gfx_tool_t* t, int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void gfx_draw_point(gfx_tool_t* t, int x, int y, uint8_t r, uint8_t g, uint8_t b); 
// p = paletted
void gfx_draw_point_c16_split(gfx_tool_t* t, int x, int y, uint8_t ref, uint8_t a);
void gfx_render_sprite_i(gfx_tool_t* t, uint16_t si_index, int x, int y);
void gfx_render_sprite_xy(gfx_tool_t* t, gfx_sprite_info si, int x, int y);

void gfx_delay(uint32_t d);
void gfx_commit(gfx_tool_t* t);

#endif 