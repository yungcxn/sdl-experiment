#include "./gfx.h"

static uint32_t* _gfx_pixel_array_init() {
  uint8_t data[] = {RES_ALL_DATA};
  uint16_t width = RES_ALL_WIDTH;
  uint16_t height = RES_ALL_HEIGHT;

  uint32_t* pixel_array = (uint32_t*) malloc(sizeof(uint32_t) * width * height);

  for (uint16_t j = 0; j < height; j++) {
    for (uint16_t i = 0; i < width; i++) {
      uint32_t translated_color = 0x00000000;
      uint32_t ind = j * width + i;
      uint8_t palette_color_index = data[ind];
      
      switch (palette_color_index) {
        case 0: translated_color = PALETTE_COLOR_0; break;
        case 1: translated_color = PALETTE_COLOR_1; break;
        case 2: translated_color = PALETTE_COLOR_2; break;
        case 3: translated_color = PALETTE_COLOR_3; break;
        case 4: translated_color = PALETTE_COLOR_4; break;
        case 5: translated_color = PALETTE_COLOR_5; break;
        case 6: translated_color = PALETTE_COLOR_6; break;
        case 7: translated_color = PALETTE_COLOR_7; break;
        case 8: translated_color = PALETTE_COLOR_8; break;
        case 9: translated_color = PALETTE_COLOR_9; break;
        case 10: translated_color = PALETTE_COLOR_10; break;
        case 11: translated_color = PALETTE_COLOR_11; break;
        case 12: translated_color = PALETTE_COLOR_12; break;
        case 13: translated_color = PALETTE_COLOR_13; break;
        case 14: translated_color = PALETTE_COLOR_14; break;
        case 15: translated_color = PALETTE_COLOR_15; break;
      }
      pixel_array[ind] = translated_color;
    }
  }

  return pixel_array;
}


static void _gfx_pixel_array_destroy(uint32_t* pixel_array) {
  safe_free(pixel_array);
}

static SDL_Texture* _gfx_spritesheet_init(SDL_Renderer* renderer, uint32_t* rgba_array, int32_t width, int32_t height) {
  // Create SDL_Surface from the pixel data 
  SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(
    rgba_array, 
    width, 
    height, 
    32,     
    width * 4,    
    0xFF000000,    
    0x00FF0000,   
    0x0000FF00,    
    0x000000FF     
  );

  if (!surface) {
    printf("SDL_CreateRGBSurfaceFrom failed: %s\n", SDL_GetError());
  }

  // Create texture from the surface
  SDL_Texture* in = SDL_CreateTextureFromSurface(renderer, surface);

  // Free the surface as it is no longer needed
  SDL_FreeSurface(surface);

  if (!in) {
    printf("SDL_CreateTextureFromSurface failed: %s\n", SDL_GetError());
    return 0;
  }

  return in;
}

#define _reg_sprite(i,x,y) si[i] = (gfx_sprite_info) {x,y,16,16}
#define _reg_sprite_c(i,x,y,w,h) si[i] = (gfx_sprite_info) {x,y,w,h}

