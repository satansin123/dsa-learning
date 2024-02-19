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

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr, *p;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr, *p;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node *insertAtAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 12;
    third->next = NULL;

    head = insertAtFirst(head, 50);
    traversal(head);
    head = insertAtIndex(head, 60, 3);
    printf("\n");
    traversal(head);
    head = insertAtEnd(head, 80);
    printf("\n");
    traversal(head);
    head = insertAtAfterNode(head, second, 890);
    printf("\n");
    traversal(head);
    return 0;
}