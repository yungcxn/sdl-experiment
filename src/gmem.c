#include "./gmem.h"

gmem_c16_table_t* gmem_c16_table_init() {
  gmem_c16_table_t* cmt = (gmem_c16_table_t*) malloc(sizeof(gmem_c16_table_t));

  (*cmt)[0] = rgba_from_hex(PALETTE_COLOR_0);
  (*cmt)[0] = rgba_from_hex(PALETTE_COLOR_1);
  (*cmt)[2] = rgba_from_hex(PALETTE_COLOR_2);
  (*cmt)[3] = rgba_from_hex(PALETTE_COLOR_3);
  (*cmt)[4] = rgba_from_hex(PALETTE_COLOR_4);
  (*cmt)[5] = rgba_from_hex(PALETTE_COLOR_5);
  (*cmt)[6] = rgba_from_hex(PALETTE_COLOR_6);
  (*cmt)[7] = rgba_from_hex(PALETTE_COLOR_7);
  (*cmt)[8] = rgba_from_hex(PALETTE_COLOR_8);
  (*cmt)[9] = rgba_from_hex(PALETTE_COLOR_9);
  (*cmt)[10] = rgba_from_hex(PALETTE_COLOR_10);
  (*cmt)[11] = rgba_from_hex(PALETTE_COLOR_11);
  (*cmt)[12] = rgba_from_hex(PALETTE_COLOR_12);
  (*cmt)[13] = rgba_from_hex(PALETTE_COLOR_13);
  (*cmt)[14] = rgba_from_hex(PALETTE_COLOR_14);
  (*cmt)[15] = rgba_from_hex(PALETTE_COLOR_15);

  return cmt;
}


void gmem_c16_table_destroy (gmem_c16_table_t* cmt) {
  free(cmt);
}

gmem_map_tile_table_t* gmem_map_tile_table_init() {
  return 0; //TODO
}


gmem_sprite_table_t* gmem_sprite_table_init() {
  return 0; //TODO
}

void gmem_map_tile_table_destroy(gmem_map_tile_table_t* mtt) {

}


void gmem_sprite_table_destroy(gmem_sprite_table_t* st) {

}


gmem_ptr_route_t* gmem_init() {
  gmem_ptr_route_t* ptr_route = (gmem_ptr_route_t*) malloc(sizeof(gmem_ptr_route_t));
  ptr_route->color_table_ptr = gmem_c16_table_init();
  ptr_route->map_tile_table_ptr = gmem_map_tile_table_init();
  ptr_route->sprite_table_ptr = gmem_sprite_table_init();
  return ptr_route;
}


void gmem_destroy(gmem_ptr_route_t* ptr_route) {
  gmem_c16_table_destroy(ptr_route->color_table_ptr);
  gmem_map_tile_table_destroy(ptr_route->map_tile_table_ptr);
  gmem_sprite_table_destroy(ptr_route->sprite_table_ptr);
  free(ptr_route);
}