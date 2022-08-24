#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void RinOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    RinOrder(root->left);
    cout << root->data << " ";
    RinOrder(root->right);
}
void inOrder(Node *root)
{
    // Creating a satck
    stack<Node *> st;
    // Creating a current node with root

    Node *curr = root;
    // Run the loop until cuurent becomes NULL and stack becomes empty
    while (curr != NULL || st.empty() == false)
    {
        // Reach the leftmost node
        while (curr != NULL)
        {
            // Push the current node to the stack
            st.push(curr);
            curr = curr->left;
        }

        // Curr must be NULL
        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        // We have visited the  node and its left subtree
        // Now it's time for its right subtree

        curr = curr->right;
    }
}

struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return (node);
}
int main()
{
    struct Node *root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    RinOrder(root);
}