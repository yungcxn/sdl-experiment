#ifndef RENDER_H
#define RENDER_H

/* More abstracted rendering layer */

#include "./gfx.h"
#include "./util/primitive.h"

STATUS render_render(gfx_tool_t* gt, float dt);

#endif