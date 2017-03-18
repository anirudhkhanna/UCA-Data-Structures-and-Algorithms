#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, i, j, mul=1;
	printf("\nEnter size: ");
	scanf("%d", &N);
	
	int *A=(int*)malloc(N*sizeof(int));
	int *B=(int*)malloc(N*sizeof(int));
	
	printf("\nEnter array: \n");
	for(i=0; i<N; i++)
	{
		scanf("%d", &A[i]);
		mul*=A[i];
	}
	
	for(i=0; i<N; i++)
	{
		B[i]=mul/A[i];
	}

	printf("\nArray such that Bi = ((Product of A0 to An-1) / Ai): \n");
	for(i=0; i<N; i++)
		printf("%d ", B[i]);

	printf("\n\n");
	return 0;
}
