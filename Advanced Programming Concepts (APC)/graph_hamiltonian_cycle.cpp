/* Hamiltonian Cycle

   A Hamiltonian path in a graph is such a path that visits each vertex exactly once.
   A Hamiltonian cycle (also known as Hamiltonian circuit) is a Hamiltonian path which forms a cycle.
   Determining whether such paths and cycles exist in graphs is the Hamiltonian path problem, which is NP-complete.

       0 -- 1 -- 2                        0 -- 1 -- 2
       |   / \   |                        |   / \   |
       |  /   \  |                        |  /   \  |
       | /     \ |                        | /     \ |
       3 ------- 4                        3         4
       Contains Hamiltonian cycles        No Hamiltonian cycle

   Applications: In computer graphics

   Time Complexity:
   With backtracking approach, we can find a solution in O(V!) in worst case.

   Let there be N vertices. In each recursive call, one of the remaining vertices is selected in worst case. So, the branch factor decreases by 1.
   Recursion in this case can be thought of as N nested loops where in each loop the number of iterations decreases by 1.
   T(N) = N * (T(N-1) + O(1))
        = N * (N-1) * (T(N-2) + O(1))
        = N * (N-1) * (N-2) * ... * 1
        = O(N!)
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

#define SOURCE 0

bool pathContains(vector<int>, int);
void printPath(vector<int>);

// find Hamiltonian cycle in the graph with backtracking
bool findHamiltonianCycle(int **graph, int V, int src, vector<int> path) {

	if(path.size() == V && graph[src][SOURCE] == 1) {
		path.push_back(SOURCE);
		cout << "\nHamiltonian cycle: ";
		printPath(path);
		return true;
	}

	for(int v = 0; v < V; v++) {
		if(graph[src][v] == 1 && !pathContains(path, v)) {

			path.push_back(v);
			cout << "Intermediate path: ";
			printPath(path);

			if(findHamiltonianCycle(graph, V, v, path) == true)
				return true;
			else
				path.pop_back();
		}
	}

	return false;
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

	vector<int> path;
	path.push_back(SOURCE);
	cout << "\n";
	bool doesExist = findHamiltonianCycle(graph, V, SOURCE, path);

	if(!doesExist)
		cout << "\nNo Hamiltonian cycle exists in the graph.\n";

	cout << "\n";
	return 0;
}

bool pathContains(vector<int> path, int v) {
	return find(path.begin(), path.end(), v) != path.end();
}

void printPath(vector<int> path) {
	for(vector<int>::iterator it = path.begin(); it != path.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";
}
