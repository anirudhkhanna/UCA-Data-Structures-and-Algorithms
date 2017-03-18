#include <stdio.h>

int main()
{
    int t;
    int a[200], res[200];
    int n1, n2, x, temp, i, m;

    printf("\nEnter 2 numbers to multiply (inputs should be within the range of int): \n");
    scanf("%d", &n1);
    scanf("%d", &n2);

    m = 0; // Will contain the number of digits
    while(n2) // Store n2 in an array digit-by-digit
    {
        a[m++] = n2 % 10;
        n2 /= 10;
    }

    temp = 0; // Initializes carry variable to 0
    for(i = 0; i < m; i++) // Multiplying
    {
        x = a[i] * n1 + temp; // Contains the digit by digit product with n1 plus carry, if any
        res[i] = x % 10; // Contains the digit to store at current position
        temp = x / 10; // Contains the carry value that will be stored at later indexes
    }

    while(temp) // Loop that will store the remaining carry value on resultant array, if any
    {
        res[m++] = temp % 10;
        temp /= 10;
    }

    printf("Result = ");
    for(i = m - 1; i >= 0; i--) // Printing the result
        printf("%d", res[i]);
    
    printf("\n\n");
    return 0;
}
