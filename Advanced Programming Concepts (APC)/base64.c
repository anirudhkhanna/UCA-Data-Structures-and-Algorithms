/* Base64 encryption using bit manipulation */

#include <stdio.h>
#include <string.h>

void base64encode(char *, char *);
void base64decode(char *, char *);

char table[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main()
{
    char S[10001], res[10001];
    int choice;

    do
    {
        printf("\n\n\tBASE 64 ENCODER/DECODER: \n");
        printf("\n\t1. Encode \n\t2. Decode \n\t0. Exit \n");
        printf("\n\tEnter choice: ");
        scanf("%d", &choice);
        getchar();

        if(choice == 1)
        {
            printf("\n\tEnter text: \n\t");
            gets(S);
            base64encode(S, res);
            printf("\n\tEncoded: \n\t");
            puts(res);
        }
        else if(choice == 2)
        {
            printf("\n\tEnter code: \n\t");
            gets(S);
            base64decode(S, res);
            printf("\n\tDecoded: \n\t");
            puts(res);
        }
    } while(choice);

    return 0;
}

void base64encode(char *S, char *res)
{
    int mod, i, j = 0;
    char ch, tempbits;

    for(i = 0; S[i] != '\0'; i++)
    {
        mod = i % 3;    // Scenarios can be 0, 1 or 2 in bytes.

        if(mod == 0)            // eg. 10101111
        {                       //     ------~~
            ch = (S[i] & 0xFC) >> 2;
            res[j++] = ch;

            tempbits = (S[i] & 0x03) << 4;
        }
        else if(mod == 1)       // eg. 10101111
        {                       //     ~~~~++++
            ch = (S[i] & 0xF0) >> 4;
            ch = ch | tempbits;
            res[j++] = ch;

            tempbits = (S[i] & 0x0F) << 2;
        }
        else                    // eg. 10101111
        {                       //     ++------
            ch = (S[i] & 0xC0) >> 6;
            ch = ch | tempbits;
            res[j++] = ch;

            ch = (S[i] & 0x3F); // eg. 10101111
            res[j++] = ch;      //       ------

            tempbits = 0;
        }

        // Checking if this is the last byte for appending '=' at the end if required.
        if(S[i+1] == '\0')
        {
            if(mod == 1)   // One '=' symbol (given by '^' here) if 2 zeros were padded at the end.
            {
                res[j++] = tempbits;
                res[j++] = '^';
            }
            else if(mod == 0)   // Two '=' symbols ('^^') if 4 zeros were padded at the end.
            {
                res[j++] = tempbits;
                res[j++] = '^';
                res[j++] = '^';
            }
        }
    }
    res[j] = 0;


    //Converting numbers to encoded characters from table (and '^' to '=' symbols if any):
    for(j = 0; res[j] != '\0'; j++)
        if(res[j] == '^')
            res[j] = '=';
        else
            res[j] = table[res[j]];
}


void base64decode(char *S, char *res)
{
    int mod, i, j;
    char ch, tempbits;

    //Converting encoded characters to 6-bit numbers from table (except '=' symbols if any, because they have to be removed):
    for(i = 0; S[i] != '\0'; i++)
        for(j=0; table[j]!='\0'; j++)
            if(S[i] == table[j]) {
                S[i] = j;
                break;
            }

    // Removing '=' signs at end:
    i = strlen(S)-1;
    while(S[i] == '=')
        S[i--] = '\0';

    j = 0;

    for(i = 0; S[i] != '\0'; i++)
    {
        mod = i % 4;    // Scenarios can be 0, 1, 2 or 3 in 6-bit nos.

        if(mod == 0)
        {
            tempbits = (S[i+1] & 0x30) >> 4;
            ch = S[i] << 2;
            res[j++] = ch | tempbits;
        }
        else if(mod == 1)
        {
            tempbits = (S[i+1] & 0x3C) >> 2;
            ch = S[i] << 4;
            res[j++] = ch | tempbits;
        }
        else if(mod == 2)
        {
            tempbits = (S[i+1] & 0x3F) >> 0;
            ch = S[i] << 6;
            res[j++] = ch | tempbits;
        }
        else
        {
            tempbits = 0;
        }
    }

    res[j] = 0;
}
