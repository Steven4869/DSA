#include <bits/stdc++.h>
using namespace std;

// Approach
// 1. Middle element will be the root node
// 2. Leftward array will be the left nodes whereas rightward array will be the right node

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

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
Node *helper(int nums[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    Node *root = new Node(nums[mid]);
    root->left = helper(nums, start, mid - 1);
    root->right = helper(nums, mid + 1, end);
    return root;
}
Node *sortedArrayToBST(int nums[])
{
    return helper(nums, 0, nums.size() - 1);
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);
    Node *root = sortedArrayToBST(arr, 0, n - 1);
    preOrder(root);
}