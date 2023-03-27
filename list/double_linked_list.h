#pragma once

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "types.h"

// 
// Double Linked Lists
// 
// This is essentially the exact same implementation of single linked lists and doesn't need
// a repeated explanation. Read the Single Linked Lists description first.
// 
// The only real separate note I could add is that the main.c essentially can be switched
// between single linked lists and double linked lists by commenting out the respective 
// function. The only reason for this is because of how the Makefile builds only one PDF from
// the Graphviz dot output. Feel free to change around and check what's going on.
// 

typedef struct dll_node dll_node;
struct dll_node
{
  i32 data;
  dll_node* prev;
  dll_node* next;
};

dll_node** dll_create();
void dll_destroy(dll_node** head);

void dll_push(dll_node** head, i32 data);
dll_node* dll_pop(dll_node** head);
void dll_unshift(dll_node** head, i32 data);
dll_node* dll_shift(dll_node** head);

void dll_insert_after(dll_node* node, i32 data);
dll_node* dll_remove_after(dll_node* node);
dll_node* dll_remove(dll_node** head, u32 position);

dll_node* dll_at(dll_node** head, u32 position);

void dll_print(dll_node** head);
void dll_dot(dll_node** head);
i32 dll_search(dll_node** head, i32 data);
u32 dll_count(dll_node** head);

#endif // !DOUBLE_LINKED_LIST_H