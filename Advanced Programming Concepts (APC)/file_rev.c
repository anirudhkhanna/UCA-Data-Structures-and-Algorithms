#include <stdio.h>

int main()
{
    FILE *fin, *fout;
    char ch;
    int size=0;
    
    fin = fopen("read.txt", "r");
    fout = fopen("write.txt", "w");

    printf("\n");
    fseek(fin, -1, SEEK_END);
    
    size = ftell(fin);
    while(size-- >= 0)
    {
        ch = fgetc(fin);
        printf("%c", ch);
        fputc(ch, fout);
        fseek(fin, -2, SEEK_CUR);
    }
    
    printf("\n\n(File is reversed.)\n\n");
    return 0;
}
