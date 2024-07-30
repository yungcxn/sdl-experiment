#include "./render.h"

// TODO: Bad Code!

static inline void _render_on_map(
  gfx_tool_t* gt, sprite_code_t sprite,
  int32_t screen_tlp_x, int32_t screen_tlp_y, //screen top left pixel
  vec2f sprite_mapcoord
) {
  gfx_render_sprite_i(
    gt,
    sprite,
    (sprite_mapcoord[0]*16) - screen_tlp_x,
    (sprite_mapcoord[1]*16) - screen_tlp_y
  );
}

static void _render_world(
  gfx_tool_t* gt, world_handler_t* world_handler, cam_t* cam
) {
  world_world_t world = world_handler->current_loaded_world;

  uint8_t pixel_offx = ((int) (cam->pos[0] * 16.0f)) % 16;
  uint8_t pixel_offy = ((int) (cam->pos[1] * 16.0f)) % 16;   
  int32_t starttilex = ((int) (cam->pos[0])) - GFX_SCREEN_TILES_HOR_H;
  int32_t starttiley = ((int) (cam->pos[1]))  - GFX_SCREEN_TILES_VERT_H;
  int32_t endtilex = starttilex + GFX_SCREEN_TILES_HOR;
  int32_t endtiley = starttiley + GFX_SCREEN_TILES_VERT;

  // draw bg, base, base2, fg 

  if (world.bg != 0) {
    
  }

  if (world.base != 0) {
    // using <= since we want one tile on the right more for offset
    int32_t scr_x = -pixel_offx;
    int32_t scr_y = -pixel_offy;
    for (int32_t j = starttiley; j <= endtiley; j++) {
      for (int32_t i = starttilex; i <= endtilex; i++) {
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

  //screen top left pixel according to map
  int32_t screen_tlp_x = (cam->pos[0] * 16.0f) - GFX_SCREEN_WIDTH/2;
  int32_t screen_tlp_y = (cam->pos[1] * 16.0f) - GFX_SCREEN_HEIGHT/2;

  if (world.base2 != 0) {
    
  }

  vec2f spr_pos;
  vec2_copy(spr_pos, world_handler->player->core.pos);
  vec2_add(spr_pos, world_handler->player->core.sprite_offset);
  // player will be drawn all the time
  _render_on_map(gt, world_handler->player->sprite, screen_tlp_x, screen_tlp_y, spr_pos);

  if (world.fg != 0) {
    
  }
}

void render_render(gfx_tool_t* gt, ingame_data_t* ingame_data, float dt) {
  gfx_clear(gt);
  gfx_fill_rect_a(gt, 0, 0, GFX_SCREEN_WIDTH, GFX_SCREEN_HEIGHT,
    PALETTE_BLACK_R, PALETTE_BLACK_G, PALETTE_BLACK_B, 255);

  if (ingame_data->world_handler->current_world_number != 0) 
    _render_world(gt, ingame_data->world_handler,
      &(ingame_data->cam));

  gfx_commit(gt);
}