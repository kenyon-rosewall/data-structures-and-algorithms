#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "set.h"

set *set_create(u32 capacity)
{
  set *s = malloc(sizeof(set));
  s->size = 0;
  s->capacity = capacity;
  s->data = (i32 *)malloc(s->capacity * sizeof(i32));

  return s;
}

void set_destroy(set *s)
{
  free(s->data);
  free(s);
}

b32 set_empty(set *s)
{
  return s->size == 0;
}

b32 set_full(set *s)
{
  return s->size == s->capacity;
}

u32 set_size(set *s)
{
  return s->size;
}

b32 set_contains(set *s, i32 value)
{
  b32 contains = false;

  for (u32 i = 0;
       i < s->size;
       ++i)
  {
    if (s->data[i] == value)
    {
      contains = true;
    }
  }

  return contains;
}

void set_print(set *s)
{
  if (!set_empty(s))
  {
    printf("Set is: ");
    for (u32 i = 0;
         i < s->size;
         ++i)
    {
      printf("%d ", s->data[i]);
    }
  }
  printf("\n");
}

void set_add(set *s, i32 value)
{
  if (set_contains(s, value))
  {
    return;
  }

  if (s->size == s->capacity)
  {
    printf("Set overflow\n");
    return;
  }

  s->data[s->size++] = value;
}

void set_remove(set *s, i32 value)
{
  if (set_empty(s))
  {
    return;
  }

  u32 i = 0;
  while (i < s->size)
  {
    if (s->data[i] == value)
    {
      break;
    }

    ++i;
  }

  if (i == s->size)
  {
    return;
  }

  for (u32 j = i;
       j < s->size - 1;
       ++j)
  {
    s->data[j] = s->data[j + 1];
  }

  s->size--;
}

set *set_map(set *s, set_map_func func)
{
  set *result = set_create(s->size);
  result->size = s->size;
  for (u32 i = 0;
       i < result->capacity;
       ++i)
  {
    result->data[i] = func(s->data[i]);
  }

  return result;
}

set *set_filter(set *s, set_filter_func func)
{
  set *result = set_create(s->capacity);
  for (u32 i = 0;
       i < result->capacity;
       ++i)
  {
    if (func(s->data[i]))
    {
      result->data[result->size++] = s->data[i];
    }
  }

  return result;
}