// TODO: rework with variables
static gfx_sprite_info* _gfx_sprite_info_init() {
  uint16_t sprites = GFX_SPRITE_MAX_ID + 1;
  gfx_sprite_info* si = (gfx_sprite_info*) malloc(sprites 
    * sizeof(gfx_sprite_info));

  // HERE SPRITES
  _reg_sprite(GFX_SPRITE_GRASS_A,0,0);
  _reg_sprite(GFX_SPRITE_GRASS_B,16,0);
  _reg_sprite(GFX_SPRITE_GRASS_C,32,0);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_V,48,0);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_H,48,16);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_VTE,48,32);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_HRE,48,48);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_VBE,48,64);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_HLE,48,80);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_D1,64,0);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_D2,64,16);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_D3,64,32);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_D4,64,48);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_TL,80,0);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_L,80,16);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_BL,80,32);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_T,96,0);
  _reg_sprite(GFX_SPRITE_GRASS_SAND,96,16);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_B,96,32);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_TR,112,0);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_R,112,16);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_BR,112,32);
  _reg_sprite(GFX_SPRITE_GRASS_FLOWER_A,128,0);
  _reg_sprite(GFX_SPRITE_GRASS_FLOWER_B,128,16);
  _reg_sprite(GFX_SPRITE_GRASS_FLOWER_C,128,32);
  _reg_sprite(GFX_SPRITE_WATER_1,160,16);
  _reg_sprite(GFX_SPRITE_WATER_2,160,32);
  _reg_sprite(GFX_SPRITE_WATER_3,160,48);
  _reg_sprite(GFX_SPRITE_WATER_4,160,64);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_TL, 144, 48);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_L, 144, 64);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_BL, 144, 80);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_T, 160, 0);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_B, 160, 80);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_TR, 176, 48);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_R, 176, 64);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_BR, 176, 80);

  _reg_sprite_c(GFX_SPRITE_FLOWER_1, 0, 112, 16, 32);
  _reg_sprite_c(GFX_SPRITE_FLOWER_2, 16, 112, 16, 32);
  _reg_sprite_c(GFX_SPRITE_FLOWER_3, 32, 112, 16, 32);
  _reg_sprite(GFX_SPRITE_DUSTBALL_1, 48, 112);
  _reg_sprite(GFX_SPRITE_DUSTBALL_2, 48, 128);
  _reg_sprite(GFX_SPRITE_DUSTBALL_3, 48, 144);
  _reg_sprite(GFX_SPRITE_DUSTBALL_4, 48, 160);
  _reg_sprite_c(GFX_SPRITE_TREE, 64, 112, 32, 64);
  _reg_sprite_c(GFX_SPRITE_TREE_PACK_A, 96, 112, 32, 64);
  _reg_sprite_c(GFX_SPRITE_TREE_PACK_B, 128, 112, 32, 32);

  _reg_sprite_c(GFX_SPRITE_PRINCESS_IDLE_D, 0, 208, 16, 32);
  _reg_sprite_c(GFX_SPRITE_PRINCESS_IDLE_U, 16, 208, 16, 32);
  _reg_sprite_c(GFX_SPRITE_PRINCESS_IDLE_R, 32, 208, 16, 32);
  _reg_sprite_c(GFX_SPRITE_PRINCESS_IDLE_L, 48, 208, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_IDLE_D, 0, 240, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_IDLE_D_2, 16, 240, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_IDLE_U, 32, 240, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_IDLE_R, 48, 240, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_IDLE_L, 64, 240, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_1, 0, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_2, 16, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_3, 32, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_4, 48, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_5, 64, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_6, 80, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_1, 96, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_2, 112, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_3, 128, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_4, 144, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_5, 160, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_6, 176, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_1, 192, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_2, 208, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_3, 224, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_4, 240, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_5, 256, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_6, 272, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_1, 288, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_2, 304, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_3, 320, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_4, 336, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_5, 352, 272, 16, 32);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_6, 368, 272, 16, 32);

  _reg_sprite(GFX_SPRITE_HEART, 672, 208);
  _reg_sprite(GFX_SPRITE_HEART_HALF, 688, 208);
  _reg_sprite(GFX_SPRITE_NO_HEART, 704, 208);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_1, 672, 224);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_2, 688, 224);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_3, 704, 224);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_1, 720, 224);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_HALF_1, 672, 240);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_HALF_2, 688, 240);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_HALF_3, 704, 240);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_HALF_1, 720, 240);
  _reg_sprite_c(GFX_SPRITE_NO_STAMINA_L, 672, 256, 5, 8);
  _reg_sprite_c(GFX_SPRITE_NO_STAMINA_M, 678, 256, 3, 8);
  _reg_sprite_c(GFX_SPRITE_NO_STAMINA_R, 682, 256, 5, 8);
  _reg_sprite_c(GFX_SPRITE_STAMINA_L, 672, 264, 5, 8);
  _reg_sprite_c(GFX_SPRITE_STAMINA_M, 678, 264, 3, 8);
  _reg_sprite_c(GFX_SPRITE_STAMINA_R, 682, 264, 5, 8);

  int smalloff = 64;
  _reg_sprite_c(GFX_SPRITE_SMALL_HEART, 672+smalloff, 208, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_HEART_HALF, 688+smalloff, 208, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_NO_HEART, 704+smalloff, 208, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_1, 672+smalloff, 224, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_2, 688+smalloff, 224, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_3, 704+smalloff, 224, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_1, 720+smalloff, 224, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_HALF_1, 672+smalloff, 240, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_HALF_2, 688+smalloff, 240, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_HALF_3, 704+smalloff, 240, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_HALF_1, 720+smalloff, 240, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_NO_STAMINA_L, 672+smalloff, 256, 5, 8);
  _reg_sprite_c(GFX_SPRITE_SMALL_NO_STAMINA_M, 678+smalloff, 256, 3, 8);
  _reg_sprite_c(GFX_SPRITE_SMALL_NO_STAMINA_R, 682+smalloff, 256, 5, 8);
  _reg_sprite_c(GFX_SPRITE_SMALL_STAMINA_L, 672+smalloff, 264, 4, 7);
  _reg_sprite_c(GFX_SPRITE_SMALL_STAMINA_M, 678+smalloff, 264, 3, 7);
  _reg_sprite_c(GFX_SPRITE_SMALL_STAMINA_R, 682+smalloff, 264, 4, 7);

  return si;
}


