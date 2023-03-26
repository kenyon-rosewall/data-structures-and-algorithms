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
}

void btree_dot_print(btree_node* node)
{
  if (node == NULL)
  {
    return;
  }

  btree_dot_print(node->left);
  if (node->left != NULL)
  {
    printf("\t%d -> %d\n", node->value, node->left->value);
  }
  if (node->right != NULL)
  {
    printf("\t%d -> %d\n", node->value, node->right->value);
  }
  btree_dot_print(node->right);
}

void btree_dot(btree_node* root)
{
  printf("digraph BST {\n");
  printf("\tnode [fontname=\"Arial\"]\n");
  printf("\tedge [color=blue, fontname=\"Arial\"]\n");
  printf("\n");
  printf("\t%d [color=red, style=filled]\n", root->value);
  btree_dot_print(root);
  printf("}");
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