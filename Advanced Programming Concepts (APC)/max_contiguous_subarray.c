/* Given an array of numbers, find the largest possible sum of a contiguous subarray.
   Eg. [1, 3, 5]                          Max sum = 9
       [-2, -3, 4, -1, -2, 1, 5, -3]      Max sum = 7
*/

#include <stdio.h>
#include <limits.h>

/* Kadane’s algorithm:
   Look for all positive contiguous segments of the array (max_ending_here is used for checking this).
   Keep track of the maximum sum contiguous segment among all positive segments (max_so_far is used for this).
   Each time we get a positive sum, compare it with max_so_far and update max_so_far if required.
*/
int maxSubarrayViaKadanesAlgo(int arr[], int size) {
	int i;
	int max_ending_here = 0;
	int max_so_far = INT_MIN;

	for(i = 0; i < size; i++) {

		max_ending_here = max_ending_here + arr[i];

		if(max_ending_here > max_so_far)
			max_so_far = max_ending_here;

		if(max_ending_here < 0)
			max_ending_here = 0;
	}

	return max_so_far;
}

int main() {
	int size, i;

	printf("\nEnter size of array: ");
	scanf("%d", &size);
	int arr[size];
	printf("\nEnter array elements: \n");
	for(i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	printf("\nMax contiguous subsequence sum = %d ", maxSubarrayViaKadanesAlgo(arr, size));
	printf("\n\n");
	return 0;
}