static void _gfx_sprite_info_destroy(gfx_sprite_info* si) {
  safe_free(si);
}


gfx_tool_t* gfx_init() {

  gfx_tool_t* t = (gfx_tool_t*) malloc(sizeof(gfx_tool_t));

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 0;
  }

  t->window = SDL_CreateWindow("Minimal SDL Example", SDL_WINDOWPOS_UNDEFINED,
   SDL_WINDOWPOS_UNDEFINED, GFX_SCREEN_WIDTH, GFX_SCREEN_HEIGHT,
   SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if (t->window == 0) {
    SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 0;
  }

  t->renderer = SDL_CreateRenderer(t->window, -1,
   /*SDL_RENDERER_PRESENTVSYNC | */SDL_RENDERER_ACCELERATED);

  if (t->renderer == 0) {
    SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return 0;
  }
  
  SDL_RenderSetLogicalSize(t->renderer, GFX_SCREEN_WIDTH, GFX_SCREEN_HEIGHT);
  SDL_RenderSetIntegerScale(t->renderer, 1);

  t->pixel_array = _gfx_pixel_array_init();
  t->spritesheet = _gfx_spritesheet_init(t->renderer, t->pixel_array, RES_ALL_WIDTH, RES_ALL_HEIGHT);
  if(t->spritesheet == 0)
    return 0;

  t->si_array = _gfx_sprite_info_init();

  return t;
}


void gfx_destroy(gfx_tool_t* t) {
  SDL_DestroyRenderer(t->renderer);
  SDL_DestroyWindow(t->window);
  SDL_DestroyTexture(t->spritesheet);
  _gfx_sprite_info_destroy(t->si_array);
  _gfx_pixel_array_destroy(t->pixel_array);
  safe_free(t);
  SDL_Quit();
}

void gfx_render_sprite_i(gfx_tool_t* t, gfx_sprite_code_t si_index, int32_t x, int32_t y) {
    gfx_sprite_info si = t->si_array[si_index];
    SDL_Rect src = { si.x, si.y, si.w, si.h };
    SDL_Rect dest = { x, y, si.w, si.h };
    SDL_RenderCopy(t->renderer, t->spritesheet, &src, &dest);
}

void gfx_render_sprite_xy(gfx_tool_t* t, gfx_sprite_info si, int32_t x, int32_t y) {
    SDL_Rect src = { si.x, si.y, si.w, si.h };
    SDL_Rect dest = { x, y, si.w, si.h };
    SDL_RenderCopy(t->renderer, t->spritesheet, &src, &dest);
}


void gfx_clear(gfx_tool_t* t) {
  SDL_SetRenderDrawColor(t->renderer, 255, 255, 255, 255);
  SDL_RenderClear(t->renderer);  
}


void gfx_draw_rect_a(gfx_tool_t* t, int32_t x, int32_t y, int32_t w, int32_t h,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a) {

  SDL_Rect rect = {x,y,w,h};
  SDL_SetRenderDrawColor(t->renderer, r, g, b, a);
  SDL_RenderDrawRect(t->renderer, &rect);
}


void gfx_draw_rect(gfx_tool_t* t, int32_t x, int32_t y, int32_t w, int32_t h, 
 uint8_t r, uint8_t g, uint8_t b) {

  gfx_draw_rect_a(t, x, y, w, h, r, g, b, 255);
}


void gfx_fill_rect_a(gfx_tool_t* t, int32_t x, int32_t y, int32_t w, int32_t h, 
 uint8_t r, uint8_t g, uint8_t b, uint8_t a) {

  SDL_Rect rect = {x,y,w,h};
  SDL_SetRenderDrawColor(t->renderer, r, g, b, a);
  SDL_RenderFillRect(t->renderer, &rect);
}


void gfx_fill_rect(gfx_tool_t* t, int32_t x, int32_t y, int32_t w, int32_t h,
 uint8_t r, uint8_t g, uint8_t b) {

  gfx_fill_rect_a(t, x, y, w, h, r, g, b, 255);
}



void gfx_draw_point_a(gfx_tool_t* t, int32_t x, int32_t y, 
 uint8_t r, uint8_t g, uint8_t b, uint8_t a) {

  SDL_SetRenderDrawColor(t->renderer, r, g, b, a);
  SDL_RenderDrawPoint(t->renderer, x, y);
}


void gfx_draw_point(gfx_tool_t* t, int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b) {
  gfx_draw_point_a(t, x, y, r, g, b, 255);
}

void gfx_delay(uint32_t d) {
  SDL_Delay(d);
}


void gfx_commit(gfx_tool_t* t) {
  SDL_RenderPresent(t->renderer);
}