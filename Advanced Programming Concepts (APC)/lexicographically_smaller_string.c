/* Given a string, show the next lexicographically smaller string. Eg: hcdk -> dkhc, abgf -> abfg, and etc. */

#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, j, x, y;
    char  S[100];
    printf("\nEnter the string: ");
    scanf("%s", S);
    N=strlen(S);

    //Compare consecutive characters starting from RHS till we have a left character greater than a right one:
    i=N-2;
    while(S[i]<=S[i+1])
        i--;

    j=i+1;  //This divides the string (say "hcdk") into two parts: h|cdk
            //                                                     i j

    //Find index of nearest smaller character to S[i] in the right subarray:
    int diff=S[i]-S[j];
    int min=diff;
    int ind=j;
    for(x=j; x<N; x++)
    {
        diff=S[i]-S[x];
        if(diff<min && diff>=0)
        {
            min=diff;
            ind=x;
        }
    }

    //Swap nearest smaller character in the right subarray with S[i]:
    char temp=S[i];
    S[i]=S[ind];
    S[ind]=temp;

    //Sort the right subarray in desc. order:
    for(x=j; x<N; x++)
        for(y=j; y<N; y++)
            if(S[y]<S[y+1])
            {
                temp=S[y];
                S[y]=S[y+1];
                S[y+1]=temp;
            }

    printf("\nNext lexicographically smaller string = %s\n\n", S);
    return 0;
}
