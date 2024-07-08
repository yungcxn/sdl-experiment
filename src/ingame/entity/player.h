#ifndef PLAYER_H
#define PLAYER_H

#include "./entity.h"

typedef struct {
  entity_t player_entity;
} player_t;

void player_init(player_t* player);

#endif