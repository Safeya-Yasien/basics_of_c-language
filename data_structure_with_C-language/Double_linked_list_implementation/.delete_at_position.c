#include <stdio.h>
#include <stdlib.h>

/*
    delete node at particular position
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
struct Node* delFirst(struct Node *head);
struct Node* delLast(struct Node *head);
struct Node* delPos(struct Node *head, int position);



int main()
{
        struct Node *head = NULL, *ptr = NULL;
        head = addToEmpty(head, 10);
        head = addToBeg(head, 9);
        head = addToEnd(head, 1);
        head = delPos(head, 2);


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

struct Node* delFirst(struct Node *head)
{
        struct Node *ptr = NULL;
        ptr = head;
        head->pre = NULL;
        head = head->next;

        free(ptr);
        ptr = NULL;

        return (head);
}

struct Node *delLast(struct Node* head)
{
        struct Node *temp = NULL, *temp2 = NULL;
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp2 = temp->pre;
        temp2->next = NULL;

        free(temp);
        temp = NULL;

        return (head);
}

struct Node* delPos(struct Node *head, int position)
{
        struct Node *temp = NULL, *ptr = NULL;
        ptr = head;
        if (position == 1)
        {
            head = delFirst(head);
            return (head);
        }

        while (position > 1)
        {
            ptr = ptr->next;
            position--;
        }

        if (ptr->next == NULL)
            head = delLast(head);
        else
        {
            temp = ptr->pre;
            temp->next = ptr->next;
            ptr->next->pre = temp;
            free(ptr);
            ptr = NULL;
        }

        return (head);
}



