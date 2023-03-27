#pragma once

#ifndef BTREE_H
#define BTREE_H

#include "types.h"

// 
// Binary Search Trees
// 
// I decided just to implement BST trees rather than just generically Binary Trees. The 
// reason for this is because I wanted to utilize the binary search algorithms for the 
// exercise of these standard data structures. Another idea I threw around was implementing
// a Binary Tree and creating restrictions in the algorithms to process them. Again, the 
// main reason I didn't do this is that when inserting into a Binary Tree, I decided to use
// the left is less than and right is greater than standard. Anything other that will potentially
// be explored later.
//

// 
// TODO
// * Implement generic Binary Tree
// * Check if Binary Tree is a BST
// * Array (sorted or not) to BST
// * Balance tree from an unbalanced version
// * Lowest common ancestor of 2 nodes
// * Traversal/search (Depth first order, breadth first order)
//

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