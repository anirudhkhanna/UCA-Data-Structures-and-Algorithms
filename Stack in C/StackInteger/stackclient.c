/*    Compilation:
 *
 *    gcc -c stack.c
 *    ar -cvr libstack.a stack.o
 *    gcc stackclient.c -L. -lstack
 */

#include <stdio.h>
#include "stack.h"

int main()
{
    push(1);
    push(5);
    push(9);

    printf("\nStack contents = ");
    show();

    printf("\nTop element = %d", pop());

    printf("\n");
    return 0;
}
