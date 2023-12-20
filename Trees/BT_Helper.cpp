#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node (int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node *buildTree(Node *root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the left Tree for:"<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right Tree for:"<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

//Counting the leaf Nodes

int countLeafNodes(Node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    
    int leftLeaf = countLeafNodes(root->left);
    int rightLeaf = countLeafNodes(root->right);
    
    return leftLeaf+rightLeaf;
}

int heightTree(Node *root){
    if(root==NULL){
        return 0;
    }

    int leftTree = heightTree(root->left);
    int rightTree = heightTree(root->right);

    return max(leftTree, rightTree)+1;
}
//Diameter of Binary Tree
//Either diameter passes theough the root node or reside in the either of left or right subtree
//We have to take the max out of it 

int diamterBT(Node *root){
    if(root==NULL){
        return 0;
    }
    int leftNode = diamterBT(root->left);
    int rightNode = diamterBT(root->right);
    int heightNode = heightTree(root->left)+heightTree(root->right)+1;
    return max(leftNode, max(rightNode, heightNode)); 
}

//Checking for Balanced Tree 
//A tree is balanced if the height of leftTree and rightTree should be <=1 for all nodes 
//Same Approach 
//Find the left tree and right tree then absolute value of left and right should be less than 1 
bool balancedTree(Node *root){
    if(root == NULL){
        return true;
    }

    bool leftNode = balancedTree(root->left);
    bool rightNode = balancedTree(root->right);
    bool difference = (abs(heightTree(root->left))-abs(heightTree(root->right)))<=1;

    if(leftNode && rightNode && difference){
        return true;
    }
    return false;
}
int main(){
    Node *root = NULL;
    root = buildTree(root);
    cout<<"Number of Leaf Nodes: "<<countLeafNodes(root)<<endl;
    cout<<"Height of BT is: "<<heightTree(root)<<endl;
    cout<<"Diameter of BT is: "<<diamterBT(root)<<endl;
    if(balancedTree(root)){
        cout<<"Tree is Balanced"<<endl;
    }
    else{
        cout<<"Tree is not Balanced"<<endl;
    }

}

// 1 3 4 -1 -1 9 -1 -1 7 5 -1 -1 -1