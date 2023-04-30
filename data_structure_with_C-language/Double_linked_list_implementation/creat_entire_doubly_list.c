#include <stdio.h>
#include <stdlib.h>

struct Node
{
        int data;
        struct Node *pre;
        struct Node *next;
};

struct Node *creatList(struct Node *head);
struct Node *addToEmpty(struct Node *head, int data);
struct Node *addToEnd(struct Node *head, int data);

int main()
{
        struct Node *head = NULL, *ptr = NULL;
        head = creatList(head);

        ptr = head;

        while (ptr != NULL)
        {
          printf("%d ", ptr->data);
          ptr = ptr->next;
        }
}

struct Node *creatList(struct Node *head)
{
    	int n, data;
    	scanf("%d", &n);

    	if (n == 0)
        	return (head);

    	scanf("%d", &data);

    	head = addToEmpty(head, data);

    	for (int i = 1; i < n; i++)
    	{
        	scanf("%d", &data);
        	head = addToEnd(head, data);
    	}

    	return (head);
}


struct Node *addToEmpty(struct Node *head, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->pre = NULL;
        new_node->next = NULL;

        head = new_node;

        return (head);
}

struct Node *addToEnd(struct Node *head, int data)
{
        struct Node *new_node = NULL, *ptr = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->pre = NULL;
        new_node->next = NULL;
        ptr = head;

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new_node;
        new_node->pre = ptr;

        return (head);
}

