/* The knapsack problem or rucksack problem is a problem in combinatorial optimization.
   Given a knapsack size limit and a set of items, each with a weight and a profit value,
   determine the items to put in a collection (or knapsack) such that
   the total weight is less than or equal to the given knapsack limit and
   the total profit (or value) is as large as possible.
   0/1 knapsack: We can either leave the item or take the whole of it, either 0 or 1.
   
   It can be solved by dynamic programming.
   
   Optimal substructure:
   To consider all subsets of items, there can be two cases for every item.
   1. The item is included in the optimal set.
   2. It is not included in the optimal set.

   Therefore, the maximum value that can be obtained from n items is the greater of following two values.
   1. Maximum value obtained by n-1 items and W weight (excluding the nth item).
   2. Value of the nth item plus maximum value obtained by n-1 items and W minus weight of the nth item (including the nth item).
*/

#include <stdio.h>
#include <stdlib.h>

int max(int, int);

int knapsackSolution(int val[], int wt[], int N, int W) {
	if(N == 0 || W == 0)  // Base case
		return 0;

	if(wt[N-1] > W)  // If the wt of Nth item > Capacity W, then it can not be included in the optimal solution
		return knapsackSolution(val, wt, N-1, W);

	else  // Otherwise, return the maximum value from the two cases
		return max( val[N-1] + knapsackSolution(val, wt, N-1, W - wt[N-1]),  // Nth item included
					knapsackSolution(val, wt, N-1, W)                        // Nth item not included
				  );
}

int main() {
	int knapsackSize, N, i;
	printf("\nEnter the knapsack size: ");
	scanf("%d", &knapsackSize);
	printf("\nEnter the number of items: ");
	scanf("%d", &N);

	int values[N]; // Array of values
	int weights[N]; // Array of weights

	printf("\nEnter %d items' values and weights respectively: \n", N);
	for(i = 0; i < N; i++) {
		scanf("%d %d", &values[i], &weights[i]);
	}

	int totalValue = knapsackSolution(values, weights, N, knapsackSize);
	printf("\nTotal value accumulated: %d \n", totalValue);
	return 0;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

/* Sample recursion tree:
   In the following recursion tree, K() refers to the knapsack solution function. N and W are the two parameters.
   
   The recursion tree is for the following sample input:
   
   Knapsack size = 2 (So, initial W (capacity) = 2)
   Number of items = 3
   val[] = {10, 20, 30}
   wt[]  = {1,  1,  1}
   
   Recursion tree for knapsack of capacity 2 units and 3 items of 1 unit weight each:
   
                           K(3, 2)    --> K(N, W)
                         /         \
                       /             \
                     /                 \
               K(2, 2)                  K(2, 1)
              /       \                  /    \
            /           \              /        \
          K(1,2)      K(1,1)         K(1,1)     K(1,0)
          /  \         /   \          /   \
        /      \     /       \      /       \
   K(0,2)   K(0,1)  K(0,1) K(0,0)  K(0,1)   K(0,0)
   
*/