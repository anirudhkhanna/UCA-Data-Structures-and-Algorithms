/* Infix to postfix expression conversion using stacks */

/*    Compilation:
 *
 *    gcc -c stack.c
 *    ar -cvr libstack.a stack.o
 *    gcc stackclient.c -L. -lstack
 */

#include <stdio.h>
#include "stack.h"

/* Return 1 if the priority of 1st operator is less than or equal to that of 2nd, otherwise return 0 */
int hasLessPriority(char op1, char op2)
{
    char priority[256] = {0};
    priority['('] = 4;
    priority['^'] = 3;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['+'] = 1;
    priority['-'] = 1;

    if(priority[(int)op1] <= priority[(int)op2])
        return 1;
    else
        return 0;
}

/* Check if the given character is an operator */
int isOperator(char ch)
{
    if(ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch =='/' || ch=='^')
        return 1;
    else
        return 0;
}

/* Check if the given character is an operand */
int isOperand(char ch)
{
    if(!isOperator(ch))
        return 1;
    else
        return 0;
}

/* Main function */
int main()
{
    char str[100];
    int i;

    Stack *operands = newStack();  // Allocate an operands stack
    Stack *operators = newStack();  // Allocate an operators stack

    printf("\nEnter infix expression: ");
    scanf("%s", str);

    for(i = 0; str[i]; i++)
    {
        if(isOperand(str[i]))
        {
            push(operands, &str[i]);
        }
        else if(isOperator(str[i]))
        {
            while(!isEmpty(operators) && *(char *)peek(operators) != '(' && hasLessPriority(str[i], *(char *)peek(operators)))
                push(operands, pop(operators));

            if(str[i] == ')')
            {
                while(!isEmpty(operators) && *(char *)peek(operators) != '(')
                    push(operands, pop(operators));

                if(!isEmpty(operators))
                    pop(operators); // Pop the opening bracket '(', do not store anywhere
            }

            if(str[i] != ')')
                push(operators, &str[i]);
        }
    }

    while(!isEmpty(operators)) // Move the remaining operators
        push(operands, pop(operators));

    char res[100];
    int j = 0;
    while(!isEmpty(operands))
           res[j++] = *(char *)pop(operands);
    res[j] = '\0';

    printf("\nEquivalent postfix expression: ");
    for(i = (j - 1); i >= 0; i--)
        printf("%c", res[i]);

    printf("\n\n");
    return 0;
}
