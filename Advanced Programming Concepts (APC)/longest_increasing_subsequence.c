/* Given an array of numbers, find the length of the longest increasing subsequence not necessarily contiguous.
   Eg. {50, 3, 10, 7, 40, 80, 5}
       LIS = {3, 7, 40, 80}
       Length of LIS = 4
   
   Let LIS(i) be the length of the longest increasing subsequence which includes the ith element (A[i]) as its last element.
   LIS(i) = 1 + MAX [for j = 0 to i-1] { LIS(j) }    if A[i] > A[j]
          = 1                                        if no such j exists
   
   Complexity: O(n^2)
*/

#include <stdio.h>

void longestIncreasingSubsequence(int arr[], int size) {
	int i, j, LIS[size];

	// build the LIS[] array for each element
	for(i = 0; i < size; i++) {
		int max = -1;

		for(j = 0; j < i; j++) {
			// check if the previous elements are smaller than the current element
			if(arr[i] > arr[j]) {
				// update the max from the previous entries
				if(max == -1 || max < LIS[j] + 1) {
					max = LIS[j] + 1;
				}
			}
		}

		if(max == -1) // no previous element was smaller than the ith element
			max = 1;

		LIS[i] = max; // put value in LIS[]
	}

	// find the max length from LIS[]
	int maxLength = -1;
	for(i = 0; i < size; i++)
		if(LIS[i] > maxLength)
			maxLength = LIS[i];

	printf("\nLength of the longest increasing subsequence = %d \n\n", maxLength);
}

int main() {
	int size, i;

	printf("\nEnter size of array: ");
	scanf("%d", &size);
	int arr[size];
	printf("\nEnter array elements: \n");
	for(i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	longestIncreasingSubsequence(arr, size);

	return 0;
}