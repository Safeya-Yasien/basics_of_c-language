#include <stdio.h>
#include <stdlib.h>


/*
        count number of elements in list
        ► time complexity is O(n)
*/

struct Node
{
        int data;
        struct Node *next;
};

struct Node *creat_circular(int data);
struct Node *insertAtBeg(struct Node *tail, int data);
struct Node *insertAtEnd(struct Node *tail, int data);
void lengthOfList(struct Node* tail);
void display(struct Node *tail);


int main()
{
        struct Node *tail = NULL;
        tail = creat_circular(50);
        tail = insertAtBeg(tail, 10);
        tail = insertAtEnd(tail, 87);
        tail = insertAtEnd(tail, 49);
        lengthOfList(tail);

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

void lengthOfList(struct Node* tail)
{
        struct Node* temp = tail->next;
        int count = 0;

        while (temp != tail)
        {
            temp = temp->next;
            count++;
        }
        count++;
        printf("%d\n", count);
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


