
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main()
{
    //initialize pointer to point to the first node
    Node *head = NULL;

    //allocate the size of node
    //we casting malloc because it return void pointer
    Node *new_node = (Node*)(malloc(sizeof(Node)));

    //get data from user
    //to access the member of data structure
    //pointer_name then use arrow then member you want to access
    scanf("%d", &new_node->data);

    //to ensure that the node store the value
    printf("%d\n", new_node->data);

    //make it's pointer point to null
    //until insert new node
    new_node -> next = NULL;

    //now after we created node it's name new_node
    //and have value and pointer
    //we want to put it in linked list
    //so we will make head pointer point to the first node
    //which we created
    head = new_node;

    //to ensure that head now have the address of the new_node
    printf("%d\n", head -> data);

    //but if the head is not null
    //which mean if we have actually linked list
    //so we have to check from it first
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        //if the head actually have address of node
        //then we will make the pointer of the head
        //point to new_node
        //if it's while loop
        head -> next = new_node;
    }

    //but this line in else will be wrong if we insert third node
    //because head pointer will point to the third node 
    //and the link to the second node will be destroyed
    //so the solution is to make temporary pointer
    Node *temp;
    
    if (head == NULL)
    {
        head = temp;
        temp = new_node;
    }
    else
    {
        temp -> next = new_node;
        temp = new_node;
    }
}
