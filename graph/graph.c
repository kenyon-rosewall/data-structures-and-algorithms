#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

i32 graph_index_of(graph *g, u32 x)
{
  i32 index = -1;
  if (g != NULL)
  {
    for (u32 i = 0;
         i < g->node_count;
         ++i)
    {
      if (g->nodes[i]->id == x)
      {
        index = i;
      }
    }
  }

  return index;
}

graph *graph_create(u32 number_of_nodes)
{
  graph *g = (graph *)malloc(sizeof(graph));
  g->edge_count = 0;
  g->node_count = number_of_nodes;
  g->node_capacity = number_of_nodes;
  g->node_capacity_seed = number_of_nodes;
  g->nodes = (graph_node **)malloc(number_of_nodes * sizeof(graph_node *));

  for (u32 i = 0;
       i < number_of_nodes;
       ++i)
  {
    g->nodes[i] = (graph_node *)malloc(sizeof(graph_node));
    g->nodes[i]->id = i;
    g->nodes[i]->adjacency_list = *(sll_create());
  }

  return g;
}

void graph_destroy(graph *g)
{
  if (g != NULL)
  {
    for (u32 i = 0;
         i < g->node_count;
         ++i)
    {
      sll_destroy(&g->nodes[i]->adjacency_list);
      free(g->nodes[i]);
    }

    if (g->nodes != NULL)
    {
      free(g->nodes);
    }

    free(g);
  }
}

void graph_dot(graph *g)
{
  if (g != NULL)
  {
    printf("digraph G {\n");

    for (u32 i = 0;
         i < g->node_count;
         ++i)
    {
      sll_node *current = g->nodes[i]->adjacency_list;
      while (current != NULL)
      {
        printf("\t%d -> %ld;\n", g->nodes[i]->id, current->data);
        current = current->next;
      }
    }

    printf("}\n");
  }
}

b32 graph_adjacent(graph *g, u32 x, u32 y)
{
  b32 result = false;
  if (g != NULL)
  {
    i32 i = graph_index_of(g, x);
    if (i >= 0)
    {
      result = (sll_search(&g->nodes[i]->adjacency_list, y) >= 0);
    }
  }

  return result;
}

i32 *graph_neighbors(graph *g, u32 x)
{
  u32 count = 0;
  u32 capacity_seed = 4;
  u32 capacity = capacity_seed;
  i32 *neighbors = (i32 *)malloc(capacity * sizeof(i32));

  if (g != NULL)
  {
    for (u32 i = 0;
         i < g->node_count;
         ++i)
    {
      if (graph_adjacent(g, x, i) || graph_adjacent(g, i, x))
      {
        if (count == capacity)
        {
          capacity += capacity_seed;
          neighbors = (i32 *)realloc(neighbors, capacity * sizeof(i32));
        }
        neighbors[count++] = i;
      }
    }
  }

  if (count == capacity)
  {
    ++capacity;
    neighbors = (i32 *)realloc(neighbors, capacity * sizeof(i32));
  }
  neighbors[count] = -1;

  return neighbors;
}

void graph_add_node(graph *g, u32 x)
{
  i32 new_index = -1;
  if (g != NULL && graph_index_of(g, x) == -1)
  {
    if (g->node_count == g->node_capacity)
    {
      g->node_capacity += g->node_capacity_seed;
      g->nodes = (graph_node **)realloc(g->nodes, g->node_capacity * sizeof(graph_node *));
    }
    new_index = g->node_count++;
    g->nodes[new_index] = (graph_node *)malloc(sizeof(graph_node));
    g->nodes[new_index]->id = x;
    g->nodes[new_index]->adjacency_list = *(sll_create());
  }
}

void graph_remove_node(graph *g, u32 x)
{
  for (u32 i = 0;
       i < g->node_count;
       ++i)
  {
    if (graph_adjacent(g, g->nodes[i]->id, x))
    {
      graph_remove_edge(g, g->nodes[i]->id, x);
    }
  }

  i32 index = graph_index_of(g, x);
  if (index >= 0)
  {
    for (u32 i = index + 1;
         i < g->node_count;
         ++i)
    {
      g->nodes[i - 1] = g->nodes[i];
    }

    free(g->nodes[g->node_count]);
  }

  g->node_count--;
}

void graph_add_edge(graph *g, u32 x, u32 y)
{
  if (g != NULL)
  {
    i32 index = graph_index_of(g, x);
    if (index >= 0)
    {
      u32 position = sll_search(&g->nodes[index]->adjacency_list, y);
      if (position == -1)
      {
        sll_push(&g->nodes[index]->adjacency_list, y);
        g->edge_count++;
      }
    }
  }
}

void graph_remove_edge(graph *g, u32 x, u32 y)
{
  if (g != NULL)
  {
    i32 index = graph_index_of(g, x);
    if (index >= 0)
    {
      u32 x_position = sll_search(&g->nodes[index]->adjacency_list, y);
      if (x_position >= 0)
      {
        sll_remove(&g->nodes[index]->adjacency_list, x_position);
        g->edge_count--;
      }
    }
  }
}

u32 graph_get_number_of_nodes(graph *g)
{
  u32 count = 0;
  if (g != NULL)
  {
    count = g->node_count;
  }

  return count;
}

u32 graph_get_number_of_edges(graph *g)
{
  u32 count = 0;
  if (g != NULL)
  {
    count = g->edge_count;
  }

  return count;
}