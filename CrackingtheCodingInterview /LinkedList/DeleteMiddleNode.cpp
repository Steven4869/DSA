#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        this->head = nullptr;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *currNode = head;

        while (currNode->next != nullptr)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }

    void display()
    {
        Node *currNode = head;
        while (currNode != nullptr)
        {
            cout << currNode->data << "->";
            currNode = currNode->next;
        }
        cout << "NULL" << endl;
    }

    void deleteMiddleElement()
    {
        if (head == nullptr || head->next == nullptr||head->next->next==nullptr)
        {
            return;
        }
        Node *slow = head;
        Node *fast = head->next->next;
        while (fast->next != nullptr && fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *middleNode = slow->next;
        slow->next=middleNode->next;
        delete middleNode;
    }
};

int main()
{
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);

    list.display();
    list.deleteMiddleElement();
    list.display();

    return 0;
}