#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
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

void push(struct Stack *s, char val)
{
    if (isStackFull(s) == 1)
    {
        printf("Stack is full\n");
    }

    s->top += 1;
    s->arr[s->top] = val;
}

char pop(struct Stack *s)
{
    if (isStackEmpty(s) == 1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    char x = s->arr[s->top];
    s->top -= 1;
    return x;
}

int parenthesisMatch(char *exp)
{
    struct Stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sizeof(char));

    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isStackEmpty(sp))
            {
                return 0;
            }
            else
            {
                pop(sp);
            }
        }
    }
    if (isStackEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "8*(9)(";
    if (parenthesisMatch(exp))
    {
        printf("yes its balnced");
    }
    else
    {
        printf("no its not balanced");
    }
}