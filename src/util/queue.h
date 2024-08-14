#ifndef QUEUE_H
#define QUEUE_H

#include "./common.h"
#include <stdint.h>

/* should be the biggest needed space across the project */
/* or i will use custom size queues for every size       */
#define QUEUE_INT uint64_t

/* right growing queue */
typedef struct {
  int32_t rear;
  int32_t front;
  int32_t size;
  QUEUE_INT* array;
} queue;

bool queue_is_full(queue* q);
bool queue_is_empty(queue* q);
queue* queue_init(int32_t size);
void queue_destroy(queue* q);
void queue_en(queue* q, QUEUE_INT x);
QUEUE_INT queue_peak(queue* q);
QUEUE_INT queue_de(queue* q);
void queue_clear(queue* q);



#endif 