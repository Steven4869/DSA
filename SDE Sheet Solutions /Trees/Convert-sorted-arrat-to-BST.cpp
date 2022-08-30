#include <bits/stdc++.h>
using namespace std;

// Approach
// 1. Middle element will be the root node
// 2. Leftward array will be the left nodes whereas rightward array will be the right node

struct Node
{
    int data;
    struct Node *left;
    struct Ndoe *right;
};
Node *helper(vector<int> &nums, start, end)
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
Node *sortedArrayToBST(vector<int> nums)
{
    return helper(nums, 0, nums.size() - 1);
}