/* Prim's Minimum Spanning Tree Algorithm (also called DJP algorithm, Jarník's algorithm, Prim-Jarník algorithm, or Prim-Dijkstra algorithm)

   Spanning Trees and Minimum Spanning Tree:
   Given a connected and undirected graph, a spanning tree is a subgraph that connects all the vertices together and is a tree (no loops, no circuits and no self-loops). A graph can have many spanning trees.
   A Minimum Spanning Tree (MST) for a weighted, connected and undirected graph is a spanning tree that has the mimimum total weight (total weight = sum of the weights of each edge).
   For a graph G = (V, E), its MST will have V vertices and (V-1) edges.

   Applications:
   Network design (min cost of lines to connect all systems), connecting different cities, approximately solving the travelling salesman problem, and etc.

   Prim's MST Algorithm:
   1. Create a set that keeps track of the vertices already included in the MST.
   2. Assign initial distances to all the vertices in the graph. Initialize all distances as INFINITE, but for the first vertex assign distance as 0 so that it is picked initially.
   3. While the MST set does not include all the vertices,
      a. Pick a vertex u which has minimum distance and is not already there in the MST set.
      b. Include u in the MST set.
      c. Update distances of the adjacent vertices of u.
         For every adjacent vertex v, if distance of the edge (u to v) is less than the previous distance of v, update the distance as the distance of (u to v).

   Time Complexity:
   O(V^2) when using a VxV adjacency matrix to represent the graph.
   O(E log V) when using an adjacency list to represent the graph, and taking help of a binary heap.

   Example:
           10                 10
        0------1           0-----1
        | \    |     MST    \
       6|  \5  |15   ==>     \5     (Weight = 19)
        |   \  |              \
        |    \ |               \
        2------3          2-----3
           4                4
*/

#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

// find a vertex having minimum distance out of the vertices not yet included in the MST
int minVertex(int dist[], bool mstSet[], int V) {
	int minDist = INT_MAX, minV = -1;
	for(int v = 0; v < V; v++)
		if(mstSet[v] == false && dist[v] < minDist)
			minDist = dist[v], minV = v;
	return minV;
}

// finding MST using Prim's algorithm
void PrimMST(int **graph, int V) {
	int totalWeight = 0;
	int parent[V]; // store the MST (each vertex and its parent associated)
	int dist[V]; // distance values of all the vertices
	bool mstSet[V]; // track the vertices included in the MST

	// initialize distances as infinite and MST set markings as false
	for(int v = 0; v < V; v++)
		dist[v] = INT_MAX, mstSet[v] = false;

	// to include the first vertex in the MST in the beginning
	dist[0] = 0; // lowest distance
	parent[0] = -1; // it is the root, therefore no parent

	// till all the vertices are processed, run the algorithm
	for(int counter = 0; counter < (V - 1); counter++) {
		int u = minVertex(dist, mstSet, V); // pick the minimum distance vertex that is not yet included
		mstSet[u] = true; // include it in the MST

		for(int v = 0; v < V; v++) { // revise the distances and parents of adjacent vertices of u which are not already in the MST (as now, the path can go through u)
			if(graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < dist[v]) // if there is an edge (u to v) and v is not in the MST set and distance to v via u is less than v's distance mentioned in the distance array
				dist[v] = graph[u][v], parent[v] = u; // update distance of v as the distance of the edge from u to v, and parent of v (edge-via) as u
		}
	}

	// display the result
	cout << "\nEdges of the MST along with their weights: \n";
	totalWeight = 0;
	for(int i = 1; i < V; i++) {
		cout << parent[i] << " - " << i << " \t(" << graph[parent[i]][i] << ") \n";
		totalWeight += graph[parent[i]][i];
	}
	cout << "\nWeight of the MST = " << totalWeight << "\n";
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
		int src, dest, weight;
		cout << "Source, destination and weight respectively for edge " << e + 1 << ": \n";
		cin >> src >> dest >> weight;
		graph[src][dest] = weight;
		graph[dest][src] = weight;
	}

	cout << "\nGraph's adjacency matrix: \n";
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++)
			cout << graph[i][j] << "\t";
		cout << "\n";
	}

	PrimMST(graph, V);

	cout << "\n";
	return 0;
}
