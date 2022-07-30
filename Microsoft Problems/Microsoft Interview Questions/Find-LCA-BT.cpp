#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *LCA(Node *root, Node *a, Node *b)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root == a || root == b)
    {
        return root;
    }
    Node *leftchild = LCA(root->left, a, b);
    Node *rightchild = LCA(root->right, a, b);

    if (leftchild == NULL)
    {
        return rightchild;
    }
    if (rightchild == NULL)
    {
        return leftchild;
    }
    return root;
}

struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << LCA(root, root->left, root->right);
    return 0;
}