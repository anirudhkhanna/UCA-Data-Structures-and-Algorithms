#include <stdio.h>
#include <string.h>

int is_anagram(char *s1, char *s2)
{
    int A1[256]={0}, A2[256]={0};
    
    int i, j;
    for(i=0; s1[i]!='\0'; i++)
        A1[s1[i]]++;

    for(i=0; s2[i]!='\0'; i++)
        A2[s2[i]]++;
    
    for(i=0; i<256; i++)
        if(A1[i]!=A2[i])
            return 0;
    
    return 1;
}

int main()
{
    int N;
    char s[2][100];
   
    printf("\nEnter 2 strings to check if they are anagrams: \n");
    scanf("%s", s[0]);
    scanf("%s", s[1]);

    if(is_anagram(s[0], s[1]))
        printf("\nAnagrams.\n\n");
    else
        printf("\nNot anagrams.\n\n");
    
    return 0;
}
