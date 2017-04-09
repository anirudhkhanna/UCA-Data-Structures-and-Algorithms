/* In a square matrix of 0s and 1s, a group of connected 1s is said to be an island. Two 1s can be considered connected if they are adjacent horizontally or vertically.
   Given such a matrix, find the number of islands in it.
   
   Example:
   1 0 0 0                     1 1 0 0
   1 1 0 0                     0 1 0 0
   0 0 1 1                     1 0 0 1
   0 0 1 1                     0 0 0 1
   Number of islands = 2       Number of islands = 3
*/

#include <stdio.h>
#include <stdlib.h>

void DFS(int **arr, int N, int i, int j) {
	// change the value to 0 to mark this cell as visited (or, use a separate matrix to mark visited cells)
	arr[i][j] = 0;

	// perform DFS on neighbouring 1s
	if((i + 1) < N && arr[i + 1][j] == 1)
		DFS(arr, N, i + 1, j);
	if((j + 1) < N && arr[i][j + 1] == 1)
		DFS(arr, N, i, j + 1);
	if((i - 1) >= 0 && arr[i - 1][j] == 1)
		DFS(arr, N, i - 1, j);
	if((j - 1) >= 0 && arr[i][j - 1] == 1)
		DFS(arr, N, i, j - 1);
}

int countIslands(int **arr, int N) {
	int i, j, count = 0;

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			if(arr[i][j] == 1) {
				count++;
				DFS(arr, N, i, j);
			}

	return count;
}

int main() {
	int N, i, j;
	printf("\nEnter size of the square matrix: ");
	scanf("%d", &N);
	int **arr = (int **) malloc(N * sizeof(int *));
	for(i = 0; i < N; i++)
		arr[i] = (int *) malloc(N * sizeof(int));

	printf("\nFill the matrix with 0s and 1s: \n");
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	printf("\nInput matrix: \n");
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++)
			printf("%-3d", arr[i][j]);
		printf("\n");
	}

	int islands = countIslands(arr, N);
	printf("\nNumber of islands: %d \n\n", islands);

	return 0;
}