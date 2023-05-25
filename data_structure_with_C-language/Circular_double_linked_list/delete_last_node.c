#include <stdio.h>
#include <stdlib.h>


/*
        delete last node
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
struct Node* delAtBeg(struct Node* tail);
struct Node* delAtEnd(struct Node* tail);
void display(struct Node* tail);


int main()
{
        struct Node* tail;
        tail = addToEmpty(20);
        tail = addToBeg(tail, 10);
        tail = addToEnd(tail, 30);
        tail = addToEnd(tail, 40);
        //tail = delAtBeg(tail);
        //tail = delAtBeg(tail);
        tail = delAtEnd(tail);

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

struct Node* delAtBeg(struct Node* tail)
{
        if (tail == NULL)
            return (tail);

        struct Node* temp = tail->next, *current = NULL;

        if (temp == tail)
        {
            free(tail);
            tail = NULL;
            return (tail);
        }
        current = temp->next;

        current->prev = tail;
        tail->next = current;

        free(temp);

        return (tail);

}

struct Node* delAtEnd(struct Node* tail)
{
        if (tail == NULL)
            return (tail);

        struct Node* temp = tail->prev;

        if (temp == tail)
        {
            free(tail);
            tail = NULL;
            return (tail);
        }

        temp->next = tail->next;
        tail->next->prev = temp;

        free(tail);
        tail = temp;

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


