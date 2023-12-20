#include<bits/stdc++.h>
using namespace std;

//Creating the node for tree 

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
    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;

    root = new Node(data);
    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for left tree: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for right tree: "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

//Traversal to display the tree 

void levelOrderTraversal(Node *root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *frontNode = q.front();
        q.pop();

        if(frontNode == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<frontNode->data<<" ";
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
    }
}

int main(){
    Node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    return 0;
}