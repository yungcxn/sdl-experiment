#ifndef GMEM_H
#define GMEM_H

/* Graphical memory handler */
/* malloc's color table     */
/*          sprites         */
/*          tiles           */
/*          font            */

#include <stdint.h>
#include <stdlib.h>
#include "./util/primitive.h"
#include "./util/img.h"
#include "./resource/res.h"
#include "./resource/palette.h"

typedef rgba gmem_c16_table_t[16];

typedef struct {
  uint16_t sprite_table_reference_id;
  img_sprite sprite; // var len
} gmem_sprite_t; // var len because of sprite.pixels

/* what we want for our sprite_table: */
/* width,height,pixels is one unit    */
/* allocated into one big mem chunk   */
typedef void gmem_sprite_table_t;


/* It's important that id and tile/sprite_ptr lie as neighbours! */
typedef struct {
  uint16_t metadata; 
  uint16_t tile_table_reference_id;
  /* This field is later handled to store ground properties */
  img_tile tile;
} gmem_map_tile_t;

typedef gmem_map_tile_t gmem_map_tile_table_t[RES_H_TILE_AMOUNT];


// TODO font


typedef struct {
  gmem_c16_table_t* color_table_ptr;
  gmem_map_tile_table_t* map_tile_table_ptr;
  gmem_sprite_table_t* sprite_table_ptr;
} gmem_ptr_route_t;

gmem_map_tile_table_t* gmem_map_tile_table_init();
gmem_c16_table_t* gmem_c16_table_init();
gmem_sprite_table_t* gmem_sprite_table_init();

void gmem_map_tile_table_destroy(gmem_map_tile_table_t* mtt);
void gmem_c16_table_destroy(gmem_c16_table_t* ct);
void gmem_sprite_table_destroy(gmem_sprite_table_t* st);

gmem_ptr_route_t* gmem_init();
void gmem_destroy(gmem_ptr_route_t* ptr_route);
gmem_sprite_t* gmem_get_sprite_ptr_by_id(uint16_t id);
gmem_map_tile_t* gmem_get_map_tile_ptr_by_id(uint16_t id);


#endif 