/* Floyd-Warshall Algorithm for All Pairs Shortest Paths

   Find shortest distances between every pair of vertices in a given weighted, directed graph.

   Floyd-Warshall APSP Algorithm:
   The Floyd-Warshall algorithm can find all pairs shortest paths in a weighted graph with positive or negative weights (but with no negative cycles).
   We initialize the solution matrix the same as the input graph's adjacency matrix in the beginning.
   Then we keep updating the solution matrix by considering all vertices one by one as an intermediate vertex between any given pair.
   The idea is to pick a vertex and update all shortest paths which include the picked vertex as an intermediate vertex in the shortest path.

   When we pick a vertex k as an intermediate vertex, we already have considered the vertices {0 to k-1} as intermediate vertices.
   For every pair of src and dest (i, j) vertices, there are two possible cases:
   1. k is not an intermediate vertex in shortest path from i to j. Keep the value of dist[i][j] as it is.
   2. k is an intermediate vertex in shortest path from i to j. Update the value of dist[i][j] as dist[i][k] + dist[k][j].

       i ------ k ----- j

   Time Complexity:
   O(V^3) as we have three nested loops.

   Example:
             10
       (0) -----> (1)          Graph's adjacency matrix:        Minimum distances matrix:
        |         /|\          0      10     INF    5           0      9      8      5
      5 |          |           INF    0      INF    INF         INF    0      INF    INF
        |          | 1         INF    1      0      INF         INF    1      0      INF
       \|/         |           INF    INF    3      0           INF    4      3      0
       (3) -----> (2)
             3
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

#define INF (INT_MAX / 2)

// finding all pairs shortest paths using Floyd-Warshall algorithm
void FloydWarshallAPSP(int **graph, int V) {
	int dist[V][V]; // solution matrix for having shortest distances between all pairs of vertices

	// initialize solution matrix as the input graph's matrix, as initially shortest distances consider no intermediate vertex
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	// for every src to dest pair (i, j) pick vertices one by one as intermediate k
	// before the start of an iteration, the shortest distances between all pairs consider only the vertices in the set {0, 1, 2, .. , k-1} as intermediate vertices
	// after the end of an iteration, vertex k is also considered and added to the set of intermediate vertices so that it becomes {0, 1, 2, .. , k}, and the shortest distances are updated where needed

	// intermediate vertex k
	for(int k = 0; k < V; k++) {
		// vertex i from pair (i, j)
		for(int i = 0; i < V; i++) {
			// vertex j from pair (i, j)
			for(int j = 0; j < V; j++) {
				// check if vertex k should be in the shortest path from i to j
				if(dist[i][k] + dist[k][j] < dist[i][j]) {
					// update the shortest distance if needed
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// display the result
	cout << "\nMinimum distances matrix: \n";
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			if(dist[i][j] == INF)
				printf("%-7s", "INF");
			else
				printf("%-7d", dist[i][j]);
		}
		cout << "\n";
	}
}

int main() {
	int V, E;
	cout << "\nEnter the number vertices and the number of edges respectively: \n";
	cin >> V >> E;
	int **graph = new int *[V];
	for(int i = 0; i < V; i++)
		graph[i] = new int[V];

	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			if(i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;

	cout << "\nEnter the details of " << E << " directed edge(s). \n";
	for(int e = 0; e < E; e++) {
		int src, dest, weight;
		cout << "Source, destination and weight respectively for edge " << e + 1 << ": \n";
		cin >> src >> dest >> weight;
		graph[src][dest] = weight;
	}

	cout << "\nGraph's adjacency matrix: \n";
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			if(graph[i][j] == INF)
				printf("%-7s", "INF");
			else
				printf("%-7d", graph[i][j]);
		}
		cout << "\n";
	}

	FloydWarshallAPSP(graph, V);

	cout << "\n";
	return 0;
}
