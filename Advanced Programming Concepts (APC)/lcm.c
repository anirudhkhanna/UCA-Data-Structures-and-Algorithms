// LCM (Least Common Multiple) of 2 numbers.
// 1. Using iteration
// 2. Using GCD

#include <stdio.h>

int lcm(int a, int b)
{
    int i, mul, big, small;
    big = (a > b) ? a : b;
    small = (a < b) ? a : b;
    i = 1;
    while(1)
    {
        mul = big * i;
        if(mul % small == 0)
            break;
        i++;
    }
    return mul;
}

int lcmUsingGcd(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a, b;

    while(1)
    {
        printf("\nEnter 2 numbers to find their LCM: \n");
        scanf("%d %d", &a, &b);
        printf("LCM: %d  |  LCM Using GCD: %d \n\n", lcm(a, b), lcmUsingGcd(a, b));
    }

    return 0;
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
