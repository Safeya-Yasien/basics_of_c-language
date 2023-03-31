#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//add node at the beginning of the linked list

/**
 * struct Node - structure named node
 * @value: the data in the node
 * @ struct Node next: pointer to next node
 */

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;

void beginsert(int);
void printList(Node *node);

int main()
{
    int choice, item;

    do
    {
        printf("enter the item: ");
        scanf("%d", &item);
        beginsert(item);

        printf("if you want to insert another value enter 0: ");
        scanf("%d", &choice);
    }while(choice == 0);

    printList(head);

}

void beginsert(int item)
{
    Node *new_node = (Node *)(malloc(sizeof(Node)));

    if (new_node == NULL)
    {
        printf("overflow\n");
    }
    else
    {
        new_node->data = item;
        new_node->next = head;
        head = new_node;
        printf("node inserted\n");
    }

}

void printList(Node *list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}
