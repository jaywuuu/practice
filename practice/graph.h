#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

/* Graph using simple adjacency list */
typedef struct tagGraph {
	int nvertices;							/* number of verticies */
	int nedges;								/* number of edges */
	int directed;							/* 0 undirected, 1 directed */
	std::vector<std::vector<int>> adj;		/* adjacency list */
} Graph;

typedef enum {
	UNDIRECTED = 0,
	DIRECTED
} GraphDirection;

bool is_route(Graph *graph, int a, int b);
void add_edge(Graph *graph, int a, int b);
void add_verts(Graph *graph, int n);
void init_graph(Graph *graph, int direction);

#endif