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

void Inorder(struct Node *root, vector<int> res)
{
    if (root = NULL)
    {
        return;
    }
    Inorder(root->left, res);
    res.push_back(root->data);
    Inorder(root->right, res);
}

int KthSmallest(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    vector<int> ans;
    Inorder(root, ans);
    return ans[k - 1];
}
