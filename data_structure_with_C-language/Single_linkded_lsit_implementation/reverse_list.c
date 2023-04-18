#include <stdio.h>
#include <stdlib.h>

/*
    reverse the list
*/

struct Node
{
        int data;
        struct Node *link;
};

struct Node *add_end(struct Node *ptr, int data);
struct Node *reverse(struct Node *head);

int main()
{
        struct Node *head = NULL, *ptr = NULL;
        head = (struct Node *)malloc(sizeof(struct Node));

        head->data = 5;
        head->link = NULL;

        ptr = head;

        ptr = add_end(ptr, 9);
        ptr = add_end(ptr, 11);
        ptr = add_end(ptr, 13);
        ptr = add_end(ptr, 17);

        head = reverse(head);

        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }

}

struct Node *add_end(struct Node *ptr, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));

        new_node->data = data;
        new_node->link = NULL;

        ptr->link = new_node;

        return (new_node);
}

struct Node *reverse(struct Node *head)
{
        struct Node *prev = NULL;
        struct Node *next = NULL;

        while (head != NULL)
        {
            next = head->link;
            head->link = prev;
            prev = head;
            head = next;
        }
        head = prev;
        return (head);
}


