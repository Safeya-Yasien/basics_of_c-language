#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *link;
};

void add_at_end(struct Node *head, int data);
void del_at_end(struct Node *head);
void del_at_beginning(struct Node **head);

int main(void)
{
    struct Node *head = NULL, *ptr = NULL;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 5;
    head->link = NULL;

    ptr = head;

    add_at_end(head, 15);
    add_at_end(head, 30);
    add_at_end(head, 50);


    del_at_end(head);

    /*
        don't forget to pass by reference using address &
    */
    del_at_beginning(&head);

    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

}

void add_at_end(struct Node *head, int data)
{
    struct Node *new_node = NULL, *ptr;
    new_node = (struct Node *)malloc(sizeof(struct Node));

    ptr = head;

    new_node->data = data;
    new_node->link = NULL;

    while (ptr ->link != NULL)
        ptr = ptr->link;

    ptr->link = new_node;

}

void del_at_end(struct Node *head)
{
    if (head == NULL)
        return;
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp = NULL, *temp2 = NULL;

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
}


void del_at_beginning(struct Node **head)
{
    if (*head == NULL)
        return;
    else
    {
        struct Node *temp = NULL;
        temp = *head;

        /*
            The -> operator has higher precedence than the * operator,
            so the expression is being evaluated as *(head->link)
            instead of (*head)->link, which is what you intended.
        */
        *head = (*head)->link;

        free(temp);
        temp = NULL;
    }

}
