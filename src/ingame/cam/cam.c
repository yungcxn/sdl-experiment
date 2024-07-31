#include "./cam.h"

void cam_move_clean(cam_t* cam, vec2f dest, float dt) {
  //cam->move_elapsed_ticks += dt;
  //vec2f diff;
  //vec2_copy(diff, dest);
  //vec2_sub(diff, cam->pos); // diff = dest - campos
  //if (diff[0] == 0 && diff[1] == 0)
  //  return;
  //vec2f orgdiff;
  //vec2_copy(orgdiff, diff);
  //vec2f_normalized(&diff);  
  //debug_printf("%.2f, %.2f\n", diff[0], diff[1]);
  //vec2_scale(diff, CAM_DIST_PER_SEC*dt);
  //if (vec2_len(diff) > vec2_len(orgdiff)) {
  vec2_copy(cam->pos, dest);
  //  cam->move_elapsed_ticks = 0;
  //} else {
  //  vec2_add(cam->pos, diff);
  //}

}