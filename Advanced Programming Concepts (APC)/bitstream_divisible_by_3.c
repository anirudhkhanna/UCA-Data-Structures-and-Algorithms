// A stream of bits is coming from user. After addition of each bit, tell if the resulting binary number is divisible by three or not.
// 0    (0    -  divisible)
// 1    (01   -  not divisible)
// 1    (011  -  divisible)
// 0    (0110 -  divisible)
// ... and so on

#include <stdio.h>

int main()
{
    int Num, bit;  //Current number broken down to 0, 1 or 2 by using mod 3. And the current bit.
    Num = 0;       //Initialize Num with 0.
    printf("\nEnter bit by bit: \n");

    while(1)                    //For all incoming bits.
    {
        scanf("%d", &bit);
        
        if(bit == 0)            //(!bit && Num*=2) || (Num=Num*2+1)
            Num *= 2;
        else if(bit == 1)
            Num = (Num * 2) + 1;

        Num %= 3;               //Mod the resulting number with 3.

        if((Num % 3) == 0)
            printf("\tDivisible by 3.\n");
        else
            printf("\tNot divisible by 3.\n");
    }

    return 0;
}
