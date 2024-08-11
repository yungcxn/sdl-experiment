#include "./gfx.h"
static SDL_Texture* _gfx_spritesheet_init(SDL_Renderer* renderer) {
  res_handler_spritesheet_t pixels = res_handler_init_spritesheet();

  // Create Palette
  SDL_Color pal[256] = {0}; 
  pal[0] = (SDL_Color) 
    {PALETTE_COLOR_0, PALETTE_COLOR_0, PALETTE_COLOR_0, PALETTE_COLOR_0};
  pal[1] = (SDL_Color) 
    {PALETTE_COLOR_1_R, PALETTE_COLOR_1_G, PALETTE_COLOR_1_B, 0xff};
  pal[2] = (SDL_Color) 
    {PALETTE_COLOR_2_R, PALETTE_COLOR_2_G, PALETTE_COLOR_2_B, 0xff};
  pal[3] = (SDL_Color) 
    {PALETTE_COLOR_3_R, PALETTE_COLOR_3_G, PALETTE_COLOR_3_B, 0xff};
  pal[4] = (SDL_Color) 
    {PALETTE_COLOR_4_R, PALETTE_COLOR_4_G, PALETTE_COLOR_4_B, 0xff};
  pal[5] = (SDL_Color) 
    {PALETTE_COLOR_5_R, PALETTE_COLOR_5_G, PALETTE_COLOR_5_B, 0xff};
  pal[6] = (SDL_Color) 
    {PALETTE_COLOR_6_R, PALETTE_COLOR_6_G, PALETTE_COLOR_6_B, 0xff};
  pal[7] = (SDL_Color) 
    {PALETTE_COLOR_7_R, PALETTE_COLOR_7_G, PALETTE_COLOR_7_B, 0xff};
  pal[8] = (SDL_Color) 
    {PALETTE_COLOR_8_R, PALETTE_COLOR_8_G, PALETTE_COLOR_8_B, 0xff};
  pal[9] = (SDL_Color) 
    {PALETTE_COLOR_9_R, PALETTE_COLOR_9_G, PALETTE_COLOR_9_B, 0xff};
  pal[10] = (SDL_Color) 
    {PALETTE_COLOR_10_R, PALETTE_COLOR_10_G, PALETTE_COLOR_10_B, 0xff};
  pal[11] = (SDL_Color) 
    {PALETTE_COLOR_11_R, PALETTE_COLOR_11_G, PALETTE_COLOR_11_B, 0xff};
  pal[12] = (SDL_Color) 
    {PALETTE_COLOR_12_R, PALETTE_COLOR_12_G, PALETTE_COLOR_12_B, 0xff};
  pal[13] = (SDL_Color) 
    {PALETTE_COLOR_13_R, PALETTE_COLOR_13_G, PALETTE_COLOR_13_B, 0xff};
  pal[14] = (SDL_Color) 
    {PALETTE_COLOR_14_R, PALETTE_COLOR_14_G, PALETTE_COLOR_14_B, 0xff};
  pal[15] = (SDL_Color) 
    {PALETTE_COLOR_15_R, PALETTE_COLOR_15_G, PALETTE_COLOR_15_B, 0xff};
  pal[16] = (SDL_Color) 
    {PALETTE_COLOR_16_R, PALETTE_COLOR_16_G, PALETTE_COLOR_16_B, 0xff};

  // Create SDL_Surface from the pixel data 
  SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(
    pixels.sheet, pixels.width, pixels.height, 8, pixels.width, 0, 0,
    0, 0     
  );

  if (!surface) {
    printf("SDL_CreateRGBSurfaceFrom failed: %s\n", SDL_GetError());
  }

  SDL_SetPaletteColors(surface->format->palette, pal, 0, 256);

  // Create texture from the surface
  SDL_Texture* in = SDL_CreateTextureFromSurface(renderer, surface);

  // Free the surface as it is no longer needed
  SDL_FreeSurface(surface);
  res_handler_destroy_spritesheet(pixels);

  if (!in) {
    printf("SDL_CreateTextureFromSurface failed: %s\n", SDL_GetError());
    return 0;
  }

  SDL_SetTextureBlendMode(in, SDL_BLENDMODE_BLEND);

  return in;
}

#define _reg_sprite(i,x,y) si[i] = (gfx_sprite_info) {x,y,ts,ts}
#define _reg_sprite_c(i,x,y,w,h) si[i] = (gfx_sprite_info) {x,y,w,h}

