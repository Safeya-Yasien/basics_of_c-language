#include <stdio.h>
#include <stdlib.h>

/*
    add node at the end of the double linked list
*/

struct Node
{
        int data;
        struct Node *pre;
        struct Node *next;
};

struct Node* addToEmpty(struct Node* head, int data);
struct Node* addToBeg(struct Node* head, int data);
struct Node *addAtEnd(struct Node* head, int data);

int main()
{
        struct Node* head = NULL, *ptr = NULL;
        head = addToEmpty(head, 15);

        head = addToBeg(head, 7);

        head = addAtEnd(head, 47);

        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
}

struct Node* addToEmpty(struct Node* head, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));

        new_node->data = data;
        new_node->pre = NULL;
        new_node->next = NULL;

        head = new_node;

        return (head);
}

struct Node* addToBeg(struct Node* head, int data)
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

struct Node *addAtEnd(struct Node* head, int data)
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

