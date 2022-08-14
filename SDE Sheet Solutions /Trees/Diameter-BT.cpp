// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

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

int solve(Node *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftTree = solve(root->left, res);
    int rightTree = solve(root->right, res);

    int temp = 1 + max(leftTree + rightTree);
    int ans = max(temp, 1 + leftTree + rightTree);
    res = max(res, ans);
    return temp;
}
int Diameter(Node *root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}