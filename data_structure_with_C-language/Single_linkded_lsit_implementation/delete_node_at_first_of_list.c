#include <stdio.h>
#include <stdlib.h>

/*
    delete first node of the list
    time complexity is O(1)
*/

struct Node
{
    int data;
    struct Node *link;
};

void add_at_end(struct Node *head, int data);
struct Node* del_first(struct Node *head);

int main()
{
    struct Node *head = NULL, *ptr = NULL;
    head = (struct Node *)malloc (sizeof(struct Node));
    head->data = 90;
    head->link = NULL;

    ptr = head;
    add_at_end(head, 67);
    add_at_end(head, 14);
    add_at_end(head, 55);
    add_at_end(head, 30);

    head = del_first(head);

    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

void add_at_end(struct Node *head, int data)
{
    struct Node *new_node = NULL, *ptr = NULL;
    new_node = (struct Node *)malloc (sizeof(struct Node));
    new_node->data = data;
    new_node->link = NULL;

    ptr = head;

    while (ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = new_node;

}

struct Node* del_first(struct Node *head)
{
    if (head == NULL)
        printf("list is already empty!");

    else
    {
        struct Node *temp = NULL;
        temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return (head);

}
