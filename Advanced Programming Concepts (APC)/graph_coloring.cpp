/* Graph Coloring

   Assign colors to all the vertices of a graph such that no two adjacent vertices have the same color.
   The smallest number of colors needed to color a graph is called its chromatic number.
   For example, the following graph can be colored using at least 3 colors.

       (R)------(G)
        |     /  |
        |   (R)  |     R = Red
        |  /   \ |     G = Green
       (G)------(B)    B = Blue

   NP-Completeness:
   The problem of finding the chromatic number of a graph is NP-complete.
   NP-complete problems are the problems whose status is unknown. No polynomial time algorithm has yet been discovered for any NP-complete problem, nor has it been proved that no polynomial time algorithm exists for any of them.
   The interesting part is that if any one of the NP-complete problems can be solved in polynomial time, then all of them can be solved.
   There are approximate algorithms to solve these problems though, which do not guarantee the best solution but try to come as close as possible to the optimum value in a reasonable amount of time which is at most polynomial time.

   Applications:
   Making schedules and time tables without clash, assigning mobile radio frequencies, checking for bipartite graphs, solving sudoku, coloring maps.

   The Greedy Implementation:
   The basic greedy implementation does not guarantee to use minimum number of colors.
   But it does guarantee an upper bound on the number of colors - it never uses more than (d+1) colors, where d is the maximum degree of a vertex in the given graph.

   Time Complexity:
   O(V^2 + E) in worst case.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

// color the graph with greedy approach
void graphColoringGreedy(int **graph, int V) {
	int result[V]; // resulting colors of all the vertices
	bool isAssigned[V]; // to mark the colors which have been assigned to an adjacent vertex and can not be used for the current vertex (max V colors can be used)

	// assign a color to the first vertex
	result[0] = 0;

	// initialize the remaining V-1 vertices as having no colors assigned
	for(int v = 1; v < V; v++)
		result[v] = -1;

	// reset all the colors as available
	for(int c = 0; c < V; c++)
		isAssigned[c] = false;

	// assign colors to the remaining V-1 vertices
	for(int u = 1; u < V; u++) {

		// check all the adjacent vertices v and mark their colors as unavailable
		for(int v = 0; v < V; v++) {
			if(graph[u][v] == 1 && result[v] != -1) {
				int color = result[v];
				isAssigned[color] = true;
			}
		}

		// find the first available color (which is not assigned to any adjacent vertex)
		int color;
		for(color = 0; color < V; color++)
			if(isAssigned[color] == false)
				break;

		// assign that color to this vertex
		result[u] = color;

		// reset the assigned flags of colors for the next iteration
		for(int c = 0; c < V; c++)
			isAssigned[c] = false;
	}

	// display the result
	cout << "\nVertices and their color numbers: \n";
	for(int v = 0; v < V; v++)
		cout << v << " - color " << result[v] << " \n";
}

int main() {
	int V, E;
	cout << "\nEnter the number vertices and the number of edges respectively: \n";
	cin >> V >> E;
	int **graph = new int *[V];
	for(int i = 0; i < V; i++)
		graph[i] = (int *) calloc(V, sizeof(int));

	cout << "\nEnter the details of " << E << " edge(s). \n";
	for(int e = 0; e < E; e++) {
		int src, dest;
		cout << "Source and destination respectively for edge " << e + 1 << ": \n";
		cin >> src >> dest;
		graph[src][dest] = 1;
		graph[dest][src] = 1;
	}

	cout << "\nGraph's adjacency matrix: \n";
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++)
			printf("%-7d", graph[i][j]);
		cout << "\n";
	}

	graphColoringGreedy(graph, V);

	cout << "\n";
	return 0;
}
