#include <stdio.h>
#include <stdlib.h>

/*
    delete last node of the list
*/

struct Node
{
    int data;
    struct Node *link;
};

void add_at_end(struct Node *head, int data);
struct Node* del_last(struct Node *head);

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

    head = del_last(head);

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

struct Node* del_last(struct Node *head)
{
    if (head == NULL)
        printf("list is empty");
    else if (head ->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        /*
            which point to last node
            to free it
        */
        struct Node *temp = NULL;

        /*
            which point to node before last node
            to make it's pointer point to null
        */
        struct Node *temp2 = NULL;

        temp = head;
        temp2 = head;

        while (temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }

    return (head);
}

