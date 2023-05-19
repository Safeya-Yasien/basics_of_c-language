#include <stdio.h>
#include <stdlib.h>


/*
        delete the node at particular position
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
struct Node *delAtBeg(struct Node *tail);
struct Node *delAtEnd(struct Node* tail);
struct Node *delAtPos(struct Node* tail, int position);
void display(struct Node *tail);


int main()
{
        struct Node *tail = NULL;
        tail = creat_circular(50);
        tail = insertAtBeg(tail, 10);
        tail = insertAtEnd(tail, 87);
        tail = insertAtEnd(tail, 49);
        //tail = delAtBeg(tail);
        //tail = delAtEnd(tail);
        tail = delAtPos(tail, 3);
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

struct Node *delAtBeg(struct Node *tail)
{
        if (tail == NULL)
            return (NULL);
        if (tail->next == tail)
        {
            free(tail);
            tail = NULL;
            return (tail);
        }
        struct Node* ptr = tail->next;
        tail->next = ptr->next;
        free(ptr);
        ptr = NULL;

        return (tail);
}

struct Node *delAtEnd(struct Node* tail)
{
        if (tail == NULL)
            return (tail);

        struct Node* temp = NULL;
        temp = tail->next;

        if (tail->next == tail)
        {
            free(tail);
            tail = NULL;
            return(tail);
        }

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = tail->next;
        free(tail);
        tail = NULL;
        tail = temp;

        return (tail);
}

struct Node *delAtPos(struct Node* tail, int position)
{
        struct Node* ptr = tail->next, *temp = NULL;

        if (tail == NULL)
            return (tail);
        if (position == 1)
        {
            tail = delAtBeg(tail);
            return (tail);
        }
        position--;

        while (position > 1)
        {
            ptr = ptr->next;
            position--;
        }
        temp = ptr->next;

        ptr->next = temp->next;
        free(temp);
        temp = NULL;

        return (tail);

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


