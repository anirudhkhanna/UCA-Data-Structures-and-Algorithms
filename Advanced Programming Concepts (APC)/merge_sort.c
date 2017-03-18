#include <stdio.h>

void mergeSortRecursive(int *A, int left, int right);
void merge(int *A, int left, int mid, int right);

int main()
{
    int i, size;
    printf("\n\nEnter size of array: ");
    scanf("%d", &size);
    int A[size];

    printf("\n\nEnter %d elements: \n", size);
    for(i = 0; i < size; i++)
        scanf("%d", &A[i]);

    mergeSortRecursive(A, 0, size-1);

    printf("\n\nMerge sorted: ");
    for(i = 0; i < size; i++)
        printf(" %d ", A[i]);

    printf("\n\n");
    return 0;
}


void mergeSortRecursive(int *A, int left, int right)   // Keep on partitioning [in O(log n)] and then merge-sorting [in O(n)] the 2 parts.
{
    int mid;

    if(left < right)
    {
        mid = (left + right) / 2;
        mergeSortRecursive(A, left, mid);       // Partition
        mergeSortRecursive(A, mid+1, right);    // Partition

        merge(A, left, mid, right);             // Merge sort
    }
}

void merge(int *A, int left, int mid, int right)       // Merge sorting the array partitions A[left to mid] and A[mid+1 to right].
{
    int B[right+1];

    int i = left, j = mid+1, k;

    for(k = left; k <= right; k++)
    {
        if(i > mid)               B[k] = A[j++];    // Left array was exhausted. Copy right array directly.
        else if(j > right)        B[k] = A[i++];    // Right array was exhausted. Copy left array directly.
        else if(A[i] < A[j])      B[k] = A[i++];
        else                      B[k] = A[j++];
    }

    for(k = left; k <= right; k++)
        A[k] = B[k];
}
