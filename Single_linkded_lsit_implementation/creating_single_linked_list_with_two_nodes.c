#include <stdio.h>
#include <stdlib.h>

/*create single linked list
 * first we want to create linked list consist of two nodes
 * the first node will contain data and link must have
        the address of the second node
        the second node will contain data
        and link to next node which isn't
        so we will make it's link point to null
*/
//single linked list we can make multi data
// but must be only one pointer

//we should include library "stdlib.h" why?
//to call "malloc" function


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
    //pointer point to struct Node
    //this pointer "head" can access data and link
    //that mean all members of struct

    //we named it head because it's will be the first node
    //and initialize it to null
    struct Node *head = NULL;

    //now we call malloc function to allocate memory for struct node
    //now the node is created
    //which means the memory has been allocated
    //for data as well as link pointer

    //malloc return void pointer which can be type casting
    //to struct node *
    //but actually we can void this step because
    //in c is not mandatory to type cast the void pointer
    //we can simply store this pointer without type casting
    //but it's a good practice

    //now head can access to data and link
    head = (struct Node *)malloc(sizeof(struct Node));

    //how to access struct members
    //we can use arrow operator we can go inside the node
    //now we initialize date with 50
    head->data = 50;

    //now we can also access to the link
    head->link = NULL;

    //now we want to create next node
    head = (struct Node *)malloc(sizeof(struct Node));

    //assign data into second node
    head->data = 90;

    //now make pointer point to null
    head->link = NULL;

    /*// there is an error???????????//*/

    /*we create second node using the head pointer which
    must have the address of first node!!
    now we can't access to the first node
    so we will create another pointer will point to second node
    */

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

    return 0;
}
