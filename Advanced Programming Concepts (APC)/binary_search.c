#include <stdio.h>

int binary_search(int *A, int N, int num)
{
    int start = 0, end = (N - 1), mid;
    
    while(start <= end)
    {
        mid = (start + end) / 2;

        if(A[mid] == num)
            return mid;
        else if(A[mid] > num)
            end = mid - 1;
        else
            start = mid + 1;
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

    ind = binary_search(A, N, num);
    
    if(ind != -1)
        printf("\nFound at index %d\n\n", ind);
    else
        printf("\nNot found\n\n");
    
    return 0;
}
