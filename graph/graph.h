#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include "types.h"

typedef struct graph_node graph_node;
struct graph_node
{
  u32 value;
  graph_node* next;
};

typedef struct graph graph;
struct graph
{
  u32 node_count;
  u32 edge_count;
  graph_node** list;
};

graph* graph_create(i32 number_of_nodes);
void graph_destroy(graph* g);
void graph_print(graph* g);

b32 graph_adjacent(graph* g, u32 x, u32 y);
u32* graph_neighbors(graph* g, u32 x);

b32 graph_add_vertex(graph* g, u32 x);
b32 graph_remove_vertex(graph* g, u32 x);
b32 graph_add_edge(graph* g, u32 x, u32 y, u32 value);
b32 graph_remove_edge(graph* g, u32 x, u32 y);

b32 graph_set_edge_value(graph* g, u32 x, u32 y, u32 value);
u32 graph_get_edge_value(graph* g, u32 x, u32 y);
u32 graph_get_number_of_nodes(graph* g);

#endif // !GRAPH_H