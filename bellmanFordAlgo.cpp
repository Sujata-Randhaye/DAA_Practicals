#include<iostream>
#include<limits.h>
using namespace std;

// The main function that finds shortest
// distances from src to all other vertices
// using Bellman-Ford algorithm. The function
// also detects negative weight cycle
// The row graph[i] represents i-th edge with
// three values u, v and w.
void BellmanFord(int graph[][3], int V, int E,
				int src)
{
	// Initialize distance of all vertices as infinite.
	int dis[V];
	for (int i = 0; i < V; i++)
		dis[i] = INT_MAX;

	// initialize distance of source as 0
	dis[src] = 0;

	// Relax all edges |V| - 1 times. A simple
	// shortest path from src to any other
	// vertex can have at-most |V| - 1 edges
	for (int i = 0; i < V - 1; i++) {

		for (int j = 0; j < E; j++) {
			if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] <
							dis[graph[j][1]])
				dis[graph[j][1]] = 
				dis[graph[j][0]] + graph[j][2];
		}
	}

	// check for negative-weight cycles.
	// The above step guarantees shortest
	// distances if graph doesn't contain
	// negative weight cycle. If we get a
	// shorter path, then there is a cycle.
	for (int i = 0; i < E; i++) {
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];
		if (dis[x] != INT_MAX &&
				dis[x] + weight < dis[y])
			cout << "Graph contains negative"
					" weight cycle"
				<< endl;
	}

	cout << "Vertex Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << "\t\t" << dis[i] << endl;
}

// Driver program to test above functions
int main()
{
	int V = 6; // Number of vertices in graph
	int E = 9; // Number of edges in graph

	// Every edge has three values (u, v, w) where
	// the edge is from vertex u to v. And weight
	// of the edge is w.
	int graph[][3] = { { 0, 1, 6 }, { 0, 2, 4 },
					{ 0, 3, 5 }, { 1, 4, -1 }, { 2, 1, -2 }, 
					{ 2, 4, 3 }, { 3, 2, -2 } ,
                    {3, 5, -1}, {4, 5 ,3}};

	BellmanFord(graph, V, E, 0);
	return 0;
}
