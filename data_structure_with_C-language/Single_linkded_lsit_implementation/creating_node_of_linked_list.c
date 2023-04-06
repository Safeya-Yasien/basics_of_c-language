#include <stdio.h>
#include <stdlib.h>

/*create node of single linked list*/
//single linked list we can make multi data
// but must be only one pointer

//we should include library "stdlib.h" why?
//to call "malloc" function


/**
 * Node - struct of node
 * @a: value in linked list
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

    //now we want to display the value in data Node
    printf("%d", head->data);

    return 0;
}
