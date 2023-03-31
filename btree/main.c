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

  btree_node *root = btree_create();
  root = btree_insert(root, 50);
  btree_insert(root, 30);
  btree_insert(root, 20);
  btree_insert(root, 40);
  btree_insert(root, 70);
  btree_insert(root, 60);
  btree_insert(root, 80);
  btree_insert(root, 35);
  btree_insert(root, 75);
  btree_insert(root, 41);

  btree_delete(root, 30);

  if (dot)
  {
    btree_dot(root);
  }
  else
  {
    printf("Inorder: \n");
    btree_print(root, BtreePrintOrder_Inorder);
    printf("\n");

    printf("Preorder: \n");
    btree_print(root, BtreePrintOrder_Preorder);
    printf("\n");

    printf("Postorder: \n");
    btree_print(root, BtreePrintOrder_Postorder);
    printf("\n");

    printf("BST has 35: ");
    btree_search(root, 35) ? printf("YES\n") : printf("NO\n");

    printf("BST has 30: ");
    btree_search(root, 30) ? printf("YES\n") : printf("NO\n");
  }
  printf("\n");

  return 0;
}