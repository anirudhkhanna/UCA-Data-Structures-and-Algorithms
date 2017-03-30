/* Optimal binary search tree (Optimal BST) or weight-balanced binary tree:
   
   A binary search tree which provides the smallest possible expected search time for given access probabilities.
   Optimal BSTs are generally divided into two types: static (fixed) and dynamic (changeable).

   Given a sorted array of keys (0 to n-1) and an array of their corresponding search frequencies (0 to n-1).
   Here freq[i] is the expected number of searches for keys[i].
   If a binary search tree is constructed such that the total cost of all the searches is as small as possible,
   what is the total cost?

   The cost of a BST node is the level of that node multiplied by its frequency. Level of root node is 1.

   Example:
   keys[] = {10, 12}
   freq[] = {34, 50}
   There can be two possible BSTs:
      10                       12
       \                       /
       12                     10
      (I)                    (II)

   Frequency of searches for 10 and 12 are 34 and 50 respectively.
   The cost of tree (I) is 34*1 + 50*2 = 134
   The cost of tree (II) is 50*1 + 34*2 = 118
   Therefore, tree (II) is optimal BST and the cost is 118.

   SOLUTION USING OPTIMAL SUBSTRUCTURE:
   The optimal cost can be recursively calculated using the following formula:
   obstCost(i, j) = [for r = i..j] MIN{obstCost(i, r-1) + obstCost(r+1, j)} + sumitoj,
   where sumitoj = [for k = i..j] SUMMATION{freq[k]}

   We need to calculate obstCost(0, n-1) to find the result.
   The idea of above formula is that we try all the nodes as root one by one (r varies from i to j).
   When we make the rth node as root, we recursively calculate the optimal cost from i to r-1 and r+1 to j.
   We also always add the sum of frequencies from i to j, because every search will go through root and one comparison will be done for every search.
*/

#include <iostream>
#include <climits>
using namespace std;

int obstCost(int *freq, int i, int j) {
	if(i > j) // No BST possible, therefore 0 cost
		return 0;

	if(i == j) // Only one node, therefore its cost
		return freq[i];

	// Sum of freq from i to j
	int sumitoj = 0;
	for(int k = i; k <= j; k++)
		sumitoj += freq[k];

	// Try out every node from i to j as root and decide the min cost
	int min = INT_MAX;
	int minroot = i;
	for(int r = i; r <= j; r++) {
		cout << "\n Trying as root: " << r + 1;

		int cost = obstCost(freq, i, r-1) + obstCost(freq, r+1, j) + sumitoj;
		if(cost < min) {
			min = cost;
			minroot = r;
		}
	}

	cout << "  >>  Decided root: " << minroot + 1 << " (cost: " << min << ")";
	return min;
}

int getOptimalCost(int *freq, int size) {
	// keys considered sorted here
	// just working with frequencies
	return obstCost(freq, 0, size-1);
}

int main() {
	int size, i, optimalCost;
	cout << "Enter number of nodes: ";
	cin >> size;

	int keys[size], freq[size];
	cout << "Enter keys: \n";
	for(i = 0; i < size; i++)
		cin >> keys[i];

	cout << "Enter frequencies: \n";
	for(i = 0; i < size; i++)
		cin >> freq[i];

	optimalCost = getOptimalCost(freq, size);
	cout << "\n\n Optimal cost = " << optimalCost << " \n\n";
	return 0;
}
