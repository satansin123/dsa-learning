#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void initMyArray(struct myArray *arr, int tSize, int uSize)
{
    (*arr).total_size = tSize;
    (*arr).used_size = uSize;
    (*arr).ptr = (int *)malloc(tSize * sizeof(int));
}

void showArray(struct myArray *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d\n", (arr->ptr)[i]);
    }
}

int main()
{
    struct myArray marks;
    initMyArray(&marks, 10, 2);
    showArray(&marks);
}