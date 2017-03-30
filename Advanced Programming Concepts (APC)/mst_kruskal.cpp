/* Kruskal’s Minimum Spanning Tree Algorithm

   Spanning Trees and Minimum Spanning Tree:
   Given a connected and undirected graph, a spanning tree is a subgraph that connects all the vertices together and is a tree (no loops, no circuits and no self-loops). A graph can have many spanning trees.
   A Minimum Spanning Tree (MST) for a weighted, connected and undirected graph is a spanning tree that has the mimimum total weight (total weight = sum of the weights of each edge).
   For a graph G = (V, E), its MST will have V vertices and (V-1) edges.

   Applications:
   Network design (min cost of lines to connect all systems), connecting different cities, approximately solving the travelling salesman problem, and etc.

   Kruskal’s MST Algorithm:
   1. Sort all the edges in ascending order of their weights.
   2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
      If no cycle is formed, include this edge in the spaning tree. Otherwise, discard it.
   3. Repeat step 2 until there are (V-1) edges in the spanning tree.

   Time Complexity:
   O(E log E) or O(E log V).
   Sorting the edges takes O(E log E) time. After sorting, we iterate through all the edges and apply Union-Find algorithm to check for cycles. The find and union operations can take at most O(log V) time.
   So the overall complexity is O(E log E + E log V). The value of E can be at most V^2, and log V^2 = 2 log V, so O(log E) ~ O(log V).
   Therefore, the time complexity becomes O(E log E) or O(E log V).

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
using namespace std;

// structure for an edge
struct Edge {
	int src, dest, weight; // source vertex, destination vertex and weight of the edge
};

// structure for a graph
struct Graph {
	int V, E;   // number of vertices and number of edges
	Edge *edge; // array of edges
};

// allocating a new graph
Graph * createGraph(int V, int E) {
	Graph *graph = (Graph *) malloc(sizeof(Graph));
	graph -> V = V;
	graph -> E = E;
	graph -> edge = (Edge *) malloc(E * sizeof(Edge));
	return graph;
}

// find operation of Union-Find: find the subset of a given element i
int find(int parent[], int i) {
	if(parent[i] == -1) return i;
	else return find(parent, parent[i]);
}

// union operation of Union-Find: unite two given subsets
void Union(int parent[], int x, int y) {
	int xset = find(parent, x);
	int yset = find(parent, y);
	parent[xset] = yset;
}

// compare function for qsort-ing the array of edges
int cmpEdges(const void *a, const void *b) {
	Edge *e1 = (Edge *) a;
	Edge *e2 = (Edge *) b;
	return (e1 -> weight) > (e2 -> weight);
}

// finding MST using Kruskal's algorithm
void KruskalMST(Graph *graph) {
	int V = graph -> V;
	int E = graph -> E;
	int totalWeight = 0;
	Edge result[V]; // to store the resulting edges of the MST
	int e = 0, i = 0; // indexes used for result[] array and sorted edge[] array

	// sort the edges in edge[] array
	qsort(graph -> edge, E, sizeof(Edge), cmpEdges);

	// allocate memeory (parent[] array) for Union-Find (which is used to detect cycles)
	// and initialize all to -1 (no parent of any vertex, i.e. all disjoint sets)
	int parent[V];
	for(int v = 0; v < V; v++)
		parent[v] = -1;

	// take edges (in sorted order of weights) one by one and include an edge in the result if it does not form a cycle
	// do this till (V - 1) edges are included (which must be connecting all V vertices as there is no cycle)
	e = 0;
	i = 0;
	while(e < (V - 1)) {
		Edge curr_edge = graph -> edge[i];
		i++;

		int x = find(parent, curr_edge.src);
		int y = find(parent, curr_edge.dest);

		// if the src and dest of the edge are in the same subset, then there is a cycle, otherwise not
		if(x != y) {
			result[e] = curr_edge; // include the edge in MST
			e++;
			Union(parent, x, y); // unite the two subsets
		}
		// otherwise, the edge is discarded
	}

	// display the result
	cout << "\nEdges of the MST along with their weights: \n";
	totalWeight = 0;
	for(i = 0; i < e; i++) {
		cout << result[i].src << " - " << result[i].dest << " \t(" << result[i].weight << ") \n";
		totalWeight += result[i].weight;
	}
	cout << "\nWeight of the MST = " << totalWeight << "\n";
}

int main() {
	int V, E;
	cout << "\nEnter the number vertices and the number of edges respectively: \n";
	cin >> V >> E;
	Graph* graph = createGraph(V, E);

	cout << "\nEnter the details of " << E << " edge(s). \n";
	for(int e = 0; e < E; e++) {
		cout << "Source, destination and weight respectively for edge " << e + 1 << ": \n";
		cin >> graph -> edge[e].src;
		cin >> graph -> edge[e].dest;
		cin >> graph -> edge[e].weight;
	}

	KruskalMST(graph);

	cout << "\n";
	return 0;
}
