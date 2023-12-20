#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        this->data = d;
        this->left=nullptr;
        this->right=nullptr;
    }
};

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<", ";
    inorder(root->right);
}

Node *insertIntoBST(Node *root, int d){
    if(root==NULL){
        root = new Node(d);
        return root;
    }
    if(d>root->data){
        root->right = insertIntoBST(root->right, d);
    }
    else{
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

Node *minVal(Node *root){
    Node *temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node *deleteFromBST(Node *root, int val){
    //base case
    if(root==NULL){
        return root;
    }
    if(root->data == val){
        // 0 child (Leaf Node)
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 child 
        // Left child 

        if(root->left != NULL && root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Right child 
        if(root->left == NULL && root->right != NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child nodes 

        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
void takeInput(Node *&root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}
int main(){
    Node *root = NULL;
    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    inorder(root);
    deleteFromBST(root, 8);
    inorder(root);
    return 0;
}