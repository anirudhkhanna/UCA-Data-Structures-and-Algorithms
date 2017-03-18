#include <stdio.h>

void mergeSort(int *A, int *B, int *C, int szA, int szB, int szC);

int main()
{
    int i, sizeA = 13, sizeB = 6;
    int sizeC = sizeA + sizeB;
    int A[13] = {1, 2 , 4, 10, 11, 12, 13, 15, 21, 100, 123, 135, 144};
    int B[6]  = {1, 3, 5, 6, 8, 9};
    int C[sizeC];
    
    mergeSort(A, B, C, sizeA, sizeB, sizeC);
    
    printf("\n\nMerge sorted: ");
    for(i = 0; i < sizeC; i++)
        printf("%d ", C[i]);

    printf("\n\n");
    return 0;
}

void mergeSort(int *A, int *B, int *C, int szA, int szB, int szC)
{
    int a = 0, b = 0, c = 0;
    
    while(c < szC)
    {        
        if(a >= szA)             C[c++] = B[b++];
        else if(b >= szB)        C[c++] = A[a++];
        else if(A[a] < B[b])     C[c++] = A[a++];
        else                     C[c++] = B[b++];
    }
}
