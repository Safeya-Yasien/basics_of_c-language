#include <stdio.h>
#include <stdlib.h>


/*
        searching an element in list
        ► time complexity is O(n)
*/

struct Node
{
        int data;
        struct Node *next;
};

struct Node *creat_circular(int data);
struct Node *insertAtBeg(struct Node *tail, int data);
struct Node *insertAtEnd(struct Node *tail, int data);
void lengthOfList(struct Node* tail);
int searchElement(struct Node* tail, int key);
void display(struct Node *tail);


int main()
{
        struct Node *tail = NULL;
        tail = creat_circular(50);
        tail = insertAtBeg(tail, 10);
        tail = insertAtEnd(tail, 87);
        tail = insertAtEnd(tail, 49);
        //lengthOfList(tail);
        int re = searchElement(tail, 10);
        if (re == 0)
            printf("found\n");
        else
            printf("not\n");

        display(tail);
}

struct Node *creat_circular(int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = new_node;

        return (new_node);
}

struct Node *insertAtBeg(struct Node *tail, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = tail;
        tail->next = new_node;

        return (tail);
}

struct Node *insertAtEnd(struct Node *tail, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = tail->next;
        tail->next = new_node;

        tail = new_node;

        return (tail);

}

void lengthOfList(struct Node* tail)
{
        struct Node* temp = tail->next;
        int count = 0;

        while (temp != tail)
        {
            temp = temp->next;
            count++;
        }
        count++;
        printf("%d\n", count);
}

int searchElement(struct Node* tail, int key)
{
        struct Node* temp = tail->next;
        int index = 0;
        
        if (tail == NULL)
            return (-2);

        do
        {
            if (key == temp->data)
                return (index);
            temp = temp->next;
        } while ( (temp != tail->next));
        
        return (-1);
}

void display(struct Node *tail)
{
        struct Node *p = NULL;
        p = tail->next;

        do
        {
            printf("%d ", p->data);
            p = p->next;
        } while (p != tail->next);
}


