#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* queue_create(u32 capacity)
{
  queue* q = (queue*)malloc(sizeof(queue));
  q->front = 0;
  q->size = 0;
  q->capacity = capacity;
  q->rear = capacity-1;
  q->queue_array = (i32*)malloc(capacity * sizeof(i32));

  return q;
}

void queue_destroy(queue* q)
{
  free(q->queue_array);
  free(q);
}

b32 queue_empty(queue* q)
{
  return q->size = 0;
}

b32 queue_full(queue* q)
{
  return q->size == q->capacity;
}

void queue_enqueue(queue* q, i32 value)
{
  if (queue_empty(q))
  {
    printf("Queue overflow\n");
    return;
  }

  q->rear = (q->rear + 1) % q->capacity;
  q->queue_array[q->rear] = value;
  q->size++;
}

i32* queue_dequeue(queue* q)
{

}

i32 queue_front(queue* q)
{

}

i32 queue_rear(queue* q)
{

}