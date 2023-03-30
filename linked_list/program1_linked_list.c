#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*create program to create node if till the user
    enter number 1
*/

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

void printList(Node *node);

int main()
{
    Node *head = NULL, *new_node, *temp;

    int choice = 1;

    while(choice)
    {
        new_node = (Node *)malloc(sizeof(Node));

        printf("Enter a number (or 0 to stop): ");
        scanf("%d", &choice);

        new_node ->data = choice;
        new_node ->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp ->next = new_node;
            temp = new_node;
        }
    }
    printf("Linked list: ");
    printList(head);
}

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node ->data);
        node = node ->next;
    }
    printf("\n");
}

