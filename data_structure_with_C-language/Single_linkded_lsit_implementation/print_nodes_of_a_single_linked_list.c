#include <stdio.h>
#include <stdlib.h>


//print the data of a single linked list


struct Node
{
    int data;
    struct Node *link;
};

void print_data(struct Node *head);


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
        print nodes of linked list
    */

    print_data(head);

    return (0);

}

void print_data(struct Node *head)
{
    /*
        it's better to use another pointer equal to head
        until we change the node which head must point to
    */
    if (head == NULL)
        printf("linked list is empty");

    struct Node *ptr = NULL;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

