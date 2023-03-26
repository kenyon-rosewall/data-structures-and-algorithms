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

  btree_node* root = btree_create();
  root = btree_insert(root, 50);
  btree_insert(root, 30);
  btree_insert(root, 20);
  btree_insert(root, 40);
  btree_insert(root, 70);
  btree_insert(root, 60);
  btree_insert(root, 80);

  if (dot)
  {

  }
  else
  {
    btree_print(root);
    printf("\n");
  }

  return 0;
}