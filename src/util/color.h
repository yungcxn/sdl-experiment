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

// bits: cccc aaaa
typedef byte c16;

rgba rgba_from_hex(uint32_t hex);
byte alpha_from_c16(c16 c);
byte c16ref_from_c16(c16 c);


#endif