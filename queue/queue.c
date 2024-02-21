#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int back;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if (q->back == q->front)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if (q->back == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->back++;
        q->arr[q->back] = val;
    }
}

int dequeue(struct Queue *q)
{

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        q->front++;
        return q->arr[q->back];
    }
}

int display(struct Queue *q)
{
    for (int i = q->front + 1; i < q->back + 1; i++)
    {
        printf("%d\n", q->arr[i]);
    }
}

int main()
{
    struct Queue q;
    q.size = 100;
    q.front = q.back = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 5);
    enqueue(&q, 10);
    display(&q);

    return 0;
}