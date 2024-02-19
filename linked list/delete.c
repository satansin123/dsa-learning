#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndexNode(struct Node *head, int index)
{
    struct Node *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    struct Node *q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

struct Node *deleteLastNode(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = ptr->next;

    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }

    ptr->next = NULL;
    free(q);
    return head;
}

struct Node *deleteAtValueNode(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {

        ptr = ptr->next;
        q = q->next;
    }
    if (q->data == value)
    {
        ptr->next = q->next;
        free(q);
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *seventh;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = fifth;

    fifth->data = 20;
    fifth->next = sixth;

    sixth->data = 27;
    sixth->next = seventh;

    seventh->data = 38;
    seventh->next = NULL;

    traversal(head);

    head = deleteFirstNode(head);
    printf("Linked list after deletion:\n");
    traversal(head);

    head = deleteAtIndexNode(head, 4);
    printf("Linked list after deletion:\n");
    traversal(head);

    head = deleteLastNode(head);
    printf("Linked list after deletion:\n");
    traversal(head);

    return 0;
}