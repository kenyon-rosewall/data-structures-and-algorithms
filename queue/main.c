#include <stdio.h>
#include "queue.h"

i32 main(i32 argc, char **argv)
{
  queue* q = queue_create(5);

  printf("Queue's size is %d\n", q->size);

  printf("Queue is empty: ");
  queue_empty(q) ? printf("YES\n") : printf("NO\n");
  i32 dequeued_empty = queue_dequeue(q);

  queue_enqueue(q, 10);
  queue_enqueue(q, 20);
  queue_enqueue(q, 30);
  printf("Queue's size is %d\n", q->size);
  queue_enqueue(q, 40);
  queue_enqueue(q, 50);
  queue_enqueue(q, 100);
  printf("Queue's size is %d\n", q->size);

  queue_full(q) ? printf("YES\n") : printf("NO\n");

  i32 dequeued_first = queue_dequeue(q);
  i32 dequeued_second = queue_dequeue(q);

  queue_print(q);

  printf("Dequeued empty: %d\n", dequeued_empty);
  printf("Dequeued first: %d\n", dequeued_first);
  printf("Dequeued second: %d\n", dequeued_second);

  queue_destroy(q);
}