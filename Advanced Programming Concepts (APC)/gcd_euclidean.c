// GCD (Greatest Common Divisor) or HCF (Highest Common Factor) of 2 numbers using Euclidean GCD algorithm.
// Works in logarithmic time.

#include <stdio.h>

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b;

    while(1)
    {
        printf("\nEnter 2 numbers to find their GCD: \n");
        scanf("%d %d", &a, &b);
        printf("GCD: %d \n\n", gcd(a, b));
    }

    return 0;
}
