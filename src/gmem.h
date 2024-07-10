#ifndef GMEM_H
#define GMEM_H

/* Graphical memory handler */
/* malloc's color table     */
/*          sprites         */
/*          tiles           */
/*          font            */

#include <stdint.h>
#include "./util/primitive.h"
#include "./util/img.h"
#include "./resource/res.h"


/* It's important that id and tile/sprite_ptr lie as neighbours! */

typedef struct {
  uint16_t metadata; 
  uint16_t tile_table_reference_id;
  /* This field is later handled to store ground properties */
  img_tile tile;
} gmem_map_tile_t;

typedef struct {
  uint16_t sprite_table_reference_id;
  img_sprite* sprite_ptr;
} gmem_indexed_sprite_t;

typedef rgb gmem_color_table_t[32];

/* IDEA: needs optimization                  */
/* since objects live abroad from each other */
typedef gmem_indexed_sprite_t gmem_sprite_table_t[RES_H_SPRITE_AMOUNT];

typedef gmem_map_tile_t gmem_tile_table_t[RES_H_TILE_AMOUNT];

typedef struct {
  gmem_color_table_t* color_table_ptr;
  gmem_map_tile_t* map_tile_ptr;
} gmem_ptr_route_t;

// TODO font

gmem_ptr_route_t* gmem_init();
void gmem_destroy(gmem_ptr_route_t* ptr_route);

#endif 