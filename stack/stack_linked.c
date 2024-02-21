#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isStackEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
int isStackFull(struct Node *top)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *top, int x)
{
    if (isStackFull(top))
    {
        printf("Stack is Full\n");
        return NULL;
    }
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = x;
        p->next = top;
        top = p;
        return top;
    }
}

int pop(struct Node **top)
{
    if (isStackEmpty(*top))
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node *temp = *top;
    *top = (*top)->next;
    int x = temp->data;
    free(temp);
    return x;
}

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 6);
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 9);
    traversal(top);
    printf("%d", pop(&top));
    traversal(top);
}