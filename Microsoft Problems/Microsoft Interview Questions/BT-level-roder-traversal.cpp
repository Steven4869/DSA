#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void Levelorder(Node *root)
{
    // Base Consition
    if (root == NULL)
    {
        return;
    }

    // Create a Queue
    queue<Node *> q;

    // Push the root value to queue

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data;
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

// Creating a New Node

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

    Levelorder(root);
    return 0;
}