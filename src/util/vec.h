#ifndef VEC_H
#define VEC_H

#include "./math.h"
#include <stdint.h>

// Macros
#define VEC2_SET(var, x, y) do {  \
    (var)[0] = (x);               \
    (var)[1] = (y);               \
} while (0)

#define MAT22_SET(var, a,b,c,d) do {  \
    (var)[0] = (a);                   \
    (var)[1] = (b);                   \
    (var)[2] = (c);                   \
    (var)[3] = (d);                   \
} while (0)

#define VEC2_COPY(a, b) do {  \
    (a)[0] = (b)[0];          \
    (a)[1] = (b)[1];          \
} while (0)

#define MAT22_COPY(a, b) do {  \
    (a)[0] = (b)[0];           \
    (a)[1] = (b)[1];           \
    (a)[2] = (b)[2];           \
    (a)[3] = (b)[3];           \
} while (0)

#define VEC2_ADD(a, b) do {  \
    (a)[0] += (b)[0];        \
    (a)[1] += (b)[1];        \
} while (0)

#define VEC2_SUB(a, b) do {  \
    (a)[0] -= (b)[0];        \
    (a)[1] -= (b)[1];        \
} while (0)

#define VEC2_SCALE(a, s) do { \
    (a)[0] *= s;              \
    (a)[1] *= s;              \
} while (0)

#define VEC2_LEN(a) math_fsqrt((a)[0] * (a)[0] + (a)[1] * (a)[1]) 

typedef float vec2f[2];
typedef float vec3f[3];
typedef float mat22f[4]; // x1, y1, x2, y2

void vec2f_normalized(vec2f *v);
// TODO export

#endif 