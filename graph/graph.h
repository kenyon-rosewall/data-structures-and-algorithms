#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include "types.h"
#include "list/single_linked_list.h"

// 
// Graphs
//
// I chose the "id" of the graph node to be an unsigned 32-bit int, assuming that in this 
// implementation, they stand for the ids of the nodes rather than a place to store any random
// type of data, like a string. But again, you could easily update the id data type and a few
// methods to extend this to be any data type.
//
// To store the nodes sparsely, I chose to implement an array of single linked lists to represent
// the nodes which are connected. The alternative would be to create an two-dimensional array,
// which grows exponentially as the nodes grow. Eventually it becomes hard to search. Also, this
// graph is directed. You could implement undirected by adding both directions and adjusting when
// edge_count gets incremented/decremented. It would be a little work, but it's relatively
// trivial.
//
// I was also going to make the graphs weighted at the beginning, but since I decided to utilize
// the single linked list from earlier, I didn't conveniently have another property to store the 
// weight. Of course, the easiest way to do this would be to just create a single linked list
// with an extra property that help the weight of that directed edge. Then you could write some
// methods to calculate the cost of traveling certain paths. Currently, consider all edges to be
// equal to 1.
// 
// I wasn't exactly sure of how I wanted to return neighbors. In a modern language, I would definitely
// just return an array or list of integers that would be sized appropriately. That's not possible 
// exactly in C, so I did something a little experimental for me. I tried to do something as close
// as possible to that rather then just return an array that was the same as the size of nodes
// and a valid nodes were from 0 to neighbor count - 1 and everything else -1. It just felt bad.
// So I went with a dynamically allocated array that reallocates based on how big it gets. Then
// I add a sentinel of sorts to mark the end of the array by adding one more element as -1. Then
// you can loop through the array until the element is equal to -1.
// 

// 
// TODO
// * Add weight
// * Implement error handling for realloc returning NULL
// * Matrix into a graph
// * Graph searching functions
// * Detect any and all cycles in the graph
// * Shortest path between two nodes (considering weight too, Dijkstra's, DFS, etc )
//

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
void graph_dot(graph* g);

b32 graph_adjacent(graph* g, u32 x, u32 y);
i32* graph_neighbors(graph* g, u32 x);

void graph_add_node(graph* g, u32 x);
void graph_remove_node(graph* g, u32 x);
void graph_add_edge(graph* g, u32 x, u32 y);
void graph_remove_edge(graph* g, u32 x, u32 y);

u32 graph_get_number_of_nodes(graph* g);
u32 graph_get_number_of_edges(graph* g);

#endif // !GRAPH_H