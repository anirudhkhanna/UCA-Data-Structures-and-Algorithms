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
int ** allocateArr(int, int);
void printArr(int **, int, int);

int knapsackSolution(int val[], int wt[], int N, int W) {
	int i, w;
	int **benefit = allocateArr(N + 1, W + 1); // Allocate a 2D array having total benefits for items cross weights combinations

	// Filling benefit[][] - permitted items vs permitted weight
	printf("\nFilling benefit[items][weights] row by row (i.e. per possible no of items) in bottom-up manner: \n\n");
	for(i = 0; i <= N; i++) {
		for(w = 0; w <= W; w++) {

			if(i == 0 || w == 0) // If 0 items are permitted or 0 weight is permitted
				benefit[i][w] = 0;

			else if(wt[i-1] <= w) // Weight of the item is within the currently permitted capacity. Now check if including it is beneficial or not.
				benefit[i][w] = max(val[i-1] + benefit[i-1][w-wt[i-1]], 
									benefit[i-1][w]);

			else // Weight of the item is not permitted
				benefit[i][w] = benefit[i-1][w];
		}

		printArr(benefit, N + 1, W + 1);
	}

	return benefit[N][W]; // Return the maximum benefit
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

int ** allocateArr(int R, int C) {
	int i, j;
	int **arr = (int **) malloc(R * sizeof(int *));
	for(i = 0; i < C; i++)
		arr[i] = (int *) malloc(C * sizeof(int));

	for(i = 0; i < R; i++)
		for(j = 0; j < C; j++)
			arr[i][j] = -1;

	return arr;
}

void printArr(int **arr, int R, int C) {
	int i, j;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++)
			printf("%d \t", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}
