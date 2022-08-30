#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *invertTree(Node *root)
{
    if (root = NULL)
    {
        return root;
    }
    Node *temp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = temp;
    return root;
}