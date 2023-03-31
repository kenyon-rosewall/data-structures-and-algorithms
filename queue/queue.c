#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

queue *queue_create(u32 capacity)
{
  queue *q = (queue *)malloc(sizeof(queue));
  q->front = 0;
  q->size = 0;
  q->capacity = capacity;
  q->rear = capacity - 1;
  q->queue_array = (i32 *)malloc(capacity * sizeof(i32));

  return q;
}

void queue_destroy(queue *q)
{
  free(q->queue_array);
  free(q);
}

void queue_print(queue *q)
{
  if (queue_empty(q))
  {
    return;
  }

  for (i32 i = q->front;
       i <= q->rear;
       ++i)
  {
    printf("%d ", q->queue_array[i]);
  }
  printf("\n");
}

b32 queue_empty(queue *q)
{
  return q->size == 0;
}

b32 queue_full(queue *q)
{
  return q->size == q->capacity;
}

void queue_enqueue(queue *q, i32 value)
{
  if (queue_full(q))
  {
    printf("Queue overflow\n");
    return;
  }

  q->rear = (q->rear + 1) % q->capacity;
  q->queue_array[q->rear] = value;
  q->size++;
}

i32 queue_dequeue(queue *q)
{
  if (queue_empty(q))
  {
    return INT_MIN;
  }

  i32 value = q->queue_array[q->front];
  q->front = (q->front + 1) % q->capacity;
  q->size--;

  return value;
}

i32 queue_front(queue *q)
{
  if (queue_empty(q))
  {
    return INT_MIN;
  }

  return q->queue_array[q->front];
}

i32 queue_rear(queue *q)
{
  if (queue_empty(q))
  {
    return INT_MIN;
  }

  return q->queue_array[q->rear];
}

u32 queue_size(queue *q)
{
  return q->size;
}