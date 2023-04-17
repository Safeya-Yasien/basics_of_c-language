#include <stdio.h>
#include <stdlib.h>

/*
    delete the whole single linked list
*/

struct Node
{
        int data;
        struct Node *link;
};

struct Node * add_end(struct Node *ptr, int data);
struct Node *del_list(struct Node *head);

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

        head = del_list(head);

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

struct Node *del_list(struct Node *head)
{
        struct Node *temp = NULL;
        temp = head;

        while (temp != NULL)
        {
            temp = temp->link;
            free(head);
            head = temp;
        }

        return (head);
}

