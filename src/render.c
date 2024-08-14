#include "./render.h"

#include "./ingame/cam/cam.h"
#include "./util/debug.h"

// TODO: Bad Code!

static void _render_hud(gfx_tool_t* gt, hud_t* hud) {
  uint8_t heartwidth = 11;

  uint8_t hnum = 0;
  for (int i = 0; i < hud->player->maxhealth; hnum++) {
    gfx_render_sprite_i(gt, GFX_SPRITE_SMALL_NO_HEART, hnum*heartwidth, 0);
    i += 2;
  }
  hnum = 0;
  for (int i = hud->player->health; i > 0; hnum++) {
    if (i == 1) {
      gfx_render_sprite_i(gt, GFX_SPRITE_SMALL_HEART_HALF, hnum*heartwidth, 0);
      break;
    }
    gfx_render_sprite_i(gt, GFX_SPRITE_SMALL_HEART, hnum*heartwidth, 0);
    i -= 2;
  }

  uint8_t orgxoff = 1;
  uint8_t staminawidth1 = 4;
  uint8_t staminawidth2 = 3;
  uint8_t current = hud->player->maxstamina;
  uint8_t xoff = orgxoff;
  uint8_t yoff = heartwidth;
  uint8_t accoff = 0;
  for (int i = 0; i < current; i++) {
    gfx_sprite_code_t c = GFX_SPRITE_SMALL_NO_STAMINA_M;
    uint8_t addingoff = staminawidth2;
    if (i == 0) {
      c = GFX_SPRITE_SMALL_NO_STAMINA_L;
      addingoff = staminawidth1;
    } else if (i == hud->player->maxstamina-1) {
      c = GFX_SPRITE_SMALL_NO_STAMINA_R;
      addingoff = staminawidth1;
    }
    gfx_render_sprite_i(gt, c, xoff + accoff ,yoff);
    accoff += addingoff;
  }

  current = hud->player->stamina;
  xoff = orgxoff;
  accoff = 0;
  for (int i = 0; i < current; i++) {
    gfx_sprite_code_t c = GFX_SPRITE_SMALL_STAMINA_M;
    uint8_t addingoff = staminawidth2;
    if (i == 0) {
      c = GFX_SPRITE_SMALL_STAMINA_L;
      addingoff = staminawidth1;
    } else if (i == hud->player->maxstamina-1) {
      c = GFX_SPRITE_SMALL_STAMINA_R;
      addingoff = staminawidth1;
    }
    
    gfx_render_sprite_i(gt, c, xoff + accoff ,yoff);
    accoff += addingoff;
  }
}

static inline void _render_on_map(
  gfx_tool_t* gt, gfx_sprite_code_t sprite,
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
          gfx_sprite_code_t target_sprite_code 
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

  if (ingame_data->world_handler->current_world_number != 0) {
    _render_world(gt, ingame_data->world_handler,
      &(ingame_data->cam));
    _render_hud(gt, &(ingame_data->hud));
  }
    
  gfx_commit(gt);
}