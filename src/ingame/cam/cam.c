#include "./cam.h"

void cam_move_clean(cam_t* cam, vec2f dest, float dt) {
  //cam->move_elapsed_ticks += dt;
  //vec2f diff;
  //VEC2_COPY(diff, dest);
  //VEC2_SUB(diff, cam->pos); // diff = dest - campos
  //if (diff[0] == 0 && diff[1] == 0)
  //  return;
  //vec2f orgdiff;
  //VEC2_COPY(orgdiff, diff);
  //vec2f_normalized(&diff);  
  //DEBUG_PRINTF("%.2f, %.2f\n", diff[0], diff[1]);
  //VEC2_SCALE(diff, CAM_DIST_PER_SEC*dt);
  //if (VEC2_LEN(diff) > VEC2_LEN(orgdiff)) {
  VEC2_COPY(cam->pos, dest);
  //  cam->move_elapsed_ticks = 0;
  //} else {
  //  VEC2_ADD(cam->pos, diff);
  //}

}