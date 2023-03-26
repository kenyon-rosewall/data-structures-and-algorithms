#pragma once

#ifndef BTREE_H
#define BTREE_H

#include "types.h"

typedef struct btree_node btree_node;
struct btree_node
{
  u32 value;
  btree_node* left;
  btree_node* right;
};

btree_node* btree_create();
void btree_destroy(btree_node* root);
void btree_print(btree_node* root);
void btree_dot(btree_node* root);

btree_node* btree_insert(btree_node* root, i32 value);

#endif // !BTREE_H