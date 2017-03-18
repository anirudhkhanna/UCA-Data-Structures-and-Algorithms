#include <stdio.h>

int main()
{
    int res[3000]; // Let the array have capacity to store 3000 digits
                   // Numbers will be stored in reverse order in the array
    int N, n, i, carry, size, mul;

    printf("\nEnter number to calculate factorial: ");
    scanf("%d", &N);

    res[0] = 1;     // Initialize the array with only 1 digit, i.e. 1
    carry = 0;      // Carry is initially 0
    size = 1;       // Initializes digit counter as 1 (no of digits in the array)

    for(n = 2; n <= N; n++)
    {
        for(i = 0; i < size; i++)      // Loop for multiplying numbers
        {
            mul = (res[i] * n) + carry;  // Product of number with each digit + carry from previous operation
            res[i] = mul % 10;           // Put first digit of product (prod with ith digit) at position i itself
            carry = mul / 10;            // Remaining carry value that will be stored in later indexes
        }

        while(carry > 0)            // Loop for storing the remaining carry value to the array
        {
            res[size++] = carry % 10;
            carry /= 10;
        }
    }

    printf("\n%d! = ", N);          // Printing the result
    for(i = size-1; i >= 0; i--)    // Array is stored in reverse so printing in reverse
        printf("%d", res[i]);

    printf("\n\n");
    return 0;
}
