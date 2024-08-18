#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./debug.h"

typedef char* string;


// from super duper nice linux kernel
#define CONTAINER_OF(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))

#define SAFE_FREE(ptr) do { free((ptr)); (ptr) = NULL; } while (0)

#define ASSERT(x)                           \
  do {                                      \
    if (!(x)) {                             \
      DEBUG_PRINTF("SDL_ERROR: %s", #x);    \
      exit(1);                              \
    }                                       \
  } while(0)

#define SDL_ASSERT(x)                                       \
  do {                                                      \
    if (!(x)) {                                             \
      DEBUG_PRINTF("ERROR - %s %s", SDL_GetError(), #x);    \
      exit(1);                                              \
    }                                                       \
  } while(0)

#endif