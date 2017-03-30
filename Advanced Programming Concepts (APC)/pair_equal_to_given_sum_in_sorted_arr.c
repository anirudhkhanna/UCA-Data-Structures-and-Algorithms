/* From a sorted array of numbers, find a pair whose sum is equal to a given value.
   
   Eg: [1, 3, 4, 6], Sum = 9
       Pair = (3, 6)
       [1, 3, 4, 6], Sum = 8
       Pair not found
*/

#include <stdio.h>

int main() {
	int N, Sum, i, j, a, b, found;
	printf("Enter the size of array: \n");
	scanf("%d", &N);
	int arr[N];
	printf("Enter sorted array: \n");
	for(i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	printf("Enter a sum value to find corresponding pair from the array: \n");
	scanf("%d", &Sum);

	i = 0, j = (N - 1), found = 0;
	while(i < j) {
		if(arr[i] + arr[j] == Sum) {
			a = arr[i];
			b = arr[j];
			found = 1;
			break;
		}
		else if(arr[i] + arr[j] < Sum)
			i++;
		else if(arr[i] + arr[j] > Sum)
			j--;
	}

	if(!found)
		printf("\nPair not found. \n\n");
	else
		printf("\nPair = (%d, %d) \n\n", a, b);

	return 0;
}
