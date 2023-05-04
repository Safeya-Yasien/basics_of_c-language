#include <stdio.h>
#include <stdlib.h>

struct Node
{
        int data;
        struct Node *next;
};

void add_at_end(struct Node *head, int data);
void display(struct Node *head);
void insertion_sort(struct Node **head, struct Node *new_node);


int main()
{
        struct Node *head = NULL, *ptr = NULL, *new_node = NULL;
        head = (struct Node *)malloc (sizeof(struct Node));
        head->data = 10;
        head->next = NULL;

        ptr = head;
        add_at_end(head, 15);
        add_at_end(head, 20);
        add_at_end(head, 25);
        add_at_end(head, 30);

        new_node = (struct Node *)malloc (sizeof(struct Node));
        new_node->data = 20;
        new_node->next = NULL;

        insertion_sort(&head, new_node);


        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
}

void add_at_end(struct Node *head, int data)
{
        struct Node *new_node = NULL, *ptr = NULL;
        new_node = (struct Node *)malloc (sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;

        ptr = head;

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new_node;

}

void insertion_sort(struct Node **head, struct Node *new_node)
{
        if (*head == NULL || (*head)->data >= new_node->data)
        {
            new_node->next = *head;
            *head = new_node;
            return;
        }

        struct Node *current = *head;

        while (current->next != NULL && current->next->data < new_node->data)
            current = current->next;

        new_node->next = current->next;
        current->next = new_node;
}

void display(struct Node *head)
{
        struct Node* ptr = NULL;
        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
}

