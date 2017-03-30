/* To find the kth smallest element in an array.
   We can use a modification of Quick Sort (Quick Select) which does the thing in ~ O(n) time.
*/

#include <stdio.h>
#include <stdlib.h>

int kthSmallestViaModifiedQuickSort(int *A, int Left, int Right);

int k;

int main()
{
    int elem, i, size;
    printf("\n\nEnter size of array: ");
    scanf("%d", &size);
    int A[size];

    printf("\n\nEnter %d elements: \n", size);
    for(i = 0; i < size; i++)
        scanf("%d", &A[i]);

    printf("\n\nEnter k for finding kth smallest element: ");
    scanf("%d", &k);

    elem = kthSmallestViaModifiedQuickSort(A, 0, size-1);

    printf("\n\nQuick sorted till kth smallest element is not found: ");
    for(i = 0; i < size; i++)
        printf(" %d ", A[i]);

    if(elem != -1)
        printf("\n\n%dth smallest elem: %d", k, elem);
    else
        printf("\n\n%dth smallest elem is not available.", k);

    printf("\n\n");
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x       = *y;
    *y       = temp;
}

int getRandomPivot(int L, int R)
{
    return (rand() % (R - L + 1)) + L;  // Return a random number in the range from L to R inclusive
}

int kthSmallestViaModifiedQuickSort(int *A, int Left, int Right)
{
    if(Left > Right)
        return -1;  // Not available

    int i, pos, pivot;
    pivot = getRandomPivot(Left, Right);
    swap(&A[Left], &A[pivot]);  // Swap Left element with the random pivot element, then do Quick Sort where leftmost element acts as pivot

    pos = Left;
    for(i = Left + 1; i <= Right; i++)
        if(A[i] < A[Left])
            swap(&A[++pos], &A[i]);  // When order is mismatched, increment pos and swap A[pos] with A[i]

    swap(&A[Left], &A[pos]);         // By now, pos is at proper position for A[Left] (Left acts as pivot). Swap A[Left] with A[pos]

    if(pos == k - 1)       // Right position k is found
        return A[pos];
    else if (pos > k - 1)  // If current pivot's position pos is greater than k, recur for the left subarray
        return kthSmallestViaModifiedQuickSort(A, Left, pos-1);
    else                   // Else recur for the right subarray
        return kthSmallestViaModifiedQuickSort(A, pos+1, Right);
}
