#include "./math.h"

float math_sqrt(float x) {
  float low = 0, high = x, mid;
  while (high - low > 0.00001f) {
    mid = (low + high) / 2;
    if (mid * mid > x)
      high = mid;
    else
      low = mid;
  }
  return (low + high) / 2;
}