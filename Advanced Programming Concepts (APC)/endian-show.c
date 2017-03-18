/* In-memory representation of a multibyte data - 0x01235F7C (4 bytes int)
   On little endian machines - “7C 5F 23 01”
   On big endian machines - “01 23 5F 7C”
*/

#include <stdio.h>

/* Function to show bytes as stored in the memory, from location start to (start + n) */
void show_mem_rep(char *start, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%.2X ", start[i]);    // basically, *(start + i)
}

/* Main function to call the above function for some data */
int main()
{
    int a = 0x01235F7C;    // int in hexadecimal format
    show_mem_rep((char *)&a, sizeof(a));

    printf("\n");
    getchar();
    return 0;
}