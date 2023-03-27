#pragma once

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include "types.h"

// 
// Single Linked Lists
//
// I've chosen the value to be a 32-bit int in this case. I started with a void*, but I felt
// that it wasn't as pure an implementation. But, if you needed different data here, you 
// could just make that change to the sll_node data type.
// 
// These are non-circular. If one wanted to implement that, it would take one of two things.
// One, you could just make the tail->next = *head. The other way that might help in actual
// implementation would be to create a sentinel node that would be marked to know it's the
// point where the list turns around.
// 
// In this data structure, I've chosen to represent the head as a pointer to the pointer of
// the first element in the array, rather than to just the pointer of the first element of
// the array. I did this because I change *head in a number of methods. The alternative I
// could have done was to return the head node every time I made a change and set it in the 
// implementation code.
// 
// Any nodes that are returned from popping or shifting or removing need to be freed in the
// implementation code.
//
// Position is standard array form (0 is first). So the sll_search function returns -1 if it
// cannot find the node.
// 
// If you have Graphviz, you can output the list as a dot (directed graph) with sll_dot(). The
// Makefile stores this as a PDF.
//

// 
// TODO
// * Reverse the list
// * Remove duplicates from list
// * Sort (will implement after main sorting algorithms)
// 

typedef struct sll_node sll_node;
struct sll_node
{
  i32 data;
  sll_node* next;
};

sll_node** sll_create();
void sll_destroy(sll_node** head);

void sll_push(sll_node** head, i32 data);
sll_node* sll_pop(sll_node** head);
void sll_unshift(sll_node** head, i32 data);
sll_node* sll_shift(sll_node** head);

void sll_insert_after(sll_node* node, i32 data);
sll_node* sll_remove_after(sll_node* node);
sll_node* sll_remove(sll_node** head, u32 position);

sll_node* sll_at(sll_node** head, u32 position);

void sll_print(sll_node** head);
void sll_dot(sll_node** head);
i32 sll_search(sll_node** head, i32 data);
u32 sll_count(sll_node** head);

#endif // !SINGLE_LINKED_LIST_H