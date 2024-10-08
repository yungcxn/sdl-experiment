#include "./vec.h"
 
#include "./common.h"

// TODO directly write


void vec2f_normalized(vec2f *v){
  float mag = math_fsqrt((*v)[0] * (*v)[0] + (*v)[1] * (*v)[1]);
  (*v)[0] /= mag;
  (*v)[1] /= mag;
}

/*


bool vec2f_is_unit(vec2f v){
  return (v.x == 1.0f && v.y == 0.0f) || (v.x == 0.0f && v.y == 1.0f) || (v.x == -1.0f && v.y == 0.0f) || (v.x == 0.0f && v.y == -1.0f) || (v.x == 0.0f && v.y == 0.0f);
}


vec3f vec3f_normalized(vec3f v){
  float mag = math_sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
  return (vec3f) {v.x / mag, v.y / mag, v.z / mag};
}


vec2f vec2f_scaled(vec2f v, float s){
  return (vec2f) {v.x * s, v.y * s};
}


vec3f vec3f_scaled(vec3f v, float s){
  return (vec3f) {v.x * s, v.y * s, v.z * s};
}
*/