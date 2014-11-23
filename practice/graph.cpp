#include <queue>
#include "graph.h"

/* init */
void init_graph(Graph *graph, int direction) {
	graph->nvertices = 0;
	graph->nedges = 0;
	graph->directed = direction;
}

/* add n verticies */
void add_verts(Graph *graph, int n) {
	graph->nvertices = n;
	for (int i = 0; i < n; i++) {
		std::vector<int> node;
		graph->adj.push_back(node);
	}
}

/* adds edges between node a and node b */
/* if directed, only add edge to node a */
void add_edge(Graph *graph, int a, int b) {
	graph->adj[a].push_back(b);

	if (graph->directed == UNDIRECTED) {
		graph->adj[b].push_back(a);
	}

	graph->nedges++;
}

/* is there a route from node A to node B? */
/* apply BFS. Use a queue */
bool is_route(Graph *graph, int a, int b) {
	/* keep track of visited nodes */
	std::vector<bool> visited(graph->nvertices, false);
	std::queue<int> nodes;
	nodes.push(a);
	while (!nodes.empty()) {
		int node = nodes.front();
		nodes.pop();

		/* is this the target node? */
		if (node == b) return true;
		
		/* have we been here before? */
		if (visited[node] == false) {
			/* add connected nodes to queue */
			for (std::vector<int>::iterator it = graph->adj[node].begin();
				it != graph->adj[node].end(); it++) {
				nodes.push(*it);
			}

			/* set node to visited */
			visited[node] = true;
		}
	}

	return false;
}
