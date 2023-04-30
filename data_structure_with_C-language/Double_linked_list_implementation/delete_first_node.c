#include <stdio.h>
#include <stdlib.h>


/*
    delete first node of double linked list
*/

struct Node
{
        int data;
        struct Node *pre;
        struct Node *next;
};

struct Node *addToEmpty(struct Node *head, int data);
struct Node *addToEnd(struct Node *head, int data);
struct Node *delFirst(struct Node* head);

int main()
{
        struct Node *head = NULL, *ptr = NULL;
        head = addToEmpty(head, 3);
        head = addToEnd(head, 5);
        head = addToEnd(head, 9);
        head = delFirst(head);

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

struct Node *addToEnd(struct Node *head, int data)
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

struct Node *delFirst(struct Node* head)
{
        if (head == NULL)
            return (head);

        struct Node *temp = NULL;
        temp = head;

        head = head->next;
        if (head != NULL)
            head->pre = NULL;

        free(temp);
        temp = NULL;

        return (head);

}

