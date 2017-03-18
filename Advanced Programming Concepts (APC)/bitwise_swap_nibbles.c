#include <stdio.h>

int swapNibbles(unsigned char a) {             // Swap nibbles in 8 bit char.
    return (a<<4 | a>>4);
}

void printBinary(unsigned char a) {            // Print binary representation of 8 bit char.
    int i;
    for(i=7; i>=0; i--)
        printf("%d", (a>>i)&1);
}

int main()
{
    unsigned char ch;    // To swap the nibbles in 8 bit data.
    unsigned char res;

    while(1) {
        printf("\n\n\tEnter 8 bit no. to swap nibbles: ");
        scanf("%u", &ch);

        res = swapNibbles(ch);
        printf("\n\tNum = %u \n\tRes = %u\n\n\t", ch, res);
        printBinary(ch);
        printf("\t->\t");
        printBinary(res);
    }
    
    return 0;
}
