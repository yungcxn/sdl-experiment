#include "./map.h"


static void map_load_overworld(map_handler_t* map_handler) {
  // gotta alloc base1, base2, fg, bg
  map_handler->current_loaded_map.base_tile_height = 100;
  map_handler->current_loaded_map.base_tile_width = 100;

  uint32_t size = map_handler->current_loaded_map.base_tile_height 
      * map_handler->current_loaded_map.base_tile_width;

  map_handler->current_loaded_map.base 
    = (uint16_t*) malloc(size * sizeof(uint16_t));

  for(uint32_t x = 0; x < size; x++)
    (map_handler->current_loaded_map.base)[x] = 0;
  
  (map_handler->current_loaded_map.base)[49 + 100 * 49] 
    = 3;

  map_handler->current_map_number = MAP_OVERWORLD_ID;
}


map_handler_t* map_handler_init() {
  map_handler_t* map_handler = (map_handler_t*) malloc(sizeof(map_handler_t));
  map_handler->current_loaded_map = (map_map_t) {0,0,0,0,0,0,0,0,0};
  map_handler->current_map_number = 0;
  return map_handler;
}


void map_handler_destroy(map_handler_t* map_handler) {
  safe_free(map_handler->current_loaded_map.base);
  safe_free(map_handler->current_loaded_map.base2);
  safe_free(map_handler->current_loaded_map.fg);
  safe_free(map_handler->current_loaded_map.bg);
  safe_free(map_handler);
}


void map_load_map(map_handler_t* map_handler, uint16_t map_number) {

  if (map_number == map_handler->current_map_number) 
    return; // never load unnecessary

  if (map_handler->current_map_number != 0) {
    // unload map

    //..
    if (map_handler->current_loaded_map.base != 0)
      safe_free(map_handler->current_loaded_map.base);

    if (map_handler->current_loaded_map.base2 != 0)
      safe_free(map_handler->current_loaded_map.base2);

    if (map_handler->current_loaded_map.fg != 0)
      safe_free(map_handler->current_loaded_map.fg);

    if (map_handler->current_loaded_map.bg != 0)
      safe_free(map_handler->current_loaded_map.bg);  
    
  } 

  if (map_number == MAP_OVERWORLD_ID) {
    map_load_overworld(map_handler);
  }
}