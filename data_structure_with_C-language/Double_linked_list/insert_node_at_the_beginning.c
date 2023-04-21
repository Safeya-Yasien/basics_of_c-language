#include <stdio.h>
#include <stdlib.h>

/*

    insert node at the beginning of a doubly linked list

*/

struct Node
{
        struct Node* prev;
        int data;
        struct Node* next;
};

struct Node *addToEmpty(struct Node* head, int data);
struct Node *addAtBeg(struct Node *head, int data);

int main()
{
        struct Node *head = NULL, *ptr = NULL;
        head = addToEmpty(head, 45);

        head = addAtBeg(head, 34);

        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }

}

struct Node *addToEmpty(struct Node* head, int data)
{
        struct Node* temp = NULL;
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->data = data;
        temp->next = NULL;

        head = temp;

        return (head);

}

struct Node *addAtBeg(struct Node *head, int data)
{
        struct Node* temp = NULL;
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->data = data;
        temp->next = NULL;

        temp->next = head;
        head->prev = temp;
        head = temp;

        return (head);
}
