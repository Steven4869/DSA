#include <bits/stdc++.h>
using namespace std;

// Initialising the Node
class Node
{
public:
    int data;
    Node *next;

    // Creating Constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList(){
        this->head=nullptr;
    }

    void insert(int data){
        Node *newNode = new Node(data);
        if(head==nullptr){
            head=newNode;
            return;
        }

        Node *currNode = head;
        while(currNode->next!=nullptr){
            currNode = currNode->next;
        }
        currNode->next=newNode;
    }

    void display(){
        Node *currNode = head;
        while (currNode!=nullptr)
        {
            cout<<currNode->data<<"->";
            currNode=currNode->next;
        }
        cout<<"NULL";
        cout<<endl;
    }
};

int main(){
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);

    list.display();

    return 0;
}