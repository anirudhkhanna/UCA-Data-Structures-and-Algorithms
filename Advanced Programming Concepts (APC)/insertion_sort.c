#include <stdio.h>

int main()
{
    int N;
    printf("\nEnter size of the array: ");
    scanf("%d", &N);
    int A[N];
    int i, j, pivot;

    printf("\nEnter elements of the array: \n");
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);

    // Insertion sort:
    for(i = 1; i < N; i++)
    {
        pivot = A[i];
        for(j = i - 1; j >= 0; j--)
        {
            if(A[j] > pivot)
                A[j + 1] = A[j];
            else
                break;
        }

        A[j + 1] = pivot;
    }

    printf("\nSorted array: \n");
    for(i = 0; i < N; i++)
        printf("%d ", A[i]);

    printf("\n\n");
    return 0;
}
