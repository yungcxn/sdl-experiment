#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>
#include "./primitive.h"

typedef struct {
  byte r,g,b;
} rgb;

typedef struct {
  byte r,g,b,a;
} rgba;

/* aaaccccc                        */
/* where c is color reference code */
/* and   a is alpha 000-111        */
typedef byte c32;

#endif