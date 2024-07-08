#ifndef IMG_H
#define IMG_H

#include "../util/primitive.h"
#include "../util/color.h"
#include "../gfx.h"

/* this will be a non-8x8-image */
typedef struct {
  int pixel_width;
  int pixel_height;
  rgba_t** map; 
} img_sprite_t;


/* this will be a 8x8 image */
typedef struct {
  rgba_t map[TILE_WIDTH][TILE_WIDTH]; 
} img_tile_t;

/* making this so heavy * spam is avoided */
typedef img_tile_t* img_tile_ptr;
typedef img_sprite_t* img_sprite_ptr;

typedef struct {
  int frames;
  img_sprite_t* frame_arr;
  int* tick_duration_arr;
} img_anim_sprite_t;

typedef struct {
  int frames;
  img_tile_t* frame_arr;
  int* tick_duration_arr;
} img_anim_tile_t;

typedef img_anim_sprite_t* img_anim_sprite_ptr;
typedef img_anim_tile_t* img_anim_tile_ptr;


#endif