#include "./gfx.h"

//TODO no extern!
gfx_tool_t g_gfx_tools = {
  .window = NULL,
  .renderer = NULL
};


void gfx_create_spritesheet(SDL_Texture* in, SDL_Renderer* renderer, uint32_t* rgba_array, int width, int height) {
  // Create SDL_Surface from the pixel data
  SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(
    rgba_array, 
    width, 
    height, 
    32,     
    width * 4,    
    0x000000FF,    
    0x0000FF00,   
    0x00FF0000,    
    0xFF000000     
  );

  if (!surface) {
    printf("SDL_CreateRGBSurfaceFrom failed: %s\n", SDL_GetError());
  }

  // Create texture from the surface
  in = SDL_CreateTextureFromSurface(renderer, surface);

  // Free the surface as it is no longer needed
  SDL_FreeSurface(surface);

  if (!in) {
    printf("SDL_CreateTextureFromSurface failed: %s\n", SDL_GetError());
  }
}

uint32_t* gfx_pixel_array_init() {
  // TODO
  return 0;
}


void gfx_pixel_array_destroy(uint32_t* pixel_array) {
  free(pixel_array);
}


gfx_sprite_info* gfx_sprite_info_init() {
  gfx_sprite_info* si = (gfx_sprite_info*) malloc(sizeof(gfx_sprite_info));

  // HERE SPRITES
  si[0] = (gfx_sprite_info) {0,0,TILE_WIDTH,TILE_WIDTH};
  #define GFX_SPRITE_GRASS_ID 0

  // ...

  return si;
}


void gfx_sprite_info_destroy(gfx_sprite_info* si) {
  free(si);
}


gfx_tool_t* gfx_init() {

  gfx_tool_t* t = (gfx_tool_t*) malloc(sizeof(gfx_tool_t));

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 0;
  }

  t->window = SDL_CreateWindow("Minimal SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if (t->window == 0) {
    SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 0;
  }

  t->renderer = SDL_CreateRenderer(t->window, -1, /*SDL_RENDERER_PRESENTVSYNC | */SDL_RENDERER_ACCELERATED);
  if (t->renderer == 0) {
    SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return 0;
  }
  SDL_SetRenderDrawColor(t->renderer, 0, 0, 0, 255);
  SDL_RenderPresent(t->renderer);
  //SDL_RenderClear(t->renderer);
  SDL_RenderSetLogicalSize(t->renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  t->pixels = RES_SPRITESHEET_PIXELS;
  t->pixel_array = gfx_pixel_array_init();

  // TODO
  gfx_create_spritesheet(t->spritesheet, t->renderer, 0, 0, 0);
  t->si_array = gfx_sprite_info_init();
  

  return t;
}


void gfx_destroy(gfx_tool_t* t) {
  SDL_DestroyRenderer(t->renderer);
  SDL_DestroyWindow(t->window);
  SDL_DestroyTexture(t->spritesheet);
  gfx_sprite_info_destroy(t->si_array);
  gfx_pixel_array_destroy(t->pixel_array);
  free(t);
  SDL_Quit();
}

void gfx_render_sprite_i(gfx_tool_t* t, uint16_t si_index, int x, int y) {
    gfx_sprite_info si = t->si_array[si_index];
    SDL_Rect src = { si.x, si.y, si.w, si.h };
    SDL_Rect dest = { x, y, si.w, si.h };
    SDL_RenderCopy(t->renderer, t->spritesheet, &src, &dest);
}

void gfx_render_sprite_xy(gfx_tool_t* t, gfx_sprite_info si, int x, int y) {
    SDL_Rect src = { si.x, si.y, si.w, si.h };
    SDL_Rect dest = { x, y, si.w, si.h };
    SDL_RenderCopy(t->renderer, t->spritesheet, &src, &dest);
}


void gfx_clear(gfx_tool_t* t) {
  SDL_SetRenderDrawColor(t->renderer, 255, 255, 255, 255);
  SDL_RenderClear(t->renderer);  
}


void gfx_draw_rect_a(gfx_tool_t* t, int x, int y, int w, int h, byte r, byte g, byte b, byte a) {
  SDL_Rect rect = {x,y,w,h};
  SDL_SetRenderDrawColor(t->renderer, r, g, b, a);
  SDL_RenderDrawRect(t->renderer, &rect);
}


void gfx_draw_rect(gfx_tool_t* t, int x, int y, int w, int h, byte r, byte g, byte b) {
  gfx_draw_rect_a(t, x, y, w, h, r, g, b, 255);
}


void gfx_fill_rect_a(gfx_tool_t* t, int x, int y, int w, int h, byte r, byte g, byte b, byte a) {
  SDL_Rect rect = {x,y,w,h};
  SDL_SetRenderDrawColor(t->renderer, r, g, b, a);
  SDL_RenderFillRect(t->renderer, &rect);
}


void gfx_fill_rect(gfx_tool_t* t, int x, int y, int w, int h, byte r, byte g, byte b) {
  gfx_fill_rect_a(t, x, y, w, h, r, g, b, 255);
}



void gfx_draw_point_a(gfx_tool_t* t, int x, int y, byte r, byte g, byte b, byte a) {
  SDL_SetRenderDrawColor(t->renderer, r, g, b, a);
  SDL_RenderDrawPoint(t->renderer, x, y);
}


void gfx_draw_point(gfx_tool_t* t, int x, int y, byte r, byte g, byte b) {
  gfx_draw_point_a(t, x, y, r, g, b, 255);
}

void gfx_delay(uint32_t d) {
  SDL_Delay(d);
}


void gfx_commit(gfx_tool_t* t) {
  SDL_RenderPresent(t->renderer);
}