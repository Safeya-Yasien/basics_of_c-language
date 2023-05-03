#include <stdio.h>
#include <stdlib.h>

/*
    reverse double linked list
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
struct Node* revers(struct Node *head);


int main()
{
        struct Node *head = NULL, *ptr = NULL;
        head = addToEmpty(head, 10);
        head = addToBeg(head, 9);
        head = addToEnd(head, 1);
        head = revers(head);

        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }

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


struct Node* revers(struct Node *head)
{
        struct Node *ptr = NULL, *temp = NULL;
        ptr = head;
        temp = ptr->next;

        ptr->next = NULL;
        ptr->pre = temp;

        while (temp != NULL)
        {
            temp->pre = temp->next;
            temp->next = ptr;
            ptr = temp;
            temp = temp->pre;
        }

        head = ptr;
        return (head);

}



