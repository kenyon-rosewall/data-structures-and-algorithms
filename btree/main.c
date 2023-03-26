#include <stdio.h>
#include <string.h>
#include "types.h"
#include "btree.h"

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

  if (dot)
  {

  }
  else
  {

  }

  return 0;
}