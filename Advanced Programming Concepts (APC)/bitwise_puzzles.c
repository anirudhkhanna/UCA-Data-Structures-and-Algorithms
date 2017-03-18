#include <stdio.h>

int compare(int a, int b) {     // Compare 2 nos without if-else statements, >, <, == and - operators.
    return sign(a + (~b + 1));
}

int sign(int x) {               // Give sign info about a no: 1 if x>0, -1 if x<0, 0 if x=0.
    return (x>>31) | (!!x);
}

int bitAnd(int a, int b) {      // Bitwise AND using ~ and | only.
    return ~(~a | ~b);
}

int bitXor(int a, int b) {      // Bitwise XOR using ~ and & only.
    return ~(~(~a&b) & ~(a&~b));
}

int not(int x) {                // Return !x without using ! operator.
    int neg_x = ~x + 1;
    return 1 ^ ((x>>31 & 1) | (neg_x>>31 & 1));
    
    /*
    ANOTHER WAY:
    int res;
    x && ~(res=0) || (res=1);
    return res;
    */
}

int conditional(int a, int b, int c) {  // Implement conditional operator ?: using logical operators.
    return ((~(!a<<31)>>31) & b) | (((!a<<31)>>31) & c);

    /*
    ANOTHER WAY:
    int res;
    (a && (res=b)) || (res=c);  // Will not work in case a=1 and b=0 (as "res = b" returns b).
    return res;
    */
}

int invertRange(int a, int p1, int p2) {    // Invert bits in a from position p1 to p2.
    int mo = 2147483647;    //(2 ^ (32-1)) - 1 = 01111111..
    mo >>= (32-(p2+1))-1;
    mo >>= p1;
    mo <<= p1;
    a = a ^ mo;     //a ^ 000..011110..000
    return a;
}

void printBinary(int x) {            // Print binary representation of a number.
    int i;
    for(i=31; i>=0; i--)
        printf("%d", (x>>i) & 1);
}

int main()
{
    int a, b, c;
    printf("\n\nEnter 2 numbers to compare (-1 if a<b, 1 if a>b, 0 if a=b): \n");
    scanf("%d %d", &a, &b);
    printf("\n\tComparison: %d\n", compare(a, b));
    printf("\n\tAlso,\n");
    printf("\n\ta & b : %d  |  %d\n", bitAnd(a, b), a&b);
    printf("\n\ta ^ b : %d  |  %d\n", bitXor(a, b), a^b);
    printf("\n\t!a    : %d  |  %d\n", not(a), !a);

    printf("\n\nNow enter 3 numbers for ternary operation (a?b:c): \n");
    scanf("%d %d %d", &a, &b, &c);
    printf("\n\ta?b:c   %d  |  %d\n", conditional(a, b, c), a?b:c);

    printf("\n\nNow enter 3 numbers for inverting bits in 1st no from bit pos. b to c: \n");
    scanf("%d %d %d", &a, &b, &c);
    printf("\n\tInverted bits from b to c in a: %d  |  ", invertRange(a, b, c));
    printBinary(invertRange(a, b, c));
    printf("\n");

    printf("\n\n");
    return 0;
}
