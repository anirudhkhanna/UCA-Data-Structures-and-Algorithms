// A sorted array is shifted by some unknown offset. Eg: 5 7 9 13 18  ->  13 18 5 7 9
// Perform binary search in this scenario. Algorithm should be O(log n) only.

// (THIS SOLUTION HAS SOME BUGS)
#include <stdio.h>
#include <stdlib.h>

int binary_search(int *, int, int, int, int);

int arr(int *A, int pos, int size)  // To access the logically merged array accurately.
{
    return A[pos%size];
}

int main()
{
    int i, N, num, res;

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

    res = binary_search(A, 0, (2*N)-1, num, N); // Logically merge the array. Eg: 8 9 1 2 becomes 8 9 1 2 8 9 1 2
                                                //                                                    -------
    if(res == -1) printf("Element not found.\n\n");
    else printf("Found at index: %d\n\n", res);
    
    return 0;
}

int binary_search(int *A, int start, int end, int num, int size)
{
    int mid;

    if(start<=end)
    {
        mid = (start + end) / 2;

        if(arr(A, mid, size) == num)  // Or, just do A[mid%size] everywhere!
            return mid%size;
        else if(arr(A, mid, size) > num)
            return binary_search(A, start, mid-1, num, size);
        else
            return binary_search(A, mid+1, end, num, size);
    }

    return -1;
}

/*
Merging technique implemented here has some issues. For example, a condition when mid is same as the shifted index.

Eg: 7 8 2 4 5 6
And searched number is 2
Logically merged array becomes: 7 8 2 4 5 7 8 2 4 5

Searching takes place as follows:
1. mid = index 4 (value is 5). As 2 < 5, it will go to the left side, i.e. 7 8 2 4.
2. mid = index 1 (value is 8). As 2 < 8, it will go to the left side, but 2 is present at the right side of 8 actually.
Hence, the number will not be found, although it is actually present.

Solution:
Maintain a flag LEFT. Before calling the binary search function (the very first time), compare the value at mid with the searched number.
If the searched number is lesser, set LEFT = true, otherwise set LEFT = false.
Also, save this A[mid] value - call it original_mid.

Now, every loop has exactly 3 outcomes:
    The number is found at mid.
    The number is lesser => left-going loop.
    The number is greater => right-going loop.

If LEFT is true and it is a left-goig loop and A[mid] > original_mid: Change the direction - make it a right-going loop.
If LEFT is false and it is a right-going loop and A[mid] < original_mid: Change it to a left-going loop.

Something like this:
int binary_search(int* A, int start, int end, int num, int size, int original_mid, int LEFT)
{
    int mid;
    int leftGoing = 1;
    if(end < start) return -1;

    mid = (start + end) / 2;
    if(A[mid % size] == num) return mid % size;
    else if(A[mid % size] < num) leftGoing = 0;
    
    if(leftGoing && LEFT && A[mid % size] > original_mid) leftGoing = 0;
    if(!leftGoing && !LEFT && A[mid % size] < original_mid) leftGoing = 1;

    if(leftGoing) return binary_search(A, start, mid-1, num, size, original_mid, LEFT);
    else return binary_search(A, mid + 1, end, num, size, original_mid, LEFT);
}

int main()
{
    :
    :
    int original_mid = A[((2 * N - 1) / 2) % N];
    if(original_mid > num) LEFT = 1;
    else LEFT = 0;
    res = binary_search(...);
    :
    :
}
*/