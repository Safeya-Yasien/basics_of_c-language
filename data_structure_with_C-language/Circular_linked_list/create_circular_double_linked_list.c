#include <stdio.h>
#include <stdlib.h>


/*
    create circular double linked list
*/

struct Node
{
        int data;
        struct Node *prev;
        struct Node *next;
};

struct Node *circularDoubly(int data);


int main()
{
        int data = 45;
        struct Node *tail = NULL;

        tail = circularDoubly(data);

        printf("%d\n", tail->data);
        return 0;
}

struct Node *circularDoubly(int data)
{
        struct Node *temp = NULL;
        temp = (struct Node *)malloc(sizeof(struct Node));

        temp->data = data;
        temp->prev = temp;
        temp->next = temp;

        return (temp);
}

