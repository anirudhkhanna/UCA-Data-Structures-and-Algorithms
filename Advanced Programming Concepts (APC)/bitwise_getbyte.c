#include <stdio.h>

int getByte(int num, unsigned byteno)
{
    return (num >> (byteno * 8)) & 0xFF;    // Mask and return the required byte
}

int main()
{
    int num;
    unsigned byteno;

    printf("\n\n\tEnter a hex number to get a desired byte from it: ");
    scanf("%x", &num);         //To take input num in hex, by using %x
    printf("\tEnter byte no to get (0 - 3): ");
    scanf("%u", &byteno);    //To take input byteno in unsigned decimal, by using %u

    printf("\n\tByte no %u in hex representation: %x\n", byteno, getByte(num, byteno));

    return 0;
}