// TODO: rework with variables
static gfx_sprite_info* _gfx_sprite_info_init() {
  int ts = 16;
  uint16_t sprites = GFX_SPRITE_MAX_ID + 1;
  gfx_sprite_info* si = (gfx_sprite_info*) malloc(sprites 
    * sizeof(gfx_sprite_info));

  int bgy = 0*ts;             // background tiles y pixel-pos
  int envy = bgy+ts*11;        // environment tiles y pixel-pos
  int hudy = envy +ts*11;     // hud tiles y pixel-pos
  int enty = hudy +ts*11;     // entity tiles y pixel-pos

  // HERE SPRITES
  _reg_sprite(GFX_SPRITE_GRASS_A,0,bgy);
  _reg_sprite(GFX_SPRITE_GRASS_B,ts,bgy);
  _reg_sprite(GFX_SPRITE_GRASS_C,ts*2,bgy);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_V,ts*3,bgy);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_H,ts*3,bgy+ts);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_VTE,ts*3,bgy+ts*2);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_HRE,ts*3,bgy+ts*3);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_VBE,ts*3,bgy+ts*4);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_HLE,ts*3,bgy+ts*5);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_D1,ts*4,bgy);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_D2,ts*4,bgy+ts);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_D3,ts*4,bgy+ts*2);
  _reg_sprite(GFX_SPRITE_GRASS_PATH_D4,ts*4,bgy+ts*3);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_TL,ts*5,bgy);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_L,ts*5,bgy+ts);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_BL,ts*5,bgy+ts*2);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_T,ts*6,bgy);
  _reg_sprite(GFX_SPRITE_GRASS_SAND,ts*6,bgy+ts);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_B,ts*6,bgy+ts*2);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_TR,ts*7,bgy);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_R,ts*7,bgy+ts);
  _reg_sprite(GFX_SPRITE_GRASS_SAND_BR,ts*7,bgy+ts*2);
  _reg_sprite(GFX_SPRITE_GRASS_FLOWER_A,ts*8,bgy);
  _reg_sprite(GFX_SPRITE_GRASS_FLOWER_B,ts*8,bgy+ts);
  _reg_sprite(GFX_SPRITE_GRASS_FLOWER_C,ts*8,bgy+ts*2);
  _reg_sprite(GFX_SPRITE_WATER_1,ts*10,bgy+ts);
  _reg_sprite(GFX_SPRITE_WATER_2,ts*10,bgy+ts*2);
  _reg_sprite(GFX_SPRITE_WATER_3,ts*10,bgy+ts*3);
  _reg_sprite(GFX_SPRITE_WATER_4,ts*10,bgy+ts*4);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_TL, ts*9, bgy+ts*3);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_L, ts*9, bgy+ts*4);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_BL, ts*9, bgy+ts*5);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_T, ts*10, bgy);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_B, ts*10, bgy+ts*5);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_TR, ts*11, bgy+ts*3);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_R, ts*11, bgy+ts*4);
  _reg_sprite(GFX_SPRITE_GRASS_WATER_BR, ts*11, bgy+ts*5);

  _reg_sprite_c(GFX_SPRITE_FLOWER_1, 0, envy, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_FLOWER_2, ts, envy, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_FLOWER_3, ts*2, envy, ts, ts*2);
  _reg_sprite(GFX_SPRITE_DUSTBALL_1, ts*3, envy);
  _reg_sprite(GFX_SPRITE_DUSTBALL_2, ts*3, envy+ts);
  _reg_sprite(GFX_SPRITE_DUSTBALL_3, ts*3, envy+ts*2);
  _reg_sprite(GFX_SPRITE_DUSTBALL_4, ts*3, envy+ts*3);
  _reg_sprite_c(GFX_SPRITE_TREE, ts*4, envy, ts*2, ts*4);
  _reg_sprite_c(GFX_SPRITE_TREE_PACK_A, ts*6, envy, ts*2, ts*4);
  _reg_sprite_c(GFX_SPRITE_TREE_PACK_B, ts*8, envy, ts*2, ts*2);

  _reg_sprite_c(GFX_SPRITE_PRINCESS_IDLE_D, 0, enty, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_PRINCESS_IDLE_U, ts, enty, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_PRINCESS_IDLE_R, ts*2, enty, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_PRINCESS_IDLE_L, ts*3, enty, ts, ts*2);
  int playery = enty + ts*2;
  _reg_sprite_c(GFX_SPRITE_CAN_IDLE_D, 0, playery, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_IDLE_D_2, ts, playery, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_IDLE_U, ts*2, playery, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_IDLE_R, ts*3, playery, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_IDLE_L, ts*4, playery, ts, ts*2);
  int playerruny = playery + ts*2;
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_1, 0,      playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_2, ts*1,   playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_3, ts*2,   playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_4, ts*3,   playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_5, ts*4,   playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_D_6, ts*5,   playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_1, ts*6,   playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_2, ts*7,   playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_3, ts*8,   playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_4, ts*9,   playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_5, ts*10,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_U_6, ts*11,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_1, ts*12,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_2, ts*13,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_3, ts*14,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_4, ts*15,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_5, ts*16,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_R_6, ts*17,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_1, ts*18,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_2, ts*19,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_3, ts*20,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_4, ts*21,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_5, ts*22,  playerruny, ts, ts*2);
  _reg_sprite_c(GFX_SPRITE_CAN_RUN_L_6, ts*23,  playerruny, ts, ts*2);

  _reg_sprite(GFX_SPRITE_HEART, 0, hudy);
  _reg_sprite(GFX_SPRITE_HEART_HALF, ts*1, hudy);
  _reg_sprite(GFX_SPRITE_NO_HEART, ts*2, hudy);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_1, 0, hudy+ts);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_2, ts*1, hudy+ts);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_3, ts*2, hudy+ts);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_4, ts*3, hudy+ts);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_HALF_1, 0, hudy+ts*2);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_HALF_2, ts, hudy+ts*2);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_HALF_3, ts*2, hudy+ts*2);
  _reg_sprite(GFX_SPRITE_GOLD_HEART_HALF_4, ts*3, hudy+ts*2);
  _reg_sprite_c(GFX_SPRITE_NO_STAMINA_L, 0, hudy+ts*3, 5, 8);
  _reg_sprite_c(GFX_SPRITE_NO_STAMINA_M, 0+6, hudy+ts*3, 3, 8);
  _reg_sprite_c(GFX_SPRITE_NO_STAMINA_R, 0+10, hudy+ts*3, 5, 8);
  int staminoff = 8;
  _reg_sprite_c(GFX_SPRITE_STAMINA_L, 0, (hudy+ts*3) + staminoff, 5, 8);
  _reg_sprite_c(GFX_SPRITE_STAMINA_M, 0+6, (hudy+ts*3) + staminoff, 3, 8);
  _reg_sprite_c(GFX_SPRITE_STAMINA_R, 0+10, (hudy+ts*3) + staminoff, 5, 8);

  _reg_sprite_c(GFX_SPRITE_SMALL_HEART, ts*4, hudy, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_HEART_HALF, ts*5, hudy, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_NO_HEART, ts*6, hudy, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_1, ts*4, hudy+ts, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_2, ts*5, hudy+ts, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_3, ts*6, hudy+ts, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_4, ts*7, hudy+ts, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_HALF_1, ts*4, hudy+ts*2, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_HALF_2, ts*5, hudy+ts*2, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_HALF_3, ts*6, hudy+ts*2, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_GOLD_HEART_HALF_4, ts*7, hudy+ts*2, 11, 11);
  _reg_sprite_c(GFX_SPRITE_SMALL_NO_STAMINA_L, ts*4, hudy+ts*3, 5, 8);
  _reg_sprite_c(GFX_SPRITE_SMALL_NO_STAMINA_M, ts*4+6, hudy+ts*3, 3, 8);
  _reg_sprite_c(GFX_SPRITE_SMALL_NO_STAMINA_R, ts*4+10, hudy+ts*3, 5, 8);
  _reg_sprite_c(GFX_SPRITE_SMALL_STAMINA_L, ts*4, (hudy+ts*3) + staminoff, 4, 7);
  _reg_sprite_c(GFX_SPRITE_SMALL_STAMINA_M, ts*4+6, (hudy+ts*3) + staminoff, 3, 7);
  _reg_sprite_c(GFX_SPRITE_SMALL_STAMINA_R, ts*4+10, (hudy+ts*3) + staminoff, 4, 7);

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

  t->spritesheet = _gfx_spritesheet_init(t->renderer);
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
  safe_free(t);
  SDL_Quit();
}

void gfx_render_sprite_i(gfx_tool_t* t, gfx_sprite_code_t si_index, int32_t x, 
                         int32_t y) {
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
  SDL_SetRenderDrawColor(t->renderer, PALETTE_COLOR_1_R, PALETTE_COLOR_1_G, 
    PALETTE_COLOR_1_B, 255);
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