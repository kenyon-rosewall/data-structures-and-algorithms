#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

graph* graph_create(i32 number_of_nodes)
{
  graph* g = (graph*)malloc(sizeof(graph));
  if (g == NULL) 
  {
    return NULL;
  }
  g->node_count = number_of_nodes;
  
  g->list = calloc(sizeof(graph_node*), g->node_count);
  if (g->list == NULL)
  {
    free(g);
    return NULL;
  }

  return g;
}

void graph_destroy(graph* g)
{
  if (g->list == NULL)
  {
    free(g);
    return;
  }

  for (u32 i = 0;
    i < g->node_count;
    ++i)
  {
    if (g->list[i] != NULL)
    {
      free(g->list[i]);
    }
  }

  free(g->list);
  free(g);
}

void graph_print(graph* g)
{
  printf("digraph {\n");

  

  printf("}\n");
}

b32 graph_adjacent(graph* g, u32 x, u32 y)
{
  return true;
}

u32* graph_neighbors(graph* g, u32 x)
{
  u32* test = (u32*)malloc(sizeof(u32));
  return test;
}
