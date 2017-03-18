#include <stdio.h>

void quickSort(int *A, int Left, int Right);

int main()
{
    int i, size;
    printf("\n\nEnter size of array: ");
    scanf("%d", &size);
    int A[size];

    printf("\n\nEnter %d elements: \n", size);
    for(i = 0; i < size; i++)
        scanf("%d", &A[i]);

    quickSort(A, 0, size-1);

    printf("\n\nQuick sorted: ");
    for(i = 0; i < size; i++)
        printf(" %d ", A[i]);

    printf("\n\n");
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x       = *y;
    *y       = temp;
}

void quickSort(int *A, int Left, int Right)
{
    int i, pos;

    if(Left < Right)
    {
        pos = Left;
        for(i = Left + 1; i <= Right; i++)
            if(A[i] < A[Left])
                swap(&A[++pos], &A[i]);   // When order is mismatched, increment pos and swap A[pos] with A[i]

        swap(&A[Left], &A[pos]);  // By now, pos is at the proper position for A[Left]. Actually, Left acts as pivot here! Now swap A[Left] with A[pos]

        quickSort(A, Left, pos-1);     // Sort left sub-list
        quickSort(A, pos+1, Right);    // Sort right sub-list
    }
}
