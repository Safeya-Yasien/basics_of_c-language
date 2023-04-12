#include <stdio.h>
#include <stdlib.h>

/*
    insert node at particular position
*/

struct Node
{
    int data;
    struct Node *link;
};

void add_node_at_end(struct Node* head, int data);
void add_at_pos(struct Node *head, int data, int pos);
int main()
{
    struct Node *head = NULL, *ptr = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 60;
    head->link = NULL;

    add_node_at_end(head, 40);
    add_node_at_end(head, 90);
    add_node_at_end(head, 13);
    add_node_at_end(head, 7);
    add_node_at_end(head, 6);

    int data = 77, position = 4;

    add_at_pos(head, data, position);

    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

}

void add_node_at_end(struct Node* head, int data)
{
    struct Node* new_node = NULL, *ptr = NULL;
    ptr = head;
    new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = new_node;

}

void add_at_pos(struct Node *head, int data, int position)
{
    struct Node* new_node = NULL, *ptr = NULL;
    ptr = head;
    new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->link = NULL;

    position--;

    while (position != 1)
    {
        ptr = ptr->link;
        position--;
    }

    new_node->link = ptr->link;
    ptr->link = new_node;
}

