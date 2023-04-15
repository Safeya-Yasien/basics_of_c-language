#include <stdio.h>

/*
    delete last element in the array
    time complexity is O(1)
*/


int main()
{
    int arr[] = {23, 3, 45, 12, 67, 54, 6, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    size = size - 1;

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return (0);
}
