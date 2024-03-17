#include <stdio.h>

int size2(int *arr)
{
    int count = 0;
    while (*arr)
    {
        count++;
        *arr++;
    }
    return count;
}

int size(int *arr)
{
    return (sizeof(arr) / sizeof(int));
}

int main()
{
    int arr[100] = {1, 2, 3, 4, 5};
    printf("%d\n", size(arr));
    printf("%d\n", size2(arr));
    printf("%d\n", sizeof(arr) / sizeof(int));
}