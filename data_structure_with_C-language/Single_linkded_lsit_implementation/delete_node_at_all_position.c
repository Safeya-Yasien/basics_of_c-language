#include <stdio.h>
#include <stdlib.h>


struct Node
{
        int data;
        struct Node *link;
};

void del_first(struct Node **head);
void del_end(struct Node *head);
void del_pos(struct Node **head, int pos);
struct Node * add_end(struct Node *ptr, int data);

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

        //del_first(&head);
        //del_end(head);
        del_pos(&head, 3);

        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }

}

struct Node * add_end(struct Node *ptr, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));

        new_node->data = data;
        new_node->link = NULL;

        ptr->link = new_node;

        return (new_node);
}

void del_first(struct Node **head)
{
        if (*head == NULL)
            return;
        else
        {
            struct Node *ptr = NULL;
            ptr = *head;
            *head = (*head)->link;
            free(ptr);
            ptr = NULL;
        }
}

void del_end(struct Node *head)
{
        if (head == NULL)
            return;
        else if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct Node *ptr = NULL, *temp = NULL;
            ptr = head;
            temp = head;

            while (ptr->link != NULL)
            {
                temp = ptr;
                ptr = ptr->link;
            }
            temp->link = NULL;
            free(ptr);
            ptr = NULL;
        }
}

void del_pos(struct Node **head, int pos)
{
        if (*head == NULL)
            return;
        else if (pos == 1)
        {
            struct Node *temp = NULL;
            temp = *head;
            *head = (*head)->link;
            free(temp);
            temp = NULL;
        }
        else
        {
            struct Node *current = NULL, *previous = NULL;
            current = *head;
            previous = *head;

            while (pos != 1)
            {
                previous = current;
                current = current->link;
                pos--;
            }

            previous->link = current->link;
            free(current);
            current = NULL;
        }
}

