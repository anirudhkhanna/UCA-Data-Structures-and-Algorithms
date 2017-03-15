/* Addition of two numbers using linked lists */

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
    printf("%d", *(int *)data);
}

void addLists(List *L1, List *L2, List *LRes)
{
    Node *p1 = (*L1).head;
    Node *p2 = (*L2).head;

    int sum, carry = 0, *dgt = NULL;

    while(p1 && p2)
    {
        sum = (*(int *)p1 -> data) + (*(int *)p2 -> data) + carry;

        dgt = (int *)malloc(sizeof(int));
        *dgt = sum % 10;
        addEnd(LRes, dgt);

        carry = sum / 10;
        p1 = p1 -> next;
        p2 = p2 -> next;
    }

    while(p1)
    {
        sum = (*(int *)p1 -> data) + carry;
        dgt = (int *)malloc(sizeof(int));
        *dgt = sum % 10;
        addEnd(LRes, dgt);

        carry = sum / 10;
        p1 = p1 -> next;
    }

    while(p2)
    {
        sum = (*(int *)p2 -> data) + carry;
        dgt = (int *)malloc(sizeof(int));
        *dgt = sum % 10;
        addEnd(LRes, dgt);

        carry = sum / 10;
        p2 = p2 -> next;
    }

    while(carry)
    {
        dgt = (int *)malloc(sizeof(int));
        *dgt = carry % 10;
        addEnd(LRes, dgt);

        carry = carry /10;
    }
}

int main()
{
    List *L1 = newList(), *L2 = newList(), *LRes = newList();
    char s1[100], s2[100];
    int i, *dgt;

    printf("\nEnter two numbers to be added: \n");
    scanf("%s", s1);
    scanf("%s", s2);

    for(i = 0; s1[i]; i++)    // filling linked list with number in reverse
    {
        dgt = (int *)malloc(sizeof(int));
        *dgt = (int)(s1[i] - '0');
        addStart(L1, dgt);
    }

    for(i = 0; s2[i]; i++)    // filling linked list with number in reverse
    {
        dgt = (int *)malloc(sizeof(int));
        *dgt = (int)(s2[i] - '0');
        addStart(L2, dgt);
    }

    addLists(L1, L2, LRes);

    printf("\n");

    reverse(L1);
    print(L1, &prnFun);

    printf(" + ");

    reverse(L2);
    print(L2, &prnFun);

    printf(" = ");

    reverse(LRes);
    print(LRes, &prnFun);

    printf("\n");
    return 0;
}
