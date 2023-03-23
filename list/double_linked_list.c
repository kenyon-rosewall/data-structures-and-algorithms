#include <stdlib.h>
#include <stdio.h>
#include "double_linked_list.h"

dll_node* dll_create_node(i64 data)
{
  dll_node* node = (dll_node*)malloc(sizeof(dll_node));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;

  return node;
}

dll_node* dll_get_tail(dll_node** head)
{
  dll_node* tail = *head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }

  return tail;
}

dll_node** dll_create(i64 data)
{
  dll_node** head = (dll_node**)malloc(sizeof(dll_node*));
  dll_node* node = dll_create_node(data);
  *head = node;

  return head;
}

void dll_destroy(dll_node** head)
{
  dll_node* current = *head;
  dll_node* next;

  while(current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

void dll_push(dll_node** head, i64 data)
{
  dll_node* new_node = dll_create_node(data);

  dll_node* tail = dll_get_tail(head);
  tail->next = new_node;
  new_node->prev = tail;

  return;
}

dll_node* dll_pop(dll_node** head)
{
  dll_node* tail = dll_get_tail(head);

  tail->prev->next = NULL;
  tail->prev = NULL;
  
  return tail;
}

void dll_unshift(dll_node** head, i64 data)
{
  dll_node* new_node = dll_create_node(data);
  new_node->next = *head;
  (*head)->prev = new_node;
  *head = new_node;
}

dll_node* dll_shift(dll_node** head)
{
  dll_node* old_head = *head;
  dll_node* new_head = (*head)->next;
  new_head->prev = NULL;
  *head = new_head;

  old_head->next = NULL;

  return old_head;
}

void dll_insert_after(dll_node* node, i64 data)
{
  if (node == NULL)
  {
    printf("Cannot add node after NULL value\n");
    return;
  }

  dll_node* new_node = dll_create_node(data);
  node->next->prev = new_node;
  new_node->prev = node;
  new_node->next = node->next;
  node->next = new_node;
}

dll_node* dll_remove_after(dll_node* node)
{
  if (node == NULL)
  {
    printf("Cannot remove node after NULL value\n");
    return NULL;
  }

  dll_node* old_node = node->next;
  old_node->next->prev = node;
  node->next = old_node->next;

  old_node->prev = NULL;
  old_node->next = NULL;

  return old_node;
}

dll_node* dll_remove(dll_node** head, u32 position)
{
  dll_node* current = *head;
  dll_node* old_node;
  u32 i = 0;
  while (current != NULL && i <= position)
  {
    if (i == position)
    {
      if (current->prev == NULL)
      {
        *head = current->next;
      }
      else
      {
        current->prev->next = current->next;
      }

      old_node = current;
      old_node->prev = NULL;
      old_node->next = NULL;
    }

    ++i;
    current = current->next;
  }

  if (old_node == NULL)
  {
    printf("Could not find valid node at position %d\n", position);
  }

  return old_node;
}

dll_node* dll_at(dll_node** head, u32 position)
{
  dll_node* current = *head;
  dll_node* node;
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

  return node;
}

void dll_print(dll_node** head)
{
  dll_node* current = *head;
  while (current != NULL)
  {
    printf(" %ld ", current->data);
    current = current->next;
  }
  printf("\n");
}

b32 dll_search(dll_node** head, i64 data)
{
  b32 found = false;
  dll_node* current = *head;
  while (current != NULL && !found)
  {
    if (current->data == data)
    {
      found = true;
    }
    
    current = current->next;
  }

  return found;
}

u32 dll_count(dll_node** head)
{
  dll_node* current = *head;
  u32 count = 0;

  while (current != NULL)
  {
    ++count;

    current = current->next;
  }

  return count;
}