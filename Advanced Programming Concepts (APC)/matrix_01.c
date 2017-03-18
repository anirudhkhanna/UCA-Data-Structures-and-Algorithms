/* Given an NxN Matrix having 0s and 1s as values.
   If a 0 is found at an index, replace all the values in that row and column with 0s.
   Eg: 1 0 1 1       0 0 0 0
       1 1 1 1  -->  0 0 1 1
       0 0 1 1       0 0 0 0
       1 1 1 1       0 0 1 1
*/

#include <stdio.h>
#include <stdlib.h>

void printarr(int **A, int R, int C)
{
    int i, j;
    for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

int main()
{
    int N, i, j, r, c;
    int nRow=0, nCol=0; // To encode positions of 0s in the matrix without much extra space
                        // (assuming N <= number of bits in the encoded variables)
    printf("\nEnter size N for an NxN matrix: ");
    scanf("%d", &N);
    int **A=(int **)malloc(N*sizeof(int *)), **B=(int **)malloc(N*sizeof(int *));
    for(i=0; i<N; i++)
    {
        A[i]=(int *)malloc(N*sizeof(int));
        B[i]=(int *)malloc(N*sizeof(int));
    }

    printf("\nEnter NxN matrix elements (0s and 1s): \n");
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            scanf("%d", &A[i][j]);

    printf("\nInput matrix: \n");
    printarr(A, N, N);

    for(i=0; i<N; i++) // Encoding positions of 0s in integer variables using bitwise operations
        for(j=0; j<N; j++)
            if(A[i][j]==0)
            {
                nRow=nRow|(1<<i);
                nCol=nCol|(1<<j);
            }

    printf("\nEncoded pos of 0s in nRow & nCol: %d %d", nRow, nCol);

    for(i=0; i<32; i++) // Setting required rows and cols to 0 by reading 0 positions from encoded variables
    {
        if((nRow>>i)&1==1)
        {
            for(c=0; c<N; c++)
            {
                A[i][c]=0;
            }
        }

        if((nCol>>i)&1==1)
        {
            for(r=0; r<N; r++)
            {
                A[r][i]=0;
            }
        }
    }

    printf("\nResult - set all those rows and columns to 0s which had a 0 value: \n");
    printarr(A, N, N);
    return 0;
}
