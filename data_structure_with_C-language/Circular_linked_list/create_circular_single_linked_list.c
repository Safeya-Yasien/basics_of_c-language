#include <stdio.h>
#include <stdlib.h>


/*
    create circular single linked list
*/

struct Node
{
        int data;
        struct Node *next;
};

struct Node *circularSingly(int data);


int main()
{
        int data = 34;
        struct Node *tail = NULL;

        tail = circularSingly(data);

        printf("%d\n", tail->data);
        return 0;
}

struct Node *circularSingly(int data)
{
        struct Node *temp = NULL;
        temp = (struct Node *)malloc(sizeof(struct Node));

        temp->data = data;
        temp->next = temp;

        return (temp);
}

