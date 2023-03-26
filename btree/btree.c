#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

btree_node* btree_create_node(i32 value)
{
  btree_node* node = (btree_node*)malloc(sizeof(btree_node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

btree_node* btree_create()
{
  btree_node* root = NULL;

  return root;
}

void btree_destroy(btree_node* root)
{
  if (root != NULL)
  {
    free(root);
  }
}

void btree_print(btree_node* root)
{
  if (root != NULL)
  {
    btree_print(root->left);
    printf("%d ", root->value);
    btree_print(root->right);
  }
  // printf("\n");
}

btree_node* btree_insert(btree_node* node, i32 value)
{
  if (node == NULL) {
    return btree_create_node(value);
  }

  if (value < node->value)
  {
    node->left = btree_insert(node->left, value);
  }
  else if (value > node->value)
  {
    node->right = btree_insert(node->right, value);
  }

  return node;
}