// A sorted array is shifted by some unknown offset. Eg: 5 7 9 13 18  ->  13 18 5 7 9
// Perform binary search in this scenario. Algorithm should be O(log n) only.

#include <stdio.h>
#include <stdlib.h>

int find_offset(int *, int, int, int);
int binary_search(int *, int, int, int);

int main()
{
    int i, N, offset, num, res;

    printf("\nEnter size: ");
    scanf("%d", &N);
    int A[N];

    printf("\nEnter elements in shifted array: \n");
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for(i = 0; i < N; i++)
        printf("%d ", A[i]);

    printf("\nEnter number to search: ");
    scanf("%d", &num);

    offset = find_offset(A, N, 0, N-1);

    printf("\nOffset at index: %d\n", offset);

    if(offset == -1)
    {
        res = binary_search(A, 0, N-1, num);
        if(res == -1) printf("Element not found.\n\n");
        else printf("Found at index: %d\n\n", res);
    }
    else
    {
        res = binary_search(A, 0, offset, num);
        if(res == -1)
        {
            res = binary_search(A, offset+1, N-1, num);
            if(res == -1) printf("Element not found.\n\n");
            else printf("Found at index: %d\n\n", res);
        }
        else
        {
            printf("Found at index: %d\n\n", res);
        }   
    }
    
    return 0;
}

int find_offset(int *A, int size, int start, int end)
{
    int mid;

    if(start <= end)
    {
        mid = (start + end) / 2;

        if((mid+1 <= size-1) && (A[mid] > A[mid+1]))
            return mid;
        else if(A[mid] > A[size-1])
            return find_offset(A, size, mid+1, end);
        else
            return find_offset(A, size, start, mid-1);
    }

    return -1;
}

int binary_search(int *A, int start, int end, int num)
{
    int mid;

    if(start <= end)
    {
        mid = (start + end) / 2;

        if(A[mid] == num)
            return mid;
        else if(A[mid] > num)
            return binary_search(A, start, mid-1, num);
        else
            return binary_search(A, mid+1, end, num);
    }

    return -1;
}
