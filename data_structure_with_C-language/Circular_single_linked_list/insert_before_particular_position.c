#include <stdio.h>
#include <stdlib.h>


/*
        insert node before particular position
        ► time complexity is O(1)
*/

struct Node
{
        int data;
        struct Node *next;
};

struct Node *creat_circular(int data);
struct Node *insertAtBeg(struct Node *tail, int data);
struct Node *insertAtEnd(struct Node *tail, int data);
struct Node *insertAtPos(struct Node *tail, int data, int pos);
void display(struct Node *tail);


int main()
{
        struct Node *tail = NULL;
        tail = creat_circular(50);
        tail = insertAtBeg(tail, 10);
        tail = insertAtEnd(tail, 87);
        tail = insertAtEnd(tail, 90);
        tail = insertAtPos(tail, 40, 1);
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
        new_node->next = tail;
        tail->next = new_node;

        return (tail);
}

struct Node *insertAtEnd(struct Node *tail, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = tail->next;
        tail->next = new_node;

        tail = new_node;

        return (tail);

}

struct Node *insertAtPos(struct Node *tail, int data, int pos)
{
        struct Node *new_node = NULL, *ptr = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        ptr = tail->next;

        if (pos == 1)
        {
            new_node->data = data;
            new_node->next = ptr;
            tail->next = new_node;
            return (tail);
        }

        pos--;
        while (pos > 1)
        {
            ptr = ptr->next;
            pos--;
        }

        new_node->data = data;
        new_node->next = ptr->next;
        ptr->next = new_node;

        return (tail);

}

void display(struct Node *tail)
{
        struct Node *p = NULL;
        p = tail->next;

        do
        {
            printf("%d ", p->data);
            p = p->next;
        } while (p != tail->next);
}

