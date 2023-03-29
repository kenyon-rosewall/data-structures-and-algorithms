#pragma once

#ifndef OUEUE_H
#define QUEUE_H

#include "types.h"

// 
// Queues
//
// I
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

b32 queue_empty(queue* q);
b32 queue_full(queue* q);

void queue_enqueue(queue* q, i32 value);
i32* queue_dequeue(queue* q);
i32 queue_front(queue* q);
i32 queue_rear(queue* q);

#endif // !OUEUE_H