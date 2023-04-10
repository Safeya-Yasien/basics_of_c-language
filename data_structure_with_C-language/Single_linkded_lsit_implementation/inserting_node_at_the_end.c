#include <stdio.h>
#include <stdlib.h>


//inserting a node at the end of single linked list
//the time complexity of this way is O(n) because we traverse whole list


struct Node
{
    int data;
    struct Node *link;
};

void add_at_end(struct Node *head, int data);
void print_list(struct Node *head);

int main()
{
    struct Node *head = NULL, *current = NULL;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 50;
    head->link = NULL;

    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = 100;
    current->link = NULL;
    head->link = current;

    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = 200;
    current->link = NULL;
    head->link->link = current;

    add_at_end(head, 67);
    print_list(head);

}

void add_at_end(struct Node *head, int data)
{
    struct Node *ptr, *temp;
    ptr = head;

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;

}


void print_list(struct Node *head)
{
    struct Node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
