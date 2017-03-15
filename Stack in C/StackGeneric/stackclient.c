/*    Compilation:
 *
 *    gcc -c stack.c
 *    ar -cvr libstack.a stack.o
 *    gcc stackclient.c -L. -lstack
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void prnFun(void *data)
{
    printf("%f ", *(float *)data);
}

int main()
{
    Stack *S = newStack();  // Allocate a new stack
    float *data;

    data = (float *)malloc(sizeof(float));
    *data = 4.5;
    push(S, (void *)data);

    data = (float *)malloc(sizeof(float));
    *data = 9.99;
    push(S, (void *)data);

    data = (float *)malloc(sizeof(float));
    *data = -81.7;
    push(S, (void *)data);

    printf("\nStack = ");
    show(S, prnFun);
    printf("\nPeek = %f", *(float *)peek(S));

    printf("\n");
    return 0;
}
