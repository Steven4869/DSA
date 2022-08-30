#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << ",";
    inOrder(root->right);
}
int main()
{
    struct Node *root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(4);
    inOrder(root);
}