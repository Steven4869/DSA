// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

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

    int KtoLast(int k){
        Node *p1=head;
        Node *p2=head;


        for(int i=0;i<k;i++){
            if(p2==nullptr){
                return -1;
            }
            p2=p2->next;
        }

        while(p2!=nullptr){
            p1=p1->next;
            p2=p2->next;
        }
        return p1->data;
    }
};


int main(){
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);


    list.display();
    
    cout<<list.KtoLast(2);

    return 0;
}