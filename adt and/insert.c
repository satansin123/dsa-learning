#include <stdio.h>
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 0;
}

int display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }
}

int delete(int arr[], int size, int index)
{
    for (int i = 0; i < size; i++)
    {
        if (i >= index)
        {
            arr[i] = arr[i + 1];
        }
    }
}

int main()
{
    int arr[100] = {1, 2, 6, 78};
    int size = 4;
    int element = 5;
    int index = 2;
    indInsertion(arr, size, element, 100, index);
    size += 1;
    display(arr, size);
    delete (arr, size, index);
    size -= 1;
    display(arr, size);
}