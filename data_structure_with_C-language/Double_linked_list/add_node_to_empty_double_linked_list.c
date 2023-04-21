#include <stdio.h>
#include <stdlib.h>

/*
    insert node in doubly linked list

*/

struct Node
{
        struct Node* prev;
        int data;
        struct Node* nex;
};

struct Node *addToEmpty(struct Node* head, int data);

int main()
{
        struct Node *head = NULL;
        head = addToEmpty(head, 45);

        printf("%d", head->data);

}

struct Node *addToEmpty(struct Node* head, int data)
{
        struct Node* temp = NULL;
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->data = data;
        temp->nex = NULL;

        head = temp;

        return (head);

}

