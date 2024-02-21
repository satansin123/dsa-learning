#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};
int isStackEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isStackFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct Stack *s, int val)
{
    if (isStackFull(s) == 1)
    {
        printf("Stack is full\n");
    }

    s->top += 1;
    s->arr[s->top] = val;
}

int pop(struct Stack *s)
{
    if (isStackEmpty(s) == 1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    int x = s->arr[s->top];
    s->top -= 1;
    return x;
}

int display(struct Stack *s)
{
    for (int i = 0; i < s->top; i++)
    {
        return s->arr[i];
    }
}

int peek(struct Stack *s, int i)
{
    if (s->top - i + 1 < 0)
    {
        printf("not valid position\n");
        return -1;
    }
    else
    {
        return s->arr[s->top - i + 1];
    }
}

int main()
{
    struct Stack *s;
    s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("%d\n", isStackEmpty(s));
    push(s, 6);
    display(s);
    printf("%d\n", isStackEmpty(s));
    pop(s);
    printf("%d\n", isStackEmpty(s));
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    printf("%d", peek(s, 2));
    printf("%d", display(s));
    return 0;
}