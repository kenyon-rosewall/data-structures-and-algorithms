#pragma once

#ifndef SET_H
#define SET_H

#include "types.h"

//
// Sets
//
// Again, I decided to just go with a capacity-based idea to create a set. If you want to
// see dynamically growing objects, check out what I did with the graph data structure. Not
// much to talk about here. It is just an array with no repeating elements.
//
// I tried to use C++ STL's definition of a set for my implementation. But for fun, I added
// a more modern concept of set_map() and set_filter() which allow you to pass in a function
// to either perform an operation on each member or even return a subset based on a condition.
//

//
// TODO
// * Build set from an array with potential repeating elements
// * Create more set-theoretic operations like union, intersection, difference, etc.
// * Clear a set
// * Similar to map and filter, add a reduce or fold operation
// * Algorithmic stuff like nearest value, min, max, etc
//

typedef struct set set;
struct set
{
  i32 *data;
  u32 size;
  u32 capacity;
};
typedef i32 (*set_map_func)(i32);
typedef b32 (*set_filter_func)(i32);

set *set_create(u32 capacity);
void set_destroy(set *s);

b32 set_empty(set *s);
b32 set_full(set *s);
u32 set_size(set *s);
b32 set_contains(set *s, i32 value);

void set_print(set *s);

void set_add(set *s, i32 value);
void set_remove(set *s, i32 value);
set *set_map(set *s, set_map_func func);
set *set_filter(set *s, set_filter_func func);

#endif // !SET_H