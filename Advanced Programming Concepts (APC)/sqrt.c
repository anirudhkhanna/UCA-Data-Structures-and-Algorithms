/* Find square root of given number up to nearest integer.
   Eg. root(11) = 3
       root(16) = 4
*/

#include <stdio.h>

/* O(log2(N)) SOLUTION (USING BINARY SEARCH): */

int root(int num)
{
    if(num == 1)    return 1;
    else            return root_binary_search(0, num/2, num);
}

int root_binary_search(long start, long end, int num)
{
    long long int mid;
    if(start <= end)
    {
        mid = (start+end)/2;
        if((mid*mid) <= num && ((mid+1)*(mid+1)) > num)
            return (int)mid;
        else if((mid*mid) > num)
            return root_binary_search(0, mid-1, num);
        else
            return root_binary_search(mid+1, end, num);
    }
    else
        return -1;
}


/* O(N) SOLUTION:

int root(int num)
{
    if(num == 1)
        return 1;

    long int i=0;
    while(i<=num/2 && i*i<=num)
        i++;
    return i-1;
}
*/


int main()
{
    int num, res;

    printf("\n\nEnter number: ");
    scanf("%d", &num);
    while(!(num < 0))
    {
        res = root(num);
        printf("\nroot(%d) = %d\n", num, res);

        printf("\n\nEnter number: ");
        scanf("%d", &num);
    }
    return 0;
}
