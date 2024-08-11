#ifndef RES_HANDLER_H
#define RES_HANDLER_H

// this should be unoptimized and have no debug information

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "./res.h"
#include "../util/primitive.h"

typedef struct {
  uint8_t* sheet;
  uint32_t width;
  uint32_t height;
} res_handler_spritesheet_t;

res_handler_spritesheet_t res_handler_init_spritesheet();
void res_handler_destroy_spritesheet(res_handler_spritesheet_t x);

#endif