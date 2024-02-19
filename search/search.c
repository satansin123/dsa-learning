#include <stdio.h>
int searchIndex(int arr[], int n, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            return i;
        }
    }
    return -1;
}

int binarySearc(int arr[], int size, int element)
{
    int mid;
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 67, 234};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 4;
    // Search for the number 8 in the array

    if (searchIndex(arr, size, n) == -1)
        printf("The element is not present in the array.\n");
    else
        printf("The element is present at index %d.\n", searchIndex(arr, size, n));
    if (binarySearc(arr, size, n) == -1)
        printf("The element is not present in the array.\n");
    else
        printf("The element is present at index %d.\n", binarySearc(arr, size, n));

    return 0;
}