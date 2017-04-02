/* Dijkstra's Shortest Path Algorithm

   Given a weighted graph and a source vertex, find shortest paths from the source to all the vertices in the graph.

   Dijkstra's SP Algorithm:
   (The algorithm doesn't work for graphs with negative weight edges. For those, use Bellman-Ford algorithm.)
   We can generate a shortest path tree (SPT) with the given source as root.
   We maintain two sets - one set containing the vertices included in the SPT, and the other set of the vertices not yet included.
   At every step, we find a vertex which is in the set of not-yet-included vertices and has minimum distance from the source.

   1. Create a set that keeps track of the vertices already included in the SPT (i.e. whose minimum distance from the source is finalized).
   2. Assign initial distances from the source to all the vertices in the graph. Initialize all distances as INFINITE, but for the source vertex assign distance as 0 (distance from the source to itself is zero, and it is picked initially).
   3. While the SPT set does not include all the vertices,
      a. Pick a vertex u which has minimum distance and is not already there in the SPT set.
      b. Include u in the SPT set.
      c. Update distances of the adjacent vertices of u.
         For every adjacent vertex v, if the distance from the source to u plus the distance of the edge (u to v) is less than the previous distance value of v, update the distance as the distance value of u + the distance of (u to v).

   Time Complexity:
   O(V^2) when using a VxV adjacency matrix to represent the graph.
   O(E log V) when using an adjacency list to represent the graph, and taking help of a binary heap.

   Example:
            3                 3
        0------1           0-----1
        | \    |     SPT         |
      8 |  \15 |2    ==>         |2
        |   \  |                 |
        |    \ |                 |
        2------3           2-----3 (for src = 3)
           4                  4
*/

#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

// find a vertex having minimum distance value and not yet included in the SPT set
int minVertex(int dist[], bool sptSet[], int V) {
	int minDist = INT_MAX, minV = -1;
	for(int v = 0; v < V; v++)
		if(sptSet[v] == false && dist[v] < minDist) {
			minDist = dist[v];
			minV = v;
		}
	return minV;
}

// finding shortest paths using Dijkstra's algorithm
void DijkstraSP(int **graph, int V, int src) {
	int parent[V]; // store the edges of the SPT (each vertex and its parent associated)
	int dist[V]; // shortest distances from the source to all the vertices
	bool sptSet[V]; // track the vertices included in the SPT

	// initialize distances as infinite and SPT set markings as false
	for(int v = 0; v < V; v++) {
		dist[v] = INT_MAX;
		sptSet[v] = false;
	}

	// to include the source vertex in the SPT first
	dist[src] = 0; // distance of src to itself is zero
	parent[src] = -1; // src is the root, therefore no parent

	// till all the vertices are processed, run the algorithm
	for(int counter = 0; counter < (V - 1); counter++) {
		int u = minVertex(dist, sptSet, V); // pick the minimum distance vertex that is not yet included
		sptSet[u] = true; // include it in the SPT

		for(int v = 0; v < V; v++) { // revise the distances and parents of adjacent vertices of u which are not already in the SPT (as now, the shortest path can go through u)
			if(graph[u][v] != 0 && sptSet[v] == false && dist[u] != INT_MAX && (dist[u] + graph[u][v]) < dist[v]) { // if there is an edge (u to v) and v is not in the SPT set and total distance from src to v via u is less than v's distance mentioned in the distance array
				dist[v] = dist[u] + graph[u][v]; // update distance of v as the distance from src to u plus the distance from u to v
				parent[v] = u; // update parent of v (edge-via) as u
			}
		}
	}

	// display the result
	cout << "\nVtx \tMin dist from src \n";
	for(int i = 0; i < V; i++)
		cout << i << " \t" << dist[i] << " \n";

	cout << "\nEdges of the SPT: \n";
	for(int i = 0; i < V; i++)
		if(i != src)
			cout << parent[i] << " - " << i << " \n";
}

int main() {
	int V, E, src;
	cout << "\nEnter the number vertices and the number of edges respectively: \n";
	cin >> V >> E;
	int **graph = new int *[V];
	for(int i = 0; i < V; i++)
		graph[i] = (int *) calloc(V, sizeof(int));

	cout << "\nEnter the details of " << E << " edge(s). \n";
	for(int e = 0; e < E; e++) {
		int src, dest, weight;
		cout << "Source, destination and weight respectively for edge " << e + 1 << ": \n";
		cin >> src >> dest >> weight;
		graph[src][dest] = weight;
		graph[dest][src] = weight;
	}

	cout << "\nEnter the source vertex: \n";
	cin >> src;

	cout << "\nGraph's adjacency matrix: \n";
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++)
			cout << graph[i][j] << "\t";
		cout << "\n";
	}

	DijkstraSP(graph, V, src);

	cout << "\n";
	return 0;
}
