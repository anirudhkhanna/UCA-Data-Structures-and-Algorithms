/* Check if a set of brackets is balanced using stacks */

/*    Compilation:
 *
 *    gcc -c stack.c
 *    ar -cvr libstack.a stack.o
 *    gcc stackclient.c -L. -lstack
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

char closingBracket(char bracket)
{
    if(bracket == '(')
        return ')';
    if(bracket == '{')
        return '}';
    if(bracket == '[')
        return ']';

    return '\0';
}

int checkBalancedBrackets(char *str)
{
    int i;
    Stack *S = newStack();  // Allocate a new stack

    /* Loop to traverse the string */
    for(i = 0; str[i]; i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') // Push opening brackets directly
        {
            push(S, &str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']') // A closing bracket is found
        {
            if(isEmpty(S))
                return 0;

            char topElem = *(char *)peek(S);

            if(str[i] == closingBracket(topElem))
                pop(S);
            else
                return 0;
        }
    }

    if(isEmpty(S))
        return 1;
    else
        return 0;
}

int main()
{
    char str[100];

    printf("\n\tARE YOUR BRACKETS BALANCED?\n");
    printf("\n\tEnter a set of brackets (or \"exit\" to stop): \n\t");
    scanf("%s", str);

    while(strcmp(str, "exit") && strcmp(str, "EXIT"))
    {
        if(checkBalancedBrackets(str) == 1)
            printf("\n\tBrackets are balanced. That's good!\n");
        else
            printf("\n\tBrackets are not balanced. Need to work on that!\n");

        printf("\n\tEnter a set of brackets (or \"exit\" to stop): \n\t");
        scanf("%s", str);
    }

    return 0;
}
