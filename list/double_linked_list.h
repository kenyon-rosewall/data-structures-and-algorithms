#pragma once

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "types.h"

typedef struct dll_node dll_node;
struct dll_node
{
  i64 data;
  dll_node* prev;
  dll_node* next;
};

dll_node** dll_create();
void dll_destroy(dll_node** head);

void dll_push(dll_node** head, i64 data);
dll_node* dll_pop(dll_node** head);
void dll_unshift(dll_node** head, i64 data);
dll_node* dll_shift(dll_node** head);

void dll_insert_after(dll_node* node, i64 data);
dll_node* dll_remove_after(dll_node* node);
dll_node* dll_remove(dll_node** head, u32 position);

dll_node* dll_at(dll_node** head, u32 position);

void dll_print(dll_node** head);
void dll_dot(dll_node** head);
i32 dll_search(dll_node** head, i64 data);
u32 dll_count(dll_node** head);

#endif // !DOUBLE_LINKED_LIST_H