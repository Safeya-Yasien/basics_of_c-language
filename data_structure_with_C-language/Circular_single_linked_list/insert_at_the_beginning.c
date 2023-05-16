#include <stdio.h>
#include <stdlib.h>


/*
    insert node at the beginning of the list

    ► why we make tail pointer?
        when we want to insert new node at the beginning of the list
        we need pointer which point to the last node of the list
        to point to the new new node to be circular linked list
        so we have to update the link part of the last node to point
        to the new node
        this will help us not to traverse the linked list

    ► time complexity is O(1)
*/

struct Node
{
        int data;
        struct Node *next;
};

struct Node *creat_circular(int data);
struct Node *insertAtBeg(struct Node *tail, int data);

int main()
{
        struct Node *tail = NULL, *ptr = NULL;
        tail = creat_circular(15);
        tail = insertAtBeg(tail, 70);

        display(tail);


}

struct Node *creat_circular(int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = new_node;

        return (new_node);
}

struct Node *insertAtBeg(struct Node *tail, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = tail->next;

        tail->next = new_node;

        return (tail);
}

void display(struct Node *tail)
{
        struct Node *head = tail->next;

        do
        {
            printf("%d ", head->data);
            head = head->next;
        }while (head != tail->next);
}

