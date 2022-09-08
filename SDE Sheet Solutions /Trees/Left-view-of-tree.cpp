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
vector<int> leftView(Node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }
    queue<Node *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        int size = q.size();
        flag = 1;
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (flag == 1)
            {
                result.push_back(temp->data);
                flag = 0;
            }
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
    return result;
}