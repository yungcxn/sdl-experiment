#include "./player.h"

player_state_t player_fsm_get_next(player_state_t p, float dt) {
  return 0;
}

void player_fsm_simulate(player_t* p, float dt) {
  (*p).current_state = player_fsm_get_next((*p).current_state, dt);
}