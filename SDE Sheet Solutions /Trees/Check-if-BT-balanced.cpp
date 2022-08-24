#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left; // self refrential structure - pointer of the structue of its own kind
    struct Node *right;
};

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (max(height(root->left), height(root->right)) + 1);
}

bool isBalanced(Node *root)
{
    int leftNode;
    int rightNode;

    if (root == NULL)
    {
        return true;
    }
    leftNode = height(root->left);
    rightNode = height(root->right);

    if (abs(leftNode - rightNode) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }

    return false;
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
    struct Node *root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    // Checking for BST
    if (isBalanced(root))
    {
        cout << "The given Binary Tree is a Balanced Binary Tree";
    }
    else
    {
        cout << "The given Binary Tree is not a Balanced Binary Tree";
    }
    return 0;
}
