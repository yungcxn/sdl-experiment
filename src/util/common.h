#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./debug.h"

typedef char* string;


// from super duper nice linux kernel
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define array_len(arr) (sizeof(arr) / sizeof((arr)[0]))

#define safe_free(ptr) do { free((ptr)); (ptr) = NULL; } while (0)

#define assert(x)                       \
  do {                                  \
    if (!(x)) {                         \
      debug_printf("SDL_ERROR: %s", #x);    \
      exit(1);                          \
    }                                   \
  } while(0);

#define sdl_assert(x)                                       \
  do {                                                      \
    if (!(x)) {                                             \
      debug_printf("ERROR - %s %s", SDL_GetError(), #x);   \
      exit(1);                                              \
    }                                                       \
  } while(0);


#define STATUS char

#define STATUS_SUCCESS 0
#define STATUS_ERR 1 // unhandled or general exception
#define STATUS_FNF 2 // file not found
#define STATUS_NOPERM 3
#define STATUS_ILLEGAL_INPUT 4
#define STATUS_SDL 5 // this is an error type
#define STATUS_INIT_QUIT 100 // successful game quit
#define STATUS_NO_EVENT 6;

#endif