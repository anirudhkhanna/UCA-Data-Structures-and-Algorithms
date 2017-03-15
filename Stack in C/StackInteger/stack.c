#include <stdio.h>
#include <stdlib.h>

/* Defining node type for storing a stack element */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *head = NULL;   // Pointer to head node

/* Defining methods to handle the stack */

void push(int data)
{
    Node *newnode = (Node*) malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = head;
    head = newnode;
}

int pop()
{
    if (head == NULL)
        return -1;

    Node *ptr = head;
    int data = head -> data;
    head = head -> next;
    free(ptr);
    return data;
}

int size()
{
    int size = 0;
    Node *ptr = head;
    while (ptr)
    {
        size++;
        ptr = ptr -> next;
    }
    return size;
}

int isEmpty()
{
   return (head == NULL);
}

void show()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}
