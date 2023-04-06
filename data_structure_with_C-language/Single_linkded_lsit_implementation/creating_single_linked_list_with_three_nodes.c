#include <stdio.h>
#include <stdlib.h>

/*create single linked list with three nodes*/

/**
 * Node - struct of node
 * @data: value in linked list
 * @Node link: the pointer which have the address of
        next node
 * self referential structure: pointer to structure
        of the same type
*/

struct Node
{
    int data;
    struct Node *link;  //self referential structure
};

int main()
{
    struct Node *head = NULL;

    //now head can access to data and link
    head = (struct Node *)malloc(sizeof(struct Node));

    //now we initialize date with 50
    head->data = 50;

    //now we can also access to the link
    head->link = NULL;

    //create second node
    struct Node *current = NULL;

    //allocate memory to the second node
    current = (struct Node *)malloc(sizeof(struct Node));

    //now assign the data of the second node
    current->data = 45;

    //make it's pointer refer to null because there is no nodes after it
    current->link = NULL;

    //now we want to link the two nodes with each other so
    //update the link of the first node to refer to the address of the second node
    head->link = current;

    //now we want to create the third node
    //we have two ways
    //first way: create another pointer
    struct Node *current2 = NULL;

    //allocate memory to the third node
    current2 = (struct Node *)malloc(sizeof(struct Node));

    //assign value to the third node
    current2->data = 90;

    //make pointer of the third (last) node equal to null
    current2->link = NULL;

    //now we make the pointer of the second node
    //refer to the  address of the third node
    current->link = current2;

    /*// but if I want to create 20 nodes we will need to 20 pointers?!!
    and this is waste of memory so what we can do*/

    //second way: reuse current pointer
    /*first what is the mean of head->link->link???
    this mean the address of the second node
    this means we can access all of the list using head pointer?
    yes that's true*/

    //we can reuse the current pointer now so
    current = (struct Node *)malloc(sizeof(struct Node));

    //assign value and make pointer refer to null
    current->data = 90;
    current->link = NULL;

    //now we want link the last node to the second and first
    head->link->link = current;


    return 0;
}
