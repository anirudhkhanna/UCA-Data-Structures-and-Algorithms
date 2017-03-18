/* To check if a system is little endian or big endian
*/

#include <stdio.h>

int main()
{
    unsigned int i = 1;
    char *p = (char *) &i;    // first byte address

    if(*p == 1)
        printf("Little endian system");
    else
        printf("Big endian system");

    printf("\n");
    getchar();
    return 0;
}