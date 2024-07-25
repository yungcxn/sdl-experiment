#include "./world.h"


static void world_load_overworld(world_handler_t* world_handler) {
  debug_printf("Loading Overworld...\n");
  // gotta alloc base1, base2, fg, bg
  world_handler->current_loaded_world.base_tile_height = 100;
  world_handler->current_loaded_world.base_tile_width = 100;
  uint32_t size = world_handler->current_loaded_world.base_tile_height 
    * world_handler->current_loaded_world.base_tile_width;

  world_handler->current_loaded_world.base 
    = (sprite_code_t*) malloc(size * sizeof(sprite_code_t));

  for(uint32_t x = 0; x < size; x++) {
    (world_handler->current_loaded_world.base)[x] = GFX_SPRITE_GRASS_A;
  }

  (world_handler->current_loaded_world.base)[49 + 100 * 49] = GFX_SPRITE_GRASS_C;
  world_handler->current_world_number = world_OVERWORLD_ID;
}


world_handler_t* world_handler_init(player_t* player) {
  world_handler_t* world_handler = (world_handler_t*) malloc(sizeof(world_handler_t));
  world_handler->current_loaded_world = (world_world_t) {0,0,0,0,0,0,0,0,0};
  world_handler->current_world_number = 0;
  world_handler->player = player;
  return world_handler;
}


void world_handler_destroy(world_handler_t* world_handler) {
  // player is not destroyed here but in ingame :)
  safe_free(world_handler->current_loaded_world.base);
  safe_free(world_handler->current_loaded_world.base2);
  safe_free(world_handler->current_loaded_world.fg);
  safe_free(world_handler->current_loaded_world.bg);
  safe_free(world_handler);
}


void world_load_world(world_handler_t* world_handler, uint16_t world_number) {

  if (world_number == world_handler->current_world_number) 
    return; // never load unnecessary

  if (world_handler->current_world_number != 0) {
    // unload world

    //..
    if (world_handler->current_loaded_world.base != 0) {
      safe_free(world_handler->current_loaded_world.base);
    }
    
    if (world_handler->current_loaded_world.base2 != 0) {
      safe_free(world_handler->current_loaded_world.base2);
    }
 
    if (world_handler->current_loaded_world.fg != 0) {
      safe_free(world_handler->current_loaded_world.fg);
    }

    if (world_handler->current_loaded_world.bg != 0) {
      safe_free(world_handler->current_loaded_world.bg);
    }  
    
  } 

  if (world_number == world_OVERWORLD_ID) {
    world_load_overworld(world_handler);
  }
}