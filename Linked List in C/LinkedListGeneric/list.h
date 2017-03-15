
typedef struct List List;
typedef struct Node Node;

struct Node {
    void *data;         // Generic pointer to any type of data
    Node *next;         // Pointer to next node
};

struct List {
    Node *head;          // Pointer to head node of the linked list
};

List *     newList     ();
void       addStart    (List *, void *);
void       addEnd      (List *, void *);
void *     delStart    (List *);
void *     delEnd      (List *);
void       reverse     (List *);
Node *     reverseRecursive    (Node *);
int        isEmpty     (List *);
int        size        (List *);
void       clear       (List *);
void       print       (List *, void (*)(void *));
