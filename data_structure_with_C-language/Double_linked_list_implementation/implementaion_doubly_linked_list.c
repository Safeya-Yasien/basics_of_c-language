#include <stdio.h>
#include <stdlib.h>

/*
    doubly linked list
    each node has an extra pointer that points to the previous
    node
*/

struct Node
{
        struct Node* prev;
        int data;
        struct Node* nex;
};

int main()
{
        struct Node *head = NULL;
        head = (struct Node *)malloc(sizeof(struct Node));
        head->prev = NULL;
        head->data = 10;
        head->nex = NULL;

}

