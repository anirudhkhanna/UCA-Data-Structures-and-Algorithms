/* Perform selection sort on an array and record the time taken in the operation. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void selectionSort(int *, int);

int main() {
	struct timeval start, end;
	long int us; // microseconds
	int *arr, i;
	const int SIZE = 10;
	arr = (int *) malloc(SIZE * sizeof(int));

	printf("\nArray: ");
	for(i = 0; i < SIZE; i++) {
		*(arr + i) = rand() % 10;
		printf("%d ", *(arr + i));
	}

	gettimeofday(&start, NULL);
	selectionSort(arr, SIZE);
	gettimeofday(&end, NULL);

	us = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);

	printf("\nSorted array: ");
	for(i = 0; i < SIZE; i++)
		printf("%d ", *(arr + i));

	printf("\nMicroseconds taken in the operation = %ld \n\n", us);

	return 0;
}

void selectionSort(int *arr, const int SIZE) {
	int i, j, min, temp;
	for(i = 0; i < SIZE - 1; i++) {
		min = i;
		for(j = i; j < SIZE; j++)
			if(arr[j] < arr[min])
				min = j;

		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}