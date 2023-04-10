#include <stdio.h>
#include <stdlib.h>


//insert element at the end of array


int add_at_end(int a[], int freePos, int data);

int main()
{
    //if the array is empty
    /*
        ► we take number of elements from user
            suppose he enter 3
            so n = 3
            and we initialize array of 10 elements
            so we have empty indexes in array we can add elements
        ► initialize variable freePos equal to n
            because will equal to last index empty in the array
            we have three elements starts from index 0 to 2
            so the index 3 is empty
        ► function add at end
            we pass to it array and the index of free position and value
            inside it we make array of index free position equal to data
            and after that we increment index to 4
            and return free position
        ► after that we print array from 0 to freepos
        ► time complexity of function add is O(1)
    */
    int a[10];
    int n, freePos;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    freePos = n;
    freePos = add_at_end(a, freePos, 65);

    for (int i = 0; i < freePos; i++)
        printf("%d ", a[i]);


    //array is full
    /*
        ► now size of array is 3
        ► and number of elements equal to size of array
            this mean no empty index
        ► so we initialize new array with more size
            depend on number of elemtns do you want to add
        ► send two array to function add at the end
            inside this function
            the loop copy all elements in old array to new array
            after coping it now we can add new element in this free position
        ► time complexity of this function is O(n)
    */

    int a2[3];
    int n2, freePos2;
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
        scanf("%d", &a2[i]);

    int size = sizeof(a) / sizeof(a[0]);

    freePos2 = n2;
    if (n == size)
    {
        int b[size + 2];
        freePos2 = add_at_end2(a2, b, size, freePos2, 115);
        for (int i = 0; i < freePos2; i++)
            printf("%d", b[i]);
    }

    return (0);

}

int add_at_end(int a[], int freePos, int data)
{
    a[freePos] = data;
    freePos++;

    return (freePos);
}


int add_at_end2(int a2[], int b[], int n2, int freePos2, int data2)
{
    for (int i = 0; i < n2; i++)
        b[i] = a2[i];

    b[freePos2] = data2;
    freePos2++;

    return (freePos);
}

