#include <stdio.h>
#include <stdlib.h>

/*
    insert element at particular index in the array
    time complexity is O(n)
    
    ► we can't return an array from a function because
        an array created in the function is local to that function
    ► this is the reason why arr2[] has been passed as a parameter
        to a function
    ► passing arr2(name of the array) is equivalent to passing
        the address of the first block of arr2
        so the changes mode in called function will be
        reflected in the caller function
*/


int main()
{
    int arr[] = {2, 34, 21, 6, 7, 8, 90, 67, 23, 39};

    int pos = 5, data = 78, i;

    int size = sizeof(arr)/sizeof(arr[0]);

    int arr2[size + 1];

    add_at_pos(arr, arr2, size, data, pos);

    for (i = 0;i < size; i++)
        printf("%d ", arr2[i]);

}

void add_at_pos(int arr[], int arr2[], int n, int data, int pos)
{
    int i;
    int index = pos - 1;
    for (i = 0;i <= index-1; i++)
        arr2[i] = arr[i];

    arr2[index] = data;
    int j;
    for (i = index + 1, j = index; i < n + 1, j < n; i++, j++)
        arr2[i] = arr[j];
}

