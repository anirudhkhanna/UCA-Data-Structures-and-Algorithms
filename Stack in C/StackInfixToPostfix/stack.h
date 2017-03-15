
typedef struct Stack Stack;
typedef struct Node Node;

struct Node {
    void *data;         // Generic pointer to any type of data
    Node *next;         // Pointer to next node
};

struct Stack {
    Node *top;          // Pointer to head node of the linked list being used as stack
};

Stack *    newStack    ();
void       push        (Stack *, void *);
void *     pop         (Stack *);
void *     peek        (Stack *);
int        isEmpty     (Stack *);
int        size        (Stack *);
void       clear       (Stack *);
void       show        (Stack *, void (*)(void *));
