#include <stdio.h>

int main()
{
    int N, K;
    printf("\nEnter string size (N) and the no of times it was shifted & XOR-ed (K): \n");
    scanf("%d %d", &N, &K);

    char S[(N + K - 1) + 1];  // For encrypted input string
    char Res[N + 1];          // For decrypted result string

    printf("\nEnter encrypted string: \n");
    scanf("%s", S);

    int i, j, r, ctr;
    int xor = 0;

    r = 0;
    for(i = 0; i < N; i++)
    {
        Res[r++] = (xor ^ (S[i]-'0')) + '0';
        
        if(i >= K-1)
            xor = xor ^ (Res[i]-'0') ^ (Res[i-(K-1)]-'0');
        else
            xor = xor ^ (Res[i]-'0');
    }
    
    Res[r] = '\0';

    printf("\nDecrypted string: %s\n\n", Res);
    return 0;
}

/*
Given a binary message S of size N bits and an integer K, an encryption algorithm takes N bits as message and encrypts them as follows:
Message is written down K times, each time shifted by 0, 1, 2, ..., K-1 bits.

If message is 1001010 and K = 4, then it looks so:

1001010
 1001010
  1001010
   1001010

Now XOR of the above representation is calculated, for example, XOR-ing the numbers in the above case is like:

1001010
 1001010
  1001010
   1001010
----------
1110100110

Given the encrypted data, can you decrypt it to the actual binary message?

Input: The first line contains two integers N and K.
       The second line contains a string S of length N+K-1 consisting of ones and zeros.

Output: The decrypted string of length N consisting of ones and zeros.

EXAMPLE I/P: 6 2
             1110001

EXAMPLE O/P: 101111

EXPLANATION: 1 0 1 1 1 1
               1 0 1 1 1 1
             -------------
             1 1 1 0 0 0 1
*/
