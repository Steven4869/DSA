#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d){
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

    cout<<"Enter the data for Left tree: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for Right tree: "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

//Level Order Traversal 

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

void inorderTraversalRecursion(Node *root){
    if(root==NULL){
        return;
    }

    inorderTraversalRecursion(root->left);
    cout<<root->data<<" ";
    inorderTraversalRecursion(root->right);
}

void inorderTraversalStack(Node *root){
    stack<Node*>st;
    Node *curr = root;
    
    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        
        curr = st.top();
        st.pop();
        
        cout<<curr->data<<" ";
        
        if(curr!=NULL){
            curr=curr->right;
        }
    }
}

void leftTreeTraversal(Node *root, vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        leftTreeTraversal(root->left, ans);
    }
    else{
        leftTreeTraversal(root->right, ans);
    }
}
void leafNodeTraversal(Node *root, vector<int>&ans){
    if(root== NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    leafNodeTraversal(root->left, ans);
    leafNodeTraversal(root->right, ans);
}
void rightTreeTraversal(Node *root, vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right){
        rightTreeTraversal(root->right, ans);
    }
    else{
        rightTreeTraversal(root->left, ans);
    }

    ans.push_back(root->data);
}
vector<int> boundaryLevelTraversal(Node *root){
    //Approach 
    //1. Get the Left side of tree except for the leaf node of left tree
    //2. Get the leaf nodes 
    //3. Get the right side of tree but in reverse directione except for the leaf node 

    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);

    //Left Tree Printing 
    leftTreeTraversal(root->left, ans);

    //Leaf Node Printing 
    leafNodeTraversal(root->left, ans);
    leafNodeTraversal(root->right, ans);

    //Right Tree Printing 
    rightTreeTraversal(root->right, ans);

    return ans;
}

vector<int> verticalLevelTraversal(Node *root){
    //Approach 
    //make the map of horixontal distance of levelwise ndoes
    map<int, map<int, vector<int>>> nodes;

    queue<pair<Node*, pair<int,int>>> q;
    vector<int>ans;

    if(root==NULL){
        return ans;
    }

    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty()){
        pair<Node*, pair<int,int>>temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
    }

    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
}

vector<int> topViewLevelTraversal(Node *root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>topNode;
    queue<pair<Node*, int>>q;

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto i:topNode){
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomViewTraversal(Node *root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>BottomNode;
    queue<pair<Node*,int>>q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        BottomNode[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i:BottomNode){
        ans.push_back(i.second);
    }

    return ans;
}

vector<int>leftView(Node *root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node *frontNode = q.front();
            q.pop();

            if(i == 0){
                ans.push_back(frontNode->data);
            }

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
    }

    return ans;
}


vector<int>rightView(Node *root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node *frontNode = q.front();
            q.pop();

            if(i == size-1){
                ans.push_back(frontNode->data);
            }

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
    }

    return ans;
}

int main(){
    Node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    cout<<"Inorder Traversal: ";
    inorderTraversalRecursion(root);
    cout<<endl;
    cout<<"Inorder Traversal using Stack: ";
    inorderTraversalStack(root);
    cout<<endl;

    cout << "Boundary Level Traversal: ";
    vector<int> boundaryTraversal = boundaryLevelTraversal(root);

    for (int val : boundaryTraversal) {
        cout << val << " ";
    }
    
    cout << endl;

    cout << "Vertical Level Traversal: ";
    vector<int> VerticalTraversal = verticalLevelTraversal(root);

    for (int val : VerticalTraversal) {
        cout << val << " ";
    }
    
    cout << endl;

    cout << "Top View Level Traversal: ";
    vector<int> topViewTraversal = topViewLevelTraversal(root);

    for (int val : topViewTraversal) {
        cout << val << " ";
    }
    
    cout << endl;

    cout << "Bottom View Level Traversal: ";
    vector<int> bottomTraversal = bottomViewTraversal(root);

    for (int val : bottomTraversal) {
        cout << val << " ";
    }
    
    cout << endl;

    cout << "Left View Level Traversal: ";
    vector<int> leftViewTraversal = leftView(root);

    for (int val : leftViewTraversal) {
        cout << val << " ";
    }
    
    cout << endl;

    cout << "Right View Level Traversal: ";
    vector<int> rightViewTraversal = rightView(root);

    for (int val : rightViewTraversal) {
        cout << val << " ";
    }
    
    cout << endl;

}

// 1 3 4 -1 -1 9 6 -1 -1 12 -1 -1 7 5 -1 -1 -1