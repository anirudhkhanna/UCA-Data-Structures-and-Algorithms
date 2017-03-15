#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Defining methods to handle the linked list */

List * newList()
{
    List *newList = (List *) malloc(sizeof(List));

    if (newList == NULL)
        return NULL;

    newList -> head = NULL;
    return newList;
}

void addStart(List *L, void *data)
{
    Node *newnode = (Node *) malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = (*L).head;
    (*L).head = newnode;
}

void addEnd(List *L, void *data)
{
    Node *newnode = (Node *) malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = NULL;

    if ((*L).head == NULL)
        (*L).head = newnode;
    else
    {
        Node *ptr = (*L).head;
        while (ptr -> next != NULL)
            ptr = ptr-> next;

        ptr -> next = newnode;
    }
}

void * delStart(List *L)
{
    if ((*L).head == NULL)
        return NULL;

    Node *ptr = (*L).head;
    void *data = (*L).head -> data;
    (*L).head = (*L).head -> next;

    free(ptr);
    return data;
}

void * delEnd(List *L)
{
    if ((*L).head == NULL)
        return NULL;

    if ((*L).head -> next == NULL)
    {
        void *data = (*L).head -> data;
        free((*L).head);
        (*L).head = NULL;
        return data;
    }

    Node *cur = (*L).head;
    while (cur -> next -> next != NULL)
        cur = cur -> next;

    Node *ptr = cur -> next;
    void *data = ptr -> data;
    cur -> next = NULL;

    free(ptr);
    return data;
}

void reverse(List *L)
{
    Node *ptr = (*L).head, *ptr1 = NULL, *ptr2;

    while (ptr != NULL)
    {
        ptr2 = ptr1;
        ptr1 = ptr;
        ptr = ptr -> next;
        ptr1 -> next = ptr2;
    }

    (*L).head = ptr1;
}


Node * reverseRecursive(Node *head)
{
    Node *first = head, *second = head -> next;

    if (second == NULL)
        return first;
    else
    {
        Node *H = reverseRecursive(first -> next);
        second -> next = first;
        first -> next = NULL;

        return H;
    }
}

int isEmpty(List *L)
{
    return (*L).head == NULL;
}

int size(List *L)
{
    int nodeCount = 0;
    Node *ptr = (*L).head;

    while (ptr != NULL)
    {
        nodeCount++;
        ptr = ptr -> next;
    }

    return nodeCount;
}

void clear(List *L)
{
    Node *ptr;
    while ((*L).head != NULL)
    {
        ptr = (*L).head;
        (*L).head = (*L).head -> next;
        free(ptr);
    }
}

void print(List *L, void (*prnFunPtr)(void *))
{
    Node *ptr = (*L).head;
    while (ptr)
    {
        void *data = ptr -> data;
        (*prnFunPtr)(data);
        ptr = ptr -> next;
    }
}
