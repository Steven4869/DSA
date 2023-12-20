#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node *head;

    LinkedList() {
        this->head = nullptr;
    }

    void insert(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node *currNode = head;

        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }

    void display() {
        Node *currNode = head;
        while (currNode != nullptr) {
            cout << currNode->data << "->";
            currNode = currNode->next;
        }
        cout << "NULL" << endl;
    }

    void partition(int x) {
        Node *lessList = nullptr;
        Node *lessTail = nullptr;
        Node *greaterList = nullptr;
        Node *greaterTail = nullptr;

        Node *currNode = head;
        while (currNode != nullptr) {
            if (currNode->data < x) {
                if (lessList == nullptr) {
                    lessList = currNode;
                    lessTail = currNode;
                } else {
                    lessTail->next = currNode;
                    lessTail = currNode;
                }
            } else {
                if (greaterList == nullptr) {
                    greaterList = currNode;
                    greaterTail = currNode;
                } else {
                    greaterTail->next = currNode;
                    greaterTail = currNode;
                }
            }
            currNode = currNode->next;
        }

        if (lessList == nullptr) {
            head = greaterList;
        } else {
            head = lessList;
            lessTail->next = greaterList;
        }
        if (greaterList != nullptr) {
            greaterTail->next = nullptr;
        }
    }
};

int main() {
    LinkedList list;

    list.insert(3);
    list.insert(5);
    list.insert(8);
    list.insert(5);
    list.insert(10);
    list.insert(2);
    list.insert(1);

    cout << "Before partition: ";
    list.display();

    list.partition(5);

    cout << "After partition: ";
    list.display();

    return 0;
}
