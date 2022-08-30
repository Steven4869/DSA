#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} *root = NULL;

void Insert(int key)
{
    struct Node *temp = root;
    struct Node *r, *p;
    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->left = p->right = NULL;
        root = p;
        return;
    }
    while (temp != NULL)
    {
        r = temp;
        if (key < temp->data)
        {
            temp = temp->left;
        }
        else if (key > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            // It'll stop the loop
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->left = p->right = NULL;
    if (key < r->data)
    {
        r->left = p;
    }
    else
    {
        r->right = p;
    }
}
void Inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    while (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << "  ";
        Inorder(root->right);
    }
}

int main()
{
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    Inorder(root);
}