#ifndef MAP_H
#define MAP_H

#define MAP_BASE_HEIGHT 1

#define MAP_MAX_TILES 200

typedef struct {
  int map_pixel_x; // positioning is top left
  int map_pixel_y;
  int map_pixel_z; // height
  gfx_sprite_id sprite_id;
} map_tile_t; // for environment only!

typedef map_tile_t map_map_t[MAP_MAX_TILES];


#endif