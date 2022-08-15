// Left View of Binary Tree
// We need to print the element that appears in the left side of Binary tree

// Approach

// Since we'll be traversing the each node and won't be returning back, so BFS should be used
// Make up a queue and traverse until queue is empty
//
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
    return node;
}

vector<int> LeftView(Node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return NULL;
    }
}