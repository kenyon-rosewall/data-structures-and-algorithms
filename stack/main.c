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

  stack* s = stack_create(25);
  stack_push(s, 10);
  stack_push(s, 20);
  stack_push(s, 30);
  i32 popped = stack_pop(s);
  stack_push(s, 50);

  if (dot)
  {

  }
  else
  {
    stack_print(s);
    printf("Popped value is %d\n", popped);
  }

  return 0;
}