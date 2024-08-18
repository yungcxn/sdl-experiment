#include "./res_handler.h"

#include <stdlib.h>
#include <string.h>

res_handler_spritesheet_t res_handler_init_spritesheet() {
  uint32_t arr[] = {RES_ALL_DATA}; // this is encoded in RLE
  uint8_t* buf = (uint8_t*) malloc(sizeof(uint8_t) 
                                   * RES_ALL_WIDTH * RES_ALL_HEIGHT);
  /* the following solves the RLE encoding of arr[] */
  uint32_t len = array_len(arr);
  assert(len % 2 == 0); //throws if array is not partitioned in RLE-pairs
  uint32_t copy_at = 0;
  uint32_t i = 0;
  uint32_t j = 0;
  for (; i < len; i+=2) {
    j = i+1;
    uint8_t copy_buf[arr[i]];
    for (uint32_t t = 0; t < arr[i]; t++) {
      copy_buf[t] = arr[j];
    } 
    memcpy(buf + copy_at, copy_buf, arr[i]);
    copy_at += arr[i];
  }   
  return (res_handler_spritesheet_t) {buf, RES_ALL_WIDTH, RES_ALL_HEIGHT};
}

void res_handler_destroy_spritesheet(res_handler_spritesheet_t x) {
  safe_free(x.sheet);
}