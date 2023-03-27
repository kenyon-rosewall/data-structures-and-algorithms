#pragma once

#ifndef BTREE_H
#define BTREE_H

#include "types.h"

typedef struct btree_node btree_node;
struct btree_node
{
  i32 value;
  btree_node* left;
  btree_node* right;
};

enum BtreePrintOrder
{
  BtreePrintOrder_Inorder,
  BtreePrintOrder_Preorder,
  BtreePrintOrder_Postorder
};

btree_node* btree_create();
void btree_destroy(btree_node* root);
void btree_print(btree_node* root, enum BtreePrintOrder order);
void btree_dot(btree_node* root);

btree_node* btree_insert(btree_node* node, i32 value);
btree_node* btree_delete(btree_node* node, i32 value);

b32 btree_search(btree_node* node, i32 value);

#endif // !BTREE_H