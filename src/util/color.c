#include "./color.h"
#include <stdio.h>

rgba rgba_from_hex(uint32_t hex) {
  return (rgba) {
    hex & 0xFF, 
    (hex >> 8) & 0xFF,
    (hex >> 16) & 0xFF,
    (hex >> 24) & 0xFF,
  };
}


byte alpha_from_c16(c16 c) {
  return (c & 0x0F) * 0x11;
  // = (c & 0b00001111) | ((c & 0b00001111) << 4)
}


byte c16ref_from_c16(c16 c) {
  printf("%d\n", c);
  return c >> 4;
}

c16 alphad_c16(c16 c, byte customalpha) {
  return c & customalpha;
}