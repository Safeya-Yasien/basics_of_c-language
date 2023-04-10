#include <stdio.h>
#include <stdlib.h>


/*
    inserting a node at the end of single linked list
    reduce time of previous way
*/

//the time complexity of this way is O(1)

struct Node
{
    int data;
    struct Node *link;
};

struct Node* add_at_end(struct Node *head, int data);
void print_list(struct Node *head);

int main()
{
    struct Node *head = NULL, *ptr;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 50;
    head->link = NULL;

    ptr = head;

    ptr = add_at_end(ptr, 100);
    ptr = add_at_end(ptr, 200);
    ptr = add_at_end(ptr, 67);

    ptr = head;
    print_list(ptr);

}

struct Node* add_at_end(struct Node *ptr, int data)
{
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return (temp);

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
