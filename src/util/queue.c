#include "./queue.h"

#include <stdlib.h>

bool queue_is_full(queue* q) {
  return ((q->rear + 1) % q->size) == q->front;
}

bool queue_is_empty(queue* q) {
  return q->rear == q->front;
}

queue* queue_init(int32_t size){
  queue* q = (queue*) malloc(sizeof(queue));
  q->rear = -1;
  q->front = -1;
  q->size = size;
  q->array = (QUEUE_INT*) calloc(size, sizeof(QUEUE_INT));
  return q;
}

void queue_destroy(queue* q){
  SAFE_FREE(q->array);
  SAFE_FREE(q);
}

void queue_en(queue* q, QUEUE_INT x){
  //if (!_queue_is_full(*q)) 
    //return;

  q->rear = (q->rear + 1) % q->size;
  q->array[q->rear] = x;
}


QUEUE_INT queue_peak(queue* q){
  //if (!_queue_is_empty(q))
    //return;

  return (q->front + 1) % q->size;
}


QUEUE_INT queue_de(queue* q){
  //if (!_queue_is_empty(*q))
    //return;

  q->front = (q->front + 1) % q->size;
  QUEUE_INT val = q->array[q->front];
  return val;
}


void queue_clear(queue* q){
  while (!queue_is_empty(q)) {
    queue_de(q);
  }
}
