#pragma once

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "types.h"

typedef struct sll_node sll_node;
struct sll_node
{
  i64 data;
  sll_node* next;
};

sll_node** sll_create(i64 data);
void sll_destroy(sll_node** head);

void sll_push(sll_node** head, i64 data);
sll_node* sll_pop(sll_node** head);
void sll_unshift(sll_node** head, i64 data);
sll_node* sll_shift(sll_node** head);

void sll_insert_after(sll_node* node, i64 data);
sll_node* sll_remove_after(sll_node* node);
sll_node* sll_remove(sll_node** head, u32 position);

sll_node* sll_at(sll_node** head, u32 position);

void sll_print(sll_node** head);
b32 sll_search(sll_node** head, i64 data);
u32 sll_count(sll_node** head);

#endif // !DOUBLE_LINKED_LIST_H