#include <stdio.h>
#include <stdlib.h>


/*
        insert node after particular position
*/

struct Node
{
        int data;
        struct Node* prev;
        struct Node *next;
};

struct Node* addToEmpty(int data);
struct Node* addToBeg(struct Node* tail, int data);
struct Node* addToEnd(struct Node* tail, int data);
struct Node* addAfterPos(struct Node* tail, int pos, int data);
void display(struct Node* tail);


int main()
{
        struct Node* tail;
        tail = addToEmpty(20);
        tail = addToBeg(tail, 10);
        tail = addToEnd(tail, 30);
        tail = addToEnd(tail, 40);
        tail = addAfterPos(tail, 3, 70);

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

        new_node->next = temp;
        new_node->prev = tail;
        tail->next = new_node;
        temp->prev = new_node;

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

struct Node* addAfterPos(struct Node* tail, int pos, int data)
{
        struct Node *new_node = NULL, *pre = tail->next, *current = NULL;
        new_node = addToEmpty(data);

        if (tail == NULL)
            return (new_node);

        while (pos > 1)
        {
            pre = pre->next;
            pos--;
        }
        current =  pre->next;

        pre->next = new_node;
        new_node->prev = pre;
        new_node->next = current;
        current->prev = new_node;

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


