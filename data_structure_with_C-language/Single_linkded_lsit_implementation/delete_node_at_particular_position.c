#include <stdio.h>
#include <stdlib.h>

/*
    delete a node at particular position
*/

struct Node
{
    int data;
    struct Node *link;
};

struct Node* add_at_end(struct Node *head, int data);
void del_pos(struct Node **head, int position);


int main()
{
        struct Node *head = NULL, *ptr = NULL;
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = 15;
        head->link = NULL;

        ptr = head;

        ptr = add_at_end(ptr, 50);
        ptr = add_at_end(ptr, 90);

        int position = 2;

        del_pos(&head, position);

        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
}

struct Node* add_at_end(struct Node *ptr, int data)
{
        struct Node *new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->link = NULL;

        ptr->link = new_node;

        return (new_node);

}

void del_pos(struct Node **head, int position)
{
        struct Node *current = NULL, *previous = NULL;

        current = *head;
        previous = *head;

        if (*head == NULL)
            printf("list is already empty");
        else if (position == 1)
        {
            *head = current->link;
            free(current);
            current = NULL;
        }
        else
        {
            while (position != 1)
            {
                previous = current;
                current = current->link;
                position--;
            }
            previous->link = current->link;
            free(current);
            current = NULL;
        }
}

