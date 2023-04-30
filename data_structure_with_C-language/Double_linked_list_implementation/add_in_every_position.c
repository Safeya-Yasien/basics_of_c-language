#include <stdio.h>
#include <stdlib.h>

struct Node
{
        int data;
        struct Node *pre;
        struct Node *next;
};

struct Node *addToEmpty(struct Node *head, int data);
struct Node *addToBeg(struct Node *head, int data);
struct Node *addToEnd(struct Node *head, int data);
struct Node *addBeforePos(struct Node *head, int data, int position);
struct Node *addAfterPos(struct Node *head, int data, int position);

int main()
{
        struct Node *head = NULL, *ptr = NULL;
        head = addToEmpty(head, 2);
        head = addToBeg(head, 1);
        head = addToEnd(head, 3);
        head = addToEnd(head, 5);
        head = addToEnd(head, 7);

        head = addBeforePos(head, 4, 4);
        head = addAfterPos(head, 6, 5);

        ptr = head;

        while (ptr != NULL)
        {
          printf("%d ", ptr->data);
          ptr = ptr->next;
        }
}

struct Node *addToEmpty(struct Node *head, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->pre = NULL;
        new_node->next = NULL;

        head = new_node;

        return (head);
}

struct Node *addToBeg(struct Node *head, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->pre = NULL;
        new_node->next = NULL;

        new_node->next = head;
        head->pre = new_node;

        head = new_node;

        return (head);
}

struct Node *addToEnd(struct Node *head, int data)
{
        struct Node *new_node = NULL, *ptr = NULL;
        new_node = addToEmpty(new_node, data);

        ptr = head;

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new_node;
        new_node->pre = ptr;

        return (head);
}

struct Node *addBeforePos(struct Node *head, int data, int position)
{
        struct Node *new_node = NULL, *temp = NULL;
        new_node = addToEmpty(new_node, data);

        temp = head;

        position--;

        while (position != 1)
        {
            temp = temp->next;
            position--;
        }

        new_node->next = temp->next;
        temp->next = new_node;
        new_node->pre = temp;

        return (head);
}

struct Node *addAfterPos(struct Node *head, int data, int position)
{
        struct Node *new_node = NULL, *temp = NULL;
        new_node = addToEmpty(new_node, data);

        temp = head;

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
            new_node->next = temp->next;
            temp->next = new_node;
            new_node->pre = temp;

        }


        return (head);
}

