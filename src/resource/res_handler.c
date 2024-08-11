#include "./res_handler.h"

res_handler_spritesheet_t res_handler_init_spritesheet() {
  uint8_t arr[] = {RES_ALL_DATA};
  uint8_t* buf = (uint8_t*) malloc(sizeof(uint8_t) 
                                   * RES_ALL_WIDTH * RES_ALL_HEIGHT);
  memcpy(buf, arr, sizeof(arr));
  return (res_handler_spritesheet_t) {buf, RES_ALL_WIDTH, RES_ALL_HEIGHT};
}

void res_handler_destroy_spritesheet(res_handler_spritesheet_t x) {
  safe_free(x.sheet);
}