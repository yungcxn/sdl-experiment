#ifndef GFX_H
#define GFX_H

/* Low-level rendering Header */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdint.h>
#include "./util/common.h"
#include "./resource/res_handler.h"
#include "./resource/palette.h"
#include "./util/vec.h"

#define GFX_SCREEN_WIDTH 256
#define GFX_SCREEN_HEIGHT 144 
#define GFX_SCREEN_TILES_HOR (GFX_SCREEN_WIDTH/16)
#define GFX_SCREEN_TILES_VERT (GFX_SCREEN_HEIGHT/16)
#define GFX_SCREEN_TILES_HOR_H (GFX_SCREEN_TILES_HOR/2)
#define GFX_SCREEN_TILES_VERT_H (GFX_SCREEN_TILES_VERT/2)

#define GFX_SPRITE_NONE               0b1111111111111111
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
#define GFX_SPRITE_CAN_IDLE_D_2       52
#define GFX_SPRITE_CAN_IDLE_U         53
#define GFX_SPRITE_CAN_IDLE_R         54
#define GFX_SPRITE_CAN_IDLE_L         55
#define GFX_SPRITE_CAN_RUN_D_1        56
#define GFX_SPRITE_CAN_RUN_D_2        57
#define GFX_SPRITE_CAN_RUN_D_3        58
#define GFX_SPRITE_CAN_RUN_D_4        59
#define GFX_SPRITE_CAN_RUN_D_5        60
#define GFX_SPRITE_CAN_RUN_D_6        61
#define GFX_SPRITE_CAN_RUN_U_1        62
#define GFX_SPRITE_CAN_RUN_U_2        63
#define GFX_SPRITE_CAN_RUN_U_3        64
#define GFX_SPRITE_CAN_RUN_U_4        65
#define GFX_SPRITE_CAN_RUN_U_5        66
#define GFX_SPRITE_CAN_RUN_U_6        67
#define GFX_SPRITE_CAN_RUN_R_1        68
#define GFX_SPRITE_CAN_RUN_R_2        69
#define GFX_SPRITE_CAN_RUN_R_3        70
#define GFX_SPRITE_CAN_RUN_R_4        71
#define GFX_SPRITE_CAN_RUN_R_5        72
#define GFX_SPRITE_CAN_RUN_R_6        73
#define GFX_SPRITE_CAN_RUN_L_1        74
#define GFX_SPRITE_CAN_RUN_L_2        75
#define GFX_SPRITE_CAN_RUN_L_3        76
#define GFX_SPRITE_CAN_RUN_L_4        77
#define GFX_SPRITE_CAN_RUN_L_5        78
#define GFX_SPRITE_CAN_RUN_L_6        79

#define GFX_SPRITE_HEART              80
#define GFX_SPRITE_HEART_HALF         81
#define GFX_SPRITE_NO_HEART           82
#define GFX_SPRITE_GOLD_HEART_1       83
#define GFX_SPRITE_GOLD_HEART_2       84
#define GFX_SPRITE_GOLD_HEART_3       85
#define GFX_SPRITE_GOLD_HEART_4       86
#define GFX_SPRITE_GOLD_HEART_HALF_1  87
#define GFX_SPRITE_GOLD_HEART_HALF_2  88
#define GFX_SPRITE_GOLD_HEART_HALF_3  89
#define GFX_SPRITE_GOLD_HEART_HALF_4  90
#define GFX_SPRITE_NO_STAMINA_L       91
#define GFX_SPRITE_NO_STAMINA_M       92
#define GFX_SPRITE_NO_STAMINA_R       93
#define GFX_SPRITE_STAMINA_L          94
#define GFX_SPRITE_STAMINA_M          95
#define GFX_SPRITE_STAMINA_R          96

#define GFX_SPRITE_SMALL_HEART              97
#define GFX_SPRITE_SMALL_HEART_HALF         98
#define GFX_SPRITE_SMALL_NO_HEART           99
#define GFX_SPRITE_SMALL_GOLD_HEART_1       100
#define GFX_SPRITE_SMALL_GOLD_HEART_2       101
#define GFX_SPRITE_SMALL_GOLD_HEART_3       102
#define GFX_SPRITE_SMALL_GOLD_HEART_4       103
#define GFX_SPRITE_SMALL_GOLD_HEART_HALF_1  104
#define GFX_SPRITE_SMALL_GOLD_HEART_HALF_2  105
#define GFX_SPRITE_SMALL_GOLD_HEART_HALF_3  106
#define GFX_SPRITE_SMALL_GOLD_HEART_HALF_4  107
#define GFX_SPRITE_SMALL_NO_STAMINA_L       108
#define GFX_SPRITE_SMALL_NO_STAMINA_M       109
#define GFX_SPRITE_SMALL_NO_STAMINA_R       110
#define GFX_SPRITE_SMALL_STAMINA_L          111
#define GFX_SPRITE_SMALL_STAMINA_M          112
#define GFX_SPRITE_SMALL_STAMINA_R          113

#define GFX_SPRITE_MAX_ID GFX_SPRITE_SMALL_STAMINA_R

typedef uint16_t gfx_sprite_code_t;

typedef struct {
  uint16_t x,y,w,h;
} gfx_sprite_info;

typedef struct {
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* spritesheet;
  gfx_sprite_info* si_array; // sprite info array
} gfx_tool_t;

gfx_tool_t* gfx_init();
void gfx_destroy(gfx_tool_t*);
void gfx_clear(gfx_tool_t* t);
void gfx_draw_rect_a(gfx_tool_t* t, int32_t x, int32_t y, int32_t w, int32_t h,
                     uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void gfx_draw_rect(gfx_tool_t* t, int32_t x, int32_t y, int32_t w, int32_t h,
                   uint8_t r, uint8_t g, uint8_t b); 
void gfx_fill_rect_a(gfx_tool_t* t, int32_t x, int32_t y, int32_t w, int32_t h,
                     uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void gfx_fill_rect(gfx_tool_t* t, int32_t x, int32_t y, int32_t w, int32_t h, 
                   uint8_t r, uint8_t g, uint8_t b); 
void gfx_draw_point_a(gfx_tool_t* t, int32_t x, int32_t y, 
                      uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void gfx_draw_point(gfx_tool_t* t, int32_t x, int32_t y, 
                    uint8_t r, uint8_t g, uint8_t b); 
// p = paletted
void gfx_draw_point_c16_split(gfx_tool_t* t, int32_t x, int32_t y, 
                              uint8_t ref, uint8_t a);
void gfx_render_sprite_i(gfx_tool_t* t, uint16_t si_index, int32_t x, int32_t y);
void gfx_render_sprite_xy(gfx_tool_t* t, gfx_sprite_info si, 
                          int32_t x, int32_t y);

void gfx_delay(uint32_t d);
void gfx_commit(gfx_tool_t* t);

#endif 