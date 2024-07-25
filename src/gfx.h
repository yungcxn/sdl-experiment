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

#define GFX_SPRITE_NONE               -1
#define GFX_SPRITE_GRASS_A            0
#define GFX_SPRITE_GRASS_B            1
#define GFX_SPRITE_GRASS_C            2
#define GFX_SPRITE_GRASS_PATH_V       3
#define GFX_SPRITE_GRASS_PATH_H       4
#define GFX_SPRITE_GRASS_PATH_VTE     5
#define GFX_SPRITE_GRASS_PATH_HRE     6
#define GFX_SPRITE_GRASS_PATH_VBE     7
#define GFX_SPRITE_GRASS_PATH_HLE     8
#define GFX_SPRITE_GRASS_PATH_D1      9
#define GFX_SPRITE_GRASS_PATH_D2      10
#define GFX_SPRITE_GRASS_PATH_D3      11
#define GFX_SPRITE_GRASS_PATH_D4      12
#define GFX_SPRITE_GRASS_SAND_TL      13
#define GFX_SPRITE_GRASS_SAND_L       14
#define GFX_SPRITE_GRASS_SAND_BL      15
#define GFX_SPRITE_GRASS_SAND_T       16
#define GFX_SPRITE_GRASS_SAND         17
#define GFX_SPRITE_GRASS_SAND_B       18
#define GFX_SPRITE_GRASS_SAND_TR      19
#define GFX_SPRITE_GRASS_SAND_R       20
#define GFX_SPRITE_GRASS_SAND_BR      21
#define GFX_SPRITE_GRASS_FLOWER_A     22
#define GFX_SPRITE_GRASS_FLOWER_B     23
#define GFX_SPRITE_GRASS_FLOWER_C     24
#define GFX_SPRITE_WATER_1            25
#define GFX_SPRITE_WATER_2            26
#define GFX_SPRITE_WATER_3            27
#define GFX_SPRITE_WATER_4            28
#define GFX_SPRITE_GRASS_WATER_TL     29
#define GFX_SPRITE_GRASS_WATER_L      30
#define GFX_SPRITE_GRASS_WATER_BL     31
#define GFX_SPRITE_GRASS_WATER_T      32
#define GFX_SPRITE_GRASS_WATER_B      33
#define GFX_SPRITE_GRASS_WATER_TR     34
#define GFX_SPRITE_GRASS_WATER_R      35
#define GFX_SPRITE_GRASS_WATER_BR     36

#define GFX_SPRITE_FLOWER_1           37
#define GFX_SPRITE_FLOWER_2           38
#define GFX_SPRITE_FLOWER_3           39
#define GFX_SPRITE_DUSTBALL_1         40
#define GFX_SPRITE_DUSTBALL_2         41
#define GFX_SPRITE_DUSTBALL_3         42
#define GFX_SPRITE_DUSTBALL_4         43
#define GFX_SPRITE_TREE               44
#define GFX_SPRITE_TREE_PACK_A        45
#define GFX_SPRITE_TREE_PACK_B        46

#define GFX_SPRITE_PRINCESS_IDLE_D    47
#define GFX_SPRITE_PRINCESS_IDLE_U    48
#define GFX_SPRITE_PRINCESS_IDLE_R    49
#define GFX_SPRITE_PRINCESS_IDLE_L    50
#define GFX_SPRITE_CAN_IDLE_D         51
#define GFX_SPRITE_CAN_IDLE_U         52
#define GFX_SPRITE_CAN_IDLE_R         53
#define GFX_SPRITE_CAN_IDLE_L         54


#define GFX_SPRITE_MAX_ID GFX_SPRITE_CAN_IDLE_L

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