#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <stdint.h>
#include <stddef.h>

#define bool _Bool
#define true 1
#define false 0
#define byte uint8_t

// from super duper nice linux kernel
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

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