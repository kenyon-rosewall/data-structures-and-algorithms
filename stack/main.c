#include <stdio.h>
#include <string.h>
#include "types.h"
#include "stack.h"

b32 is_dot(i32 argc, char **argv)
{
  b32 dot = false;
  if (argc == 2)
  {
    if (strcmp("dot", argv[1]) == 0)
    {
      dot = true;
    }
  }

  return dot;
}

i32 main(i32 argc, char **argv)
{
  b32 dot = is_dot(argc, argv);

  stack* s = stack_create(6);
  i32 popped_empty = stack_pop(s);
  stack_push(s, 50);
  stack_push(s, 10);
  stack_push(s, 20);
  stack_push(s, 30);
  i32 popped = stack_pop(s);
  stack_push(s, 51);
  stack_push(s, 52);
  stack_push(s, 53);
  stack_push(s, 55);

  if (dot)
  {

  }
  else
  {
    stack_print(s);
    
    printf("Stack is empty: ");
    stack_empty(s) ? printf("YES\n") : printf("NO\n");
    printf("Stack is full: ");
    stack_full(s) ? printf("YES\n") : printf("NO\n");

    printf("Stack top is %d\n", stack_peek(s));
    printf("Popped while empty value is %d\n", popped_empty); 
    printf("Popped value is %d\n", popped);
  }

  stack_destroy(s);

  return 0;
}