/* Graph Coloring Check

   Given a number M, check if a graph is M-colorable, i.e. at most M colors can be assigned to its vertices such that no two adjacent vertices have the same color.
   The smallest number of colors needed to color a graph is called its chromatic number.

   Applications:
   Making schedules and time tables without clash, assigning mobile radio frequencies, checking for bipartite graphs, solving sudoku, coloring maps.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int getSuitableColor(int **, int, int *, int, int);
void printResult(int *, int);

// try to color the graph with at most M colors
void graphColoringCheck(int **graph, int v, int *colorOf, int V, int M) {
	if(v == V)
		return;

	colorOf[v] = getSuitableColor(graph, v, colorOf, V, M);
	if(colorOf[v] == -1) {
		cout << "\nGraph is not " << M << "-colorable. \n";
		return;
	}
	if(v == V - 1) {
		cout << "\nGraph is " << M << "-colorable. \n";
		printResult(colorOf, V);
	}

	graphColoringCheck(graph, v + 1, colorOf, V, M);
}

int getSuitableColor(int **graph, int v, int *colorOf, int V, int M) {
	while(true) {
		colorOf[v] = colorOf[v] + 1;
		// if reached the limit M
		if(colorOf[v] == M)
			return -1;
		// check if this is a safe color
		int i;
		for(i = 0; i < V; i++) {
			if(graph[v][i] == 1 && colorOf[i] == colorOf[v])
				break;
		}
		// if this turns out to be a safe color
		if(i == V)
			return colorOf[v];
	}
}

void printResult(int *colorOf, int V) {
	cout << "\nVertices and their color numbers: \n";
	for(int v = 0; v < V; v++)
		cout << v << " - color " << colorOf[v] << " \n";
}

int main() {
	int V, E, M;
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

	cout << "\nEnter M to check if the graph is M-colorable: \n";
	cin >> M;

	cout << "\nGraph's adjacency matrix: \n";
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++)
			printf("%-7d", graph[i][j]);
		cout << "\n";
	}

	int *colorOf = new int[V];
	for(int i = 0; i < V; i++)
		colorOf[i] = -1;

	graphColoringCheck(graph, 0, colorOf, V, M);

	cout << "\n";
	return 0;
}
