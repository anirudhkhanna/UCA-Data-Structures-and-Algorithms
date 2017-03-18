#include <stdio.h>

int binary_search(int *A, int start, int end, int num)
{
    int mid;

    if(start <= end)
    {
        mid = (start + end) / 2;

        if(A[mid] == num)
            return mid;
        else if(A[mid] > num)
            return binary_search(A, start, mid - 1, num);
        else
            return binary_search(A, mid + 1, end, num);
    }

    return -1;
}


int main()
{
    int N, i, ind, num;

    printf("\nEnter size: ");
    scanf("%d", &N);
    int A[N];

    printf("\nEnter elements: ");
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for(i = 0; i < N; i++)
        printf("%d ", A[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &num);

    ind = binary_search(A, 0, N-1, num);

    if(ind != -1)
        printf("\nFound at index %d\n\n", ind);
    else
        printf("\nNot found\n\n");
    
    return 0;
}
