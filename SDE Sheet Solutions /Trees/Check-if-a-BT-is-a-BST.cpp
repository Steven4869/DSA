#include <bits/stdc++.h>
using namespace std;

// A binary search tree has a properity that where its left subtrees
// have samller value than the node whereas its right sub tree have higher value
// than its node

// All we have to do is check the left's value and compare it to node
// similarly for the right node

// Declaring the Binary Tree
// A binary tree has a data, pointer to left and right child;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Creating a fucntion that will return true if a BT is BST

bool isBST(Node *root, Node *left_node = NULL, Node *right_node = NULL)
{

    // Base Conditioon - if root is NULL

    if (root == NULL)
    {
        return true;
    }

    // If left node exists then check if it has correct data or not
    // Left Node's data should be less than root's data

    if (left_node != NULL && root->data <= left_node->data)
    {
        return false;
    }
    // If right node exists then check if it has correct data or not
    // Right Node's data should be greater than root's data

    if (right_node != NULL && root->data >= right_node->data)
    {
        return false;
    }

    // Now check recursively for every node

    return isBST(root->left, left_node, root) && isBST(root->right, root, right_node);
}

// Function to create a new node;

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
    if (isBST(root, NULL, NULL))
    {
        cout << "The given Binary Tree is a BST";
    }
    else
    {
        cout << "The given Binary Tree is not a BST";
    }
    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(h) - h represents height of the tree
// Now it consumes some space and we need to look for a solution that doesn't consumes space
