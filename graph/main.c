#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "graph.h"

i32 main(i32 argc, char **argv)
{
  u32 node_count = 6;
  graph* g = graph_create(node_count);

  graph_add_edge(g, 0, 1);
  graph_add_edge(g, 1, 2);
  graph_add_edge(g, 1, 3);
  graph_add_edge(g, 2, 4);
  graph_add_edge(g, 3, 4);
  graph_add_edge(g, 3, 1);
  graph_add_edge(g, 4, 5);
  graph_add_edge(g, 5, 0);

  graph_add_node(g, 6);
  graph_add_edge(g, 4, 6);
  graph_add_edge(g, 6, 0);

  graph_remove_node(g, 5);

  // Shouldn't do anything
  graph_add_node(g, 4);
  graph_add_node(g, 5);
  graph_add_edge(g, 3, 5);

  graph_add_node(g, 72);
  graph_add_edge(g, 0, 72);

  b32 print_dot = false;
  if (argc == 2)
  {
    if (strcmp("dot", argv[1]) == 0)
    {
      print_dot = true;
    }
  }

  if (print_dot)
  {
    graph_dot(g);
  }
  else
  {
    u32 node_num = 6;
    i32* neighbors = graph_neighbors(g, node_num);
    printf("Neighbors of %d: ", node_num);
    for (u32 i = 0;
      neighbors[i] != -1;
      ++i)
    {
      printf("%d ", neighbors[i]);
    }

    printf("\n");
  }
  graph_destroy(g);

  return 0;
}