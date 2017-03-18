#include <stdio.h>

/* Function to calculate x raised to the power y in O(N): */
long long power(int x, unsigned int y)
{
    if(y == 0)
        return 1;

    if(y%2 == 0)                       // Exponent is even
        return power(x, y/2) * power(x, y/2);
    else                               // Exponent is odd
        return x * power(x, y/2) * power(x, y/2);
}

/* Function to calculate x raised to the power y in O(log N): */
/* Above function can be optimized to O(logn) by calculating power(x, y/2) only once and storing it. */
long long pow_optimized(int x, unsigned int y)
{
    if(y == 0)
        return 1;

    long long temp = pow_optimized(x, y/2);   // Store calculated power x^(y/2)
    if(y%2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

/* Extended the above power function to work for floating-point x and negative y values: */
float pow_float(float x, int y)
{
    float temp;
    if(y == 0)
       return 1;

    temp = pow_float(x, y/2);
    if (y%2 == 0)
        return temp * temp;
    else
    {
        if(y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

/* Main function: */
int main()
{
    int A;
    unsigned int B;
    float AA;
    int BB;

    while(1)
    {
        printf("\nEnter A, B to find A^B: \n");
        scanf("%d %u", &A, &B);

        printf("\npower(%d, %d) = %lld\n", A, B, power(A, B));
        printf("\npow_optimized(%d, %d) = %lld\n", A, B, pow_optimized(A, B));

        printf("\n\nEnter floating A, and negative B to find A^B: \n");
        scanf("%f %d", &AA, &BB);

        printf("\npow_float(%f, %d) = %f\n", AA, BB, pow_float(AA, BB));

        printf("\n\t*****\n");
    }
}
