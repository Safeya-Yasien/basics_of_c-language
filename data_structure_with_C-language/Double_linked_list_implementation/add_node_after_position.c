#include <stdio.h>
#include <stdlib.h>

/*
    add node after position
*/

struct Node
{
        int data;
        struct Node *pre;
        struct Node *next;
};

struct Node *addToEmpty(struct Node* head, int data);
struct Node* addToBeg(struct Node *head, int data);
struct Node* addToEnd(struct Node *head, int data);
struct Node *addAfterPos(struct Node* head, int data, int position);



int main()
{
        struct Node *head = NULL, *ptr = NULL;
        head = addToEmpty(head, 10);
        head = addToBeg(head, 9);
        head = addToEnd(head, 1);

        head = addAfterPos(head, 52, 2);

        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }

}

struct Node *addToEmpty(struct Node* head, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));

        new_node->data = data;
        new_node->pre = NULL;
        new_node->next = NULL;

        head = new_node;

        return (head);
}

struct Node *addAfterPos(struct Node* head, int data, int position)
{
        struct Node* new_node = NULL, *temp = NULL, *temp2 = NULL;
        temp = head;
        new_node = addToEmpty(new_node, data);

        while (position != 1)
        {
            temp = temp->next;
            position--;
        }

        if (temp->next == NULL)
        {
            temp->next = new_node;
            new_node->pre = temp;
        }
        else
        {
            temp2 = temp->next;
            temp->next = new_node;
            temp2->pre = new_node;

            new_node->next = temp2;
            new_node->pre = temp;
        }


        return (head);
}

struct Node* addToEnd(struct Node *head, int data)
{
        struct Node *new_node = NULL, *ptr = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));

        new_node->data = data;
        new_node->pre = NULL;
        new_node->next = NULL;

        ptr = head;

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new_node;
        new_node->pre = ptr;

        return (head);
}

struct Node* addToBeg(struct Node *head, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));

        new_node->data = data;
        new_node->pre = NULL;
        new_node->next = NULL;

        head->pre = new_node;
        new_node->next = head;

        head = new_node;

        return (head);
}

