#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->left = NULL;
    p->right = NULL;
    p->data = data;

    return p;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct Node *root)
{
    if (root != NULL)
    {

        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {

        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}
int main()
{
    struct Node *p1 = newNode(2);
    struct Node *p2 = newNode(5);
    struct Node *p3 = newNode(6);
    struct Node *p4 = newNode(7);
    struct Node *p5 = newNode(8);
    struct Node *p6 = newNode(9);
    struct Node *p7 = newNode(3);
    //      2
    //      /\ 
//     5  6
    //    / \ / \ 
//    7 8 9 3

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    p3->right = p7;

    preOrder(p1);
    printf("\n");
    postOrder(p1);
    printf("\n");
    inOrder(p1);

    return 0;
}