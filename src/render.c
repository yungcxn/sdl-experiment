#include "./render.h"

// TODO: Bad Code!

// called during world render
static void render_player(
  gfx_tool_t* gt, player_t* player, uint16_t camx, uint16_t camy // pixel
) {
  float sprite_realx = player->core.pos.x + player->core.sprite_offset.x;
  float sprite_realy = player->core.pos.y + player->core.sprite_offset.y;
  uint16_t pixelx = (uint16_t) (sprite_realx * 16.0f);
  uint16_t pixely = (uint16_t) (sprite_realy * 16.0f);
  int pixel_offx = pixelx - camx;
  int pixel_offy = pixely - camy;

  if (pixel_offx >= -GFX_SCREEN_WIDTH
    && pixel_offx <= GFX_SCREEN_WIDTH
    && pixel_offy >= -GFX_SCREEN_HEIGHT
    && pixel_offy <= GFX_SCREEN_HEIGHT) {
    if (player->sprite != GFX_SPRITE_NONE) {
      int scr_x = pixel_offx + GFX_SCREEN_WIDTH/2;
      int scr_y = pixel_offy + GFX_SCREEN_HEIGHT/2;
      gfx_render_sprite_i(gt, player->sprite, scr_x, scr_y);
    }
  }
}

static void render_world(
  gfx_tool_t* gt, world_handler_t* world_handler, cam_t* cam
) {
  
  world_world_t world = world_handler->current_loaded_world;

  uint16_t rounded_camx = (uint16_t) (cam->pos.x);
  uint16_t rounded_camy = (uint16_t) (cam->pos.y);
  uint16_t pixel_camx = (uint16_t) (cam->pos.x * 16.0f); 
  uint16_t pixel_camy = (uint16_t) (cam->pos.y * 16.0f); 
  uint8_t pixel_offx = pixel_camx % 16;
  uint8_t pixel_offy = pixel_camy % 16; 
  int starttilex = rounded_camx - GFX_SCREEN_TILES_HOR_H;
  int starttiley = rounded_camy - GFX_SCREEN_TILES_VERT_H;
  int endtilex = starttilex + GFX_SCREEN_TILES_HOR;
  int endtiley = starttiley + GFX_SCREEN_TILES_VERT;
  // draw bg, base, base2, fg 
  if (world.bg != 0) {
    
  }

  if (world.base != 0) {
    // using <= since we want one tile on the right more for offset
    int scr_x = -pixel_offx;
    int scr_y = -pixel_offy;
    for (int j = starttiley; j <= endtiley; j++) {
      for (int i = starttilex; i <= endtilex; i++) {
        // is the selected tile actually in world?
        if (i >= 0 && j >= 0 && i < world.base_tile_width 
          && j < world.base_tile_height) {
          // try to render world
          sprite_code_t target_sprite_code 
            = world.base[j * world.base_tile_width + i];
          if (target_sprite_code != GFX_SPRITE_NONE) {
            gfx_render_sprite_i(gt, target_sprite_code, scr_x, scr_y);
          }
        }
        scr_x += 16;
      }
      scr_y += 16;
      scr_x = -pixel_offx;
    }
  }

  if (world.base2 != 0) {
    
  }

  // rendering player here to be inbetween base2 and fg
  render_player(gt, world_handler->player, pixel_camx, pixel_camy);

  if (world.fg != 0) {
    
  }
}

void render_render(gfx_tool_t* gt, ingame_data_t* ingame_data, float dt) {
  gfx_clear(gt);
  gfx_fill_rect_a(gt, 0, 0, GFX_SCREEN_WIDTH, GFX_SCREEN_HEIGHT,
    PALETTE_BLACK_R, PALETTE_BLACK_G, PALETTE_BLACK_B, 255);

  if (ingame_data->world_handler->current_world_number != 0) 
    render_world(gt, ingame_data->world_handler,
      &(ingame_data->cam));

  gfx_commit(gt);
}