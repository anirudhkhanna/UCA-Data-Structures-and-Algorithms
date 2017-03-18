/*  Given an array, print the number of elements appearing more than once in it.

    Ip. 8
        1 2 3 5 2 2 2 1

    Op. 2 (as 1 and 2 repeat)
*/

#include <stdio.h>
#include <stdlib.h>
int CountRepElems(int N, int *A);

int main()
{
    int N, i;
    scanf("%d", &N);
    int A[N];
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);

    int c = CountRepElems(N, A);
    printf("\nNo. of repeating elems: %d\n\n", c);
}

int CountRepElems(int size, int *A)
{
    int i, count = 0, *table, max = A[0];

    for(i = 0; i < size; i++)   // Finding max element for table's size
        if(A[i] > max)
            max = A[i];
    
    table = calloc(max + 1, sizeof(int)); // We will store the occurences of elements in table[] so that we also get the number of occurrences
    for(i = 0; i < size; i++)
        table[A[i]]++;

    for(i = 0; i < max + 1; i++)
        if(table[i] > 1)
            count++;

    return count;
}
