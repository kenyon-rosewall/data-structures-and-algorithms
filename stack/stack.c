#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "stack.h"

stack* stack_create(u32 capacity)
{
  stack* s = (stack*)malloc(sizeof(stack));
  s->capacity = capacity;
  s->top = -1;
  s->stack_array = (i32*)malloc(s->capacity * sizeof(i32));

  return s;
}

void stack_destroy(stack* s)
{
  free(s->stack_array);
  free(s);
}

b32 stack_empty(stack* s)
{
  return s->top == -1;
}

b32 stack_full(stack* s)
{
  return s->top == s->capacity-1;
}

void stack_dot(stack* s)
{

}

void stack_print(stack* s)
{
  printf("Stack is: ");
  if (!stack_empty(s))
  {
    for (u32 i = 0;
      i <= s->top;
      ++i)
    {
      printf("%d ", s->stack_array[i]);
    }
  }
  printf("\n");
}

void stack_push(stack* s, i32 item)
{
  if (stack_full(s))
  {
    printf("Stack Overflow!\n");
    return;
  }

  s->stack_array[++s->top] = item;
}

i32 stack_pop(stack* s)
{
  if (stack_empty(s))
  {
    return INT_MIN;
  }

  i32 item = s->stack_array[s->top--];

  return item;
}

i32 stack_peek(stack* s)
{
 return s->top; 
}