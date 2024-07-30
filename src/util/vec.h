#ifndef VEC_H
#define VEC_H

#include "./math.h"
#include <stdint.h>

// Macros
#define vec2_set(var, x, y) do { \
    (var)[0] = (x);               \
    (var)[1] = (y);               \
} while (0)

#define mat22_set(var, a,b,c,d) do { \
    (var)[0] = (a);                \
    (var)[1] = (b);                \
    (var)[2] = (c);                \
    (var)[3] = (d);                \
} while (0)

#define vec2_copy(a, b) do { \
    (a)[0] = (b)[0];          \
    (a)[1] = (b)[1];          \
} while (0)

#define mat22_copy(a, b) do { \
    (a)[0] = (b)[0];           \
    (a)[1] = (b)[1];           \
    (a)[2] = (b)[2];           \
    (a)[3] = (b)[3];           \
} while (0)

#define vec2_add(a, b) do { \
    (a)[0] += (b)[0];        \
    (a)[1] += (b)[1];        \
} while (0)

typedef float vec2f[2];
typedef float vec3f[3];
typedef float mat22f[4]; // x1, y1, x2, y2

// TODO export

#endif 