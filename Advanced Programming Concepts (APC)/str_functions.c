#include <stdio.h>
#include <string.h>

int _strlen(char *str) {
    int len=0;
    while(str[len++]!=0)
        ;
    return --len;
}


void _strcpy(char *dest, char *src) {
    while(*dest++ = *src++);            //OR: while((*src = *dest) != '\0') {*src++; *dest++;}
}


void _strcat(char *s1, char *s2) {
    while(*s1)    //Reach to the end of s1
        s1++;
    
    while(*s1++ = *s2++);   //Concatenate s2 till NULL character
}


void _strncpy(char *dest, char *src, int num) {
    int i;
    for(i = 0; i < num && src[i]; i++)
        dest[i] = src[i];
    
    while(i < num)
        dest[i++]=0;    //Padding additional NULL characers if length of src is less than num
}


void _strncat(char *s1, char *s2, int num) {
    while(*s1)    //Reach to the end of s1
        s1++;

    //Concatenate s2 till "num" characters or till s2 becomes NULL:
    while(num-- && (*s1++ = *s2++));      //OR: int i=0; while(i++<num && ((*s1 = *s2)!='\0')) {*s1++; *s2++;}

    *s1 = 0;    //Add a NULL character in the end
}


int _strncmp(char *s1, char *s2, int num) {
    while(num-->1 && *s1++ && *s2++)
        if(*s1 != *s2)
            return 0;
    
    return 1;
}


int _strend(char *s1, char *s2) {
    int i = _strlen(s1)-1;
    int j = _strlen(s2)-1;
    
    if(i < j)
        return 0;
    
    while(i>=0 && j>=0)
        if(s1[i--]!=s2[j--])
            return 0;

    return 1;
}


int main()
{
    char s1[100], s2[100], s3[200];
    int num;
    
    printf("\nEnter 2 strings s1 and s2: \n\n");
    fgets(s1, 100, stdin);
    s1[_strlen(s1)-1]=0;    //To remove an extra newline which fgets() takes.
    fgets(s2, 100, stdin);
    s2[_strlen(s2)-1]=0;    //To remove an extra newline which fgets() takes.
    
    //strcpy:
    _strcpy(s3, s1);
    printf("\n\tstrcpy(s3, s1): ");    puts(s3);
    
    //strcat:
    _strcat(s1, s2);
    printf("\n\tstrcat(s1, s2): ");    puts(s1);

    //strncpy:
    _strncpy(s3, s2, 5);
    printf("\n\tstrncpy(s3, s2, 5): ");    puts(s3);
    
    //strncat:
    _strncat(s3, s2, 5);
    printf("\n\tstrncat(s3, s2, 5): ");    puts(s3);

    
    printf("\nEnter 2 strings s1 and s2 and number num for COMPARING upto num characters: \n\n");
    fgets(s1, 100, stdin);
    s1[_strlen(s1)-1]=0;    //To remove an extra newline which fgets() takes.
    fgets(s2, 100, stdin);
    s2[_strlen(s2)-1]=0;    //To remove an extra newline which fgets() takes.
    scanf("%d", &num);
    
    //strncmp:
    if(_strncmp(s1, s2, num))
        printf("\n\tMATCHED!\n");
    else
        printf("\n\tNOT MATCHED!\n");

    printf("\nEnter 2 strings s1 and s2 to FIND if s2 occurs at end of s1: \n\n");
    fgets(s1, 100, stdin);
    s1[_strlen(s1)-1]=0;    //To remove an extra newline which fgets() takes.   THIS INTAKES THE ENTER KEY PRESS, SO WE NEED EXTRA INPUT AGAIN:
    fgets(s1, 100, stdin);
    s1[_strlen(s1)-1]=0;    //To remove an extra newline which fgets() takes.
    fgets(s2, 100, stdin);
    s2[_strlen(s2)-1]=0;    //To remove an extra newline which fgets() takes.
   
    //strend:
    if(_strend(s1, s2))
        printf("\n\tFOUND!");
    else
        printf("\n\tNOT FOUND!");

    printf("\n\n");

    return 0;   
}
