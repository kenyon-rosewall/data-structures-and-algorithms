#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include "types.h"
#include "list/single_linked_list.h"

typedef struct graph_node graph_node;
struct graph_node
{
  u32 id;
  sll_node* adjacency_list;
};

typedef struct graph graph;
struct graph
{
  u32 node_capacity;
  u32 node_capacity_seed;
  u32 node_count;
  u32 edge_count;
  graph_node** nodes;
};

graph* graph_create(u32 number_of_nodes);
void graph_destroy(graph* g);
void graph_print(graph* g);

b32 graph_adjacent(graph* g, u32 x, u32 y);
i32* graph_neighbors(graph* g, u32 x);

void graph_add_node(graph* g, u32 x);
void graph_remove_node(graph* g, u32 x);
void graph_add_edge(graph* g, u32 x, u32 y);
void graph_remove_edge(graph* g, u32 x, u32 y);

u32 graph_get_number_of_nodes(graph* g);
u32 graph_get_number_of_edges(graph* g);

#endif // !GRAPH_H