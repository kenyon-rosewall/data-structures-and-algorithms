#pragma once

#ifndef OUEUE_H
#define QUEUE_H

#include "types.h"

// 
// Queues
//
// I did pretty much the same thing for the queues that I did for the stacks, so if there is
// anything that I didn't cover here, reading that description might straightened something 
// out.
//

// 
// TODO
// * 
// 

typedef struct queue queue;
struct queue
{
  i32 front;
  i32 rear;
  i32 size;
  u32 capacity;

  i32* queue_array;
};

queue* queue_create(u32 capacity);
void queue_destroy(queue* q);
void queue_print(queue* q);

b32 queue_empty(queue* q);
b32 queue_full(queue* q);

void queue_enqueue(queue* q, i32 value);
i32 queue_dequeue(queue* q);

i32 queue_front(queue* q);
i32 queue_rear(queue* q);
u32 queue_size(queue* q);

#endif // !OUEUE_H