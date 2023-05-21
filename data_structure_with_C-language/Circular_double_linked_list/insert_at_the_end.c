#include <stdio.h>
#include <stdlib.h>


/*
        insert node at the end of circular doubly linked list
*/

struct Node
{
        int data;
        struct Node* prev;
        struct Node *next;
};

struct Node* addToEmpty(int data);
struct Node* addToBeg(struct Node* tail, int data);
void display(struct Node* tail);
struct Node* addToEnd(struct Node* tail, int data);



int main()
{
        struct Node* tail = NULL;
        tail = addToEmpty(20);
        tail = addToBeg(tail, 10);
        tail = addToEnd(tail, 30);

        display(tail);
}

struct Node* addToEmpty(int data)
{
        struct Node* new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->prev = new_node;
        new_node->data = data;
        new_node->next = new_node;

        return (new_node);
}

struct Node* addToBeg(struct Node* tail, int data)
{
        struct Node* new_node = NULL, *temp = NULL;
        new_node = addToEmpty(data);

        if (tail == NULL)
            return (new_node);

        temp = tail->next;

        new_node->prev = tail;
        new_node->next = temp;
        temp->prev = new_node;
        tail->next = new_node;

        return (tail);

}

struct Node* addToEnd(struct Node* tail, int data)
{
        struct Node* new_node = NULL, *temp = NULL;
        new_node = addToEmpty(data);

        if (tail == NULL)
            return (new_node);

        temp = tail->next;
        new_node->prev = tail;
        new_node->next = temp;
        tail->next = new_node;
        temp->prev = new_node;

        tail = new_node;

        return (tail);
}

void display(struct Node* tail)
{
        struct Node* temp = tail->next;

        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
}

