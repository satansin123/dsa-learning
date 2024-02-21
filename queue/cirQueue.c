#include <stdio.h>
#include <stdlib.h>

struct cirQueue
{
    int size;
    int front;
    int back;
    int *arr;
};

int isEmpty(struct cirQueue *q)
{
    if (q->back == q->front)
    {
        return 1;
    }
    return 0;
}

int isFull(struct cirQueue *q)
{
    if (((q->back + 1) % (q->size)) == q->front)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct cirQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->back = (q->back + 1) % q->size;
        q->arr[q->back] = val;
        printf("%d :Enqueued  \n", val);
    }
}

int dequeue(struct cirQueue *q)
{

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        q->front = ((q->front + 1) % q->size);
        return q->arr[q->front];
    }
}

void display(struct cirQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    int index = q->front + 1;
    do
    {
        printf("%d ", q->arr[index]);
        index = (index + 1) % q->size;
    } while (index != q->front);

    printf("\n");
}

int main()
{
    struct cirQueue q;
    q.size = 5;
    q.front = q.back = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    printf("%d: dequed\n", dequeue(&q));
    printf("%d dequed\n", dequeue(&q));
    display(&q);

    enqueue(&q, 9);
    enqueue(&q, 10);
    display(&q);

    return 0;
}