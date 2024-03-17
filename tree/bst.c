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

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d,", root->data);
        inOrder(root->right);
    }
}
int isBst(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBst(root->right);
    }
    else
    {
        return 1;
    }
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

void insert(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("cannot insert already in bst");
            return;
        }

        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *new = newNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
struct Node *inOrderPredec(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct Node *delete(struct Node *root, int value)
{
    if ((root) == NULL)
    {
        return NULL;
    }

    if ((root)->left == NULL && (root)->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (value < (root)->data)
    {
        ((root)->left) = delete (((root)->left), value);
    }
    else if (value > (root)->data)
    {
        ((root)->right) = delete (((root)->right), value);
    }
    else
    {
        struct Node *ipre = inOrderPredec(root);
        (root)->data = ipre->data;
        ((root)->left) = delete (((root)->left), ipre->data);
    }
    return root;
}

int main()
{
    struct Node *p1 = newNode(9);
    struct Node *p2 = newNode(5);
    struct Node *p3 = newNode(11);
    struct Node *p4 = newNode(3);
    struct Node *p5 = newNode(6);
    struct Node *p6 = newNode(10);
    struct Node *p7 = newNode(12);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    p3->right = p7;

    inOrder(p1);
    printf("\n%d", isBst(p1));
    printf("\n");
    struct Node *s = search(p1, 7);
    if (s == NULL)
    {
        printf("Not Found");
    }
    else
    {
        printf("%d", s->data);
    }
    insert(p1, 7);
    printf("\n");
    inOrder(p1);
    delete (p1, 10);
    printf("\n");
    inOrder(p1);
}