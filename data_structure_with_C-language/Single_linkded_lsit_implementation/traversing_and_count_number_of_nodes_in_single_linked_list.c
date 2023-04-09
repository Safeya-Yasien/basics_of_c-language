#include <stdio.h>
#include <stdlib.h>


//traversing a single linked list
//count number of nodes in a single linked list

/*
    what is the meaning of traversing a single linked list?
        means visiting each node of a single linked list until the
        end node is reached
*/


struct Node
{
    int data;
    struct Node *link;
};

void count_of_nodes(struct Node *head);


int main()
{
    struct Node *head = NULL, *current = NULL;
    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->link = NULL;

    current = (struct Node *)malloc(sizeof(struct Node));

    current->data = 20;
    current->link = NULL;
    head->link = current;

    current = (struct Node *)malloc(sizeof(struct Node));

    current->data = 30;
    current->link = NULL;
    head->link->link = current;


    /*
        count the number of nodes in the list
        and pass to it the head pointer which refer to the first
        node in the list
    */

    count_of_nodes(head);

    return (0);

}

void count_of_nodes(struct Node *head)
{
    int count = 0;

    if (head == NULL)
        printf("linked list is empty");

    struct Node *ptr = NULL;
    ptr = head;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }

    printf("%d", count);

}

