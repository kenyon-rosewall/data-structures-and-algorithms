#include <stdlib.h>
#include <stdio.h>
#include "single_linked_list.h"

sll_node* sll_create_node(i64 data)
{
  sll_node* node = (sll_node*)malloc(sizeof(sll_node));
  node->data = data;
  node->next = NULL;

  return node;
}

sll_node* sll_get_tall(sll_node** head)
{
  if (*head == NULL)
  {
    printf("Cannot get tail of null linked list\n");
    return NULL;
  }

  sll_node* tail = *head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }

  return tail;
}

sll_node** sll_create()
{
  sll_node** head = (sll_node**)malloc(sizeof(sll_node*));
  *head = NULL;

  return head;
}

void sll_destroy(sll_node** head)
{
  if (*head != NULL)
  {
    sll_node* current = *head;
    sll_node* next = NULL;

    while(current != NULL)
    {
      next = current->next;
      free(current);
      current = next;
    }
    *head = NULL;
  }
}

void sll_push(sll_node** head, i64 data)
{
  sll_node* new_node = sll_create_node(data);

  if (*head == NULL)
  {
    *head = new_node;
  }
  else
  {
    sll_node* tail = sll_get_tall(head);
    tail->next = new_node;
  }

  return;
}

sll_node* sll_pop(sll_node** head)
{
  if (*head == NULL)
  {
    printf("Cannot pop a node off of a NULL linked list\n");
    return NULL;
  }

  sll_node* tail = *head;
  sll_node* before_tail = NULL;
  while(tail->next != NULL)
  {
    before_tail = tail;
    tail = tail->next;
  }
  before_tail->next = NULL;

  return tail;
}

void sll_unshift(sll_node** head, i64 data)
{
  sll_node* new_node = sll_create_node(data);

  new_node->next = *head;
  *head = new_node;
}

sll_node* sll_shift(sll_node** head)
{
  if (*head == NULL)
  {
    printf("Cannot shift a node off of a NULL linked list\n");
    return NULL;
  }

  sll_node* old_head = *head;
  sll_node* new_head = (*head)->next;
  *head = new_head;
  old_head->next = NULL;

  return old_head;
}

void sll_insert_after(sll_node* node, i64 data)
{
  if (node == NULL)
  {
    printf("Cannot add node after NULL value\n");
    return;
  }

  sll_node* new_node = sll_create_node(data);
  new_node->next = node->next;
  node->next = new_node;
}

sll_node* sll_remove_after(sll_node* node)
{
  if (node == NULL)
  {
    printf("Cannot remove node after NULL value\n");
    return NULL;
  }

  sll_node* old_node = node->next;
  sll_node* next_node = old_node->next;
  node->next = next_node;
  old_node->next = NULL;

  return old_node;
}

sll_node* sll_remove(sll_node** head, u32 position)
{
  sll_node* current = *head;
  sll_node* prev_node = NULL;
  sll_node* old_node = NULL;
  u32 i = 0;
  while (current != NULL && i <= position)
  {
    if (i == position)
    {
      if (prev_node == NULL)
      {
        *head = current->next;
      }
      else
      {
        prev_node->next = current->next;
      }

      old_node = current;
      old_node->next = NULL;
    }

    ++i;
    prev_node = current;
    current = current->next;
  }

  if (old_node == NULL)
  {
    printf("Could not find valid node at position %d\n", position);
  }

  return old_node;
}

sll_node* sll_at(sll_node** head, u32 position)
{
  sll_node* current = *head;
  sll_node* node = NULL;
  u32 i = 0;
  while (current != NULL && i <= position)
  {
    if (i == position)
    {
      node = current;
    }

    ++i;
    current = current->next;
  }

  if (node == NULL)
  {
    printf("Could not find valid node at position %d\n", position);
  }

  return node;
}

void sll_print(sll_node** head)
{
  if (*head != NULL)
  {
    sll_node* current = *head;
    while (current != NULL)
    {
      printf(" %ld ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

void sll_dot(sll_node** head)
{
  if (*head != NULL)
  {
    printf("digraph SLL {\n");
    printf("\tnode [shape=record]\n");
    sll_node* current = *head;
    u32 i = 0;
    while (current != NULL)
    {
      if (current->next != NULL)
      {
        printf("\tn%d[label=\"node\\: n%d \\| data\\: %ld \\| next\\: \\-\\> n%d\"]\n", i, i, current->data, i+1);
        printf("\tn%d -> n%d\n", i, i+1);
      }
      else
      {
        printf("\tn%d[label=\"node\\: n%d \\| data\\: %ld \\| next\\: \\-\\> NULL\"]\n", i, i, current->data);
      }

      ++i;
      current = current->next;
    }
    printf("}");
  }
}

i32 sll_search(sll_node** head, i64 data)
{
  i32 position = -1;
  sll_node* current = *head;
  u32 i = 0;
  while (current != NULL && position < 0)
  {
    if (current->data == data)
    {
      position = i;
    }
    
    ++i;
    current = current->next;
  }

  return position;
}

u32 sll_count(sll_node** head)
{
  sll_node* current = *head;
  u32 count = 0;

  while (current != NULL)
  {
    ++count;

    current = current->next;
  }

  return count;
}