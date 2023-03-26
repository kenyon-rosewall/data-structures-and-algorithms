#include <stdlib.h>
#include "btree.h"

btree_node* btree_create_node(i32 value)
{
  btree_node* node = (btree_node*)malloc(sizeof(btree_node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

btree_node** btree_create()
{
  btree_node** root = (btree_node**)malloc(sizeof(btree_node*));
  *root = NULL;

  return root;
}

void btree_destroy(btree_node** root)
{
  if (*root != NULL)
  {
    free(root);
  }
}

void btree_insert(btree_node* root, i32 value)
{

}