#include <stdio.h>
#include <stdlib.h>


/*
        create circular linked list
*/

struct Node
{
        int data;
        struct Node *next;
};

struct Node *createList(struct Node* tail);
struct Node* insertToEmpty(int data);
struct Node* insertAtEnd(struct Node* tail, int data);
void display(struct Node *tail);

int main()
{
        struct Node* tail = NULL;
        tail = createList(tail);

        display(tail);
}

struct Node *createList(struct Node* tail)
{
        int n, data;
        scanf("%d", &n);

        if (n == 0)
            return (tail);
        scanf("%d", &data);
        tail = insertToEmpty(data);

        for (int i = 1; i < n; i++)
        {
            scanf("%d", &data);
            tail = insertAtEnd(tail, data);
        }

        return (tail);
}

struct Node* insertToEmpty(int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = new_node;

        return (new_node);
}

struct Node* insertAtEnd(struct Node* tail, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = tail->next;
        tail->next = new_node;
        tail = tail->next;

        return (tail);
}

void display(struct Node *tail)
{
        if (tail == NULL)
            return (tail);

        struct Node *ptr = NULL;
        ptr = tail->next;

        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != tail->next);
}

