#ifndef IMG_H
#define IMG_H

#include "../util/primitive.h"
#include "../util/color.h"
#include "../gfx.h"

#define PIXEL_ENCODING c32

/* this will be a non-map-env */
typedef struct {
  int pixel_width;
  int pixel_height;
  PIXEL_ENCODING* map; // one liner, doesn't need to be multidimensional  
} img_sprite;

/* this will be only for the map-env! */
typedef struct {
  PIXEL_ENCODING map[TILE_WIDTH][TILE_WIDTH]; 
} img_tile;

/* making this so heavy * spam is avoided */
typedef img_tile* img_tile_ptr;
typedef img_sprite* img_sprite_ptr;

/* these img_anim_* are just*/
typedef struct {
  int frames;
  img_sprite_ptr frame_arr;
  int* tick_duration_arr;
} img_anim_sprite;

typedef struct {
  int frames;
  img_tile_ptr frame_arr;
  int* tick_duration_arr;
} img_anim_tile;

typedef img_anim_sprite* img_anim_sprite_ptr;
typedef img_anim_tile* img_anim_tile_ptr;


#endif