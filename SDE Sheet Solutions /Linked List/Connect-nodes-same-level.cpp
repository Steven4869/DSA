#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *nextRight;
};

void connect(Node *root)
{
    // Base Condition
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        Node *prev = NULL;
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (prev != NULL)
            {
                prev->nextRight = temp;
            }
            prev = temp;
        }
        prev->nextRight = NULL;
    }
}
struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = node->nextRight = NULL;
    return (node);
}

int main()
{
    struct Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    connect(root);

    cout << "Following are populated nextRight pointers in the tree"
            " (-1 is printed if there is no nextRight)\n";
    cout << "nextRight of " << root->data << " is "
         << (root->nextRight ? root->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->left->data << " is "
         << (root->left->nextRight ? root->left->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->right->data << " is "
         << (root->right->nextRight ? root->right->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->left->left->data << " is "
         << (root->left->left->nextRight ? root->left->left->nextRight->data : -1) << endl;
    return 0;
}