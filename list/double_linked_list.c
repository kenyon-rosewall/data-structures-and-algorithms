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
  if (*head == NULL)
  {
    printf("Cannot find tail of a null linked list\n");
    return NULL;
  }

  dll_node* tail = *head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }

  return tail;
}

dll_node** dll_create()
{
  dll_node** head = (dll_node**)malloc(sizeof(dll_node*));
  *head = NULL;
  
  return head;
}

void dll_destroy(dll_node** head)
{
  dll_node* current = *head;
  dll_node* next = NULL;

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

  if (*head == NULL)
  {
    *head = new_node;
  }
  else
  {
    dll_node* tail = dll_get_tail(head);
    tail->next = new_node;
    new_node->prev = tail;
  }

  return;
}

dll_node* dll_pop(dll_node** head)
{
  if (*head == NULL)
  {
    printf("Cannot pop a node off of a NULL linked list\n");
    return NULL;
  }

  dll_node* tail = dll_get_tail(head);

  tail->prev->next = NULL;
  tail->prev = NULL;
  
  return tail;
}

void dll_unshift(dll_node** head, i64 data)
{
  dll_node* new_node = dll_create_node(data);
  
  new_node->next = *head;
  if (*head != NULL)
  {
    (*head)->prev = new_node;
  }
  *head = new_node;
}

dll_node* dll_shift(dll_node** head)
{
  if (*head == NULL)
  {
    printf("Cannot shift a node off of a NULL linked list\n");
    return NULL;
  }

  dll_node* old_head = *head;
  dll_node* new_head = (*head)->next;
  if (new_head != NULL)
  {
    new_head->prev = NULL;
  }
  *head = new_head;

  if (old_head != NULL)
  {
    old_head->next = NULL;
  }

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
  dll_node* old_node = NULL;
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
  dll_node* node = NULL;
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

i32 dll_search(dll_node** head, i64 data)
{
  i32 position = -1;
  dll_node* current = *head;
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