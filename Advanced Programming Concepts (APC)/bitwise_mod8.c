#include <stdio.h>

int mod_8(int n) {              // n mod 8

    int mul = (n >> 3) << 3;    // mul = (n / 8) * 8;
    return (n + (~mul + 1));    // return (n - mul)
    
    /* OR: return (~(-1 << 3)) & (N); */
}

int main()
{
    int n, mod8;

    while(1) {
        printf("\n\n\tEnter a number to mod with 8: ");
        scanf("%d", &n);
        mod8 = mod_8(n);
        printf("\n\t%d %% 8 = %d \t|\t verify: %d\n", n, mod8, n % 8);
    }
    
    return 0;
}
