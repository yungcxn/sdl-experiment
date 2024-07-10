#ifndef IMG_H
#define IMG_H

#include "../util/primitive.h"
#include "../util/color.h"
#include "../gfx.h"

/* this will be a non-map-env */
typedef struct {
  int pixel_width;
  int pixel_height;
  c32* line; // one liner, doesn't need to be multidimensional  
} img_sprite;

/* this will be only for the map-env! */
typedef struct {
  c32 map[TILE_WIDTH][TILE_WIDTH]; 
} img_tile;

/* these img_anim_* are just*/
typedef struct {
  int frames;
  img_sprite* frame_arr;
  int* tick_duration_arr;
} img_anim_sprite;

typedef struct {
  int frames;
  img_tile* frame_arr;
  int* tick_duration_arr;
} img_anim_tile;

#endif