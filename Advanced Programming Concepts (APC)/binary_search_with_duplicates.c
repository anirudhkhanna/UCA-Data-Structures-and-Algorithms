/* Given an array in ascending order which may contain some duplicate elements, 
 * find the number of occurrences of a given element in O(log n) time.
 * Eg. [1, 3, 5, 5, 5]    Occurrences of 5 = 3
 *     [20, 20, 20]       Occurrences of 20 = 3
 *     [1, 2, 2, 6, 6]    Occurrences of 10 = 0
 */

#include <stdio.h>
#include <stdlib.h>

int findFirstIndexViaBinarySearch(int *arr, int size, int left, int right, int item) {
	if(left > right)
		return -1;

	int mid = ((right - left) / 2) + left;
	if(arr[mid] == item && (mid == 0 || arr[mid - 1] < item))
		return mid;
	else if(item <= arr[mid])
		return findFirstIndexViaBinarySearch(arr, size, left, (mid - 1), item);
	else
		return findFirstIndexViaBinarySearch(arr, size, (mid + 1), right, item);
}

int findLastIndexViaBinarySearch(int *arr, int size, int left, int right, int item) {
	if(left > right)
		return -1;

	int mid = ((right - left) / 2) + left;
	if(arr[mid] == item && (mid == (size - 1) || arr[mid + 1] > item))
		return mid;
	else if(item < arr[mid])
		return findLastIndexViaBinarySearch(arr, size, left, (mid - 1), item);
	else
		return findLastIndexViaBinarySearch(arr, size, (mid + 1), right, item);
}


int main() {
	int size, item, i;

	printf("\nEnter size of array: ");
	scanf("%d", &size);
	int *arr = (int *) malloc(size * sizeof(int));
	printf("\nEnter array elements in ascending order (may be with some duplicates): \n");
	for(i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	printf("\nEnter an element to find its no of occurrences: ");
	scanf("%d", &item);
	int lb = findFirstIndexViaBinarySearch(arr, size, 0, (size - 1), item);
	int ub = findLastIndexViaBinarySearch(arr, size, lb, (size - 1), item);

	int occurrences = ub - lb + 1;
	if(lb == -1 && ub == -1)
		occurrences = 0;

	printf("\n\tFirst Index = %d", lb);
	printf("\n\tLast Index = %d", ub);
	printf("\n\tNo. of occurrences of %d = %d ", item, occurrences);

	printf("\n\n");
	return 0;
}