#include "./render.h"

static void render_map(gfx_tool_t* gt, map_map_t* map, cam_t* cam) {
  
  uint16_t rounded_camx = (uint16_t) (cam->pos.x);
  uint16_t rounded_camy = (uint16_t) (cam->pos.y);

  uint16_t pixel_camx = (uint16_t) (cam->pos.x * 16.0f); 
  uint16_t pixel_camy = (uint16_t) (cam->pos.y * 16.0f); 

  uint8_t pixel_offx = pixel_camx % 16;
  uint8_t pixel_offy = pixel_camy % 16; 
  int starttilex = rounded_camx - SCREEN_TILES_HOR_H;
  int starttiley = rounded_camy - SCREEN_TILES_VERT_H;
  int endtilex = starttilex + SCREEN_TILES_HOR;
  int endtiley = starttiley + SCREEN_TILES_VERT;

  // draw bg, base, base2, fg 
  if (map->bg != 0) {
    
  }

  if (map->base != 0) {
    // using <= since we want one tile on the right more for offset
    int scr_x = -pixel_offx;
    int scr_y = -pixel_offy;
    for (int j = starttiley; j <= endtiley; j++) {
      for (int i = starttilex; i <= endtilex; i++) {
        // is the selected tile actually in map?
        bool ipos = i >= 0;
        bool jpos = j >= 0;
        bool i_in_map = i < map->base_tile_width;
        bool j_in_map = j < map->base_tile_height;
        if (ipos && jpos && i_in_map && j_in_map) {
          // try to render map
          map_tile_t target_tile = (map->bg)[j * map->base_tile_width + i];
          gfx_render_sprite_i(gt, target_tile.sprite_id, scr_x, scr_y);
        }
        scr_x += 16;
      }
      scr_y += 16;
    }
  }

  if (map->base2 != 0) {
    
  }

  if (map->fg != 0) {
    
  }
}

void render_render(gfx_tool_t* gt, ingame_data_t* ingame_data, float dt) {
  gfx_clear(gt);
  gfx_fill_rect_a(gt, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 255, 200, 32, 255);

  if (ingame_data->map_handler.current_map_number != 0) 
    render_map(gt, &(ingame_data->map_handler.current_loaded_map),
      &(ingame_data->cam));

  gfx_commit(gt);
}