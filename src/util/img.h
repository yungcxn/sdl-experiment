#ifndef IMG_H
#define IMG_H

#include "../util/primitive.h"
#include "../util/color.h"

#define TILE_WIDTH 16 

/* this will be a non-map-env */
typedef struct {
  uint16_t width;
  uint16_t height;
  c16 pixels[]; // one liner, doesn't need to be multidimensional  
} img_sprite; // var len because of pixels

/* this will be only for the map-env! */
typedef struct {
  c16 pixels[TILE_WIDTH][TILE_WIDTH]; 
} img_tile;

/* these img_anim_* are just*/
typedef struct {
  byte frames;
  img_sprite* frame_arr;
  uint32_t* tick_duration_arr;
} img_anim_sprite;

typedef struct {
  byte frames;
  img_tile* frame_arr;
  uint32_t* tick_duration_arr;
} img_anim_tile;

#endif