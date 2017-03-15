/*    Compilation:
 *
 *    gcc -c list.c                  # creates list.o file
 *    ar -cvr liblist.a list.o       # archives list.o file into liblist.a
 *    gcc listclient.c -L. -llist    # links the library and compiles the client program
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void prnFun(void *data)
{
    printf("%d ", *(int *)data);
}

int main()
{
    List *L = newList();

    int a = 0;
    int b = 10;
    int c = 20;
    int d = 30;

    addEnd(L, &a);
    addEnd(L, &b);
    addEnd(L, &c);
    addEnd(L, &d);

    printf("\nList: ");
    print(L, &prnFun);

    reverse(L);

    printf("\nList in reverse: ");
    print(L, &prnFun);

    clear(L);
    printf("\n");

    int lim = 10;
    while(lim--)
    {
        int *elem = (int *)malloc(sizeof(int));
        *elem = rand() % 100;
        addStart(L, elem);
    }

    printf("\nNew list: ");
    print(L, &prnFun);

    L -> head = reverseRecursive(L -> head);

    printf("\nList in reverse: ");
    while(!isEmpty(L))
        printf("%d ", *(int *)delStart(L));

    printf("\n");
    return 0;
}
