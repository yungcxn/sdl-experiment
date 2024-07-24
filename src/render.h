#ifndef RENDER_H
#define RENDER_H

/* More abstracted rendering layer */

#include "./gfx.h"
#include "./util/primitive.h"
#include "./ingame/cam/cam.h"
#include "./ingame/ingame.h"

void render_render(gfx_tool_t* gt, ingame_data_t* ingame_data, float dt);

#endif