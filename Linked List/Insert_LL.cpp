#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList()
    {
        head = NULL;
    }

    void InsertElementAtFirst(int x);
    void InsertElementAtEnd(int x);
    void insertElementAfter(int x, int position);
    void deleteElement(int x);
    void display();
};

// Inserting element at beginning
void LinkedList::InsertElementAtFirst(int x)
{
    // Make up a new node
    Node *newNode = new Node;
    // insert the given data to newNode's data
    newNode->data = x;
    // Make newNode's next point to head
    newNode->next = head;
    // Make head pointer points to newNode
    head = newNode;
}

// Inserting Element at end
void LinkedList::InsertElementAtEnd(int x)
{
    Node *newNode = new Node;
    Node *temp = new Node;
    temp = head;
    newNode->data = x;
    if (temp == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->next = NULL;
    temp->next = newNode;
}

// Deleting in a Linked List
void LinkedList::deleteElement(int x)
{
    Node *del;
    del = head;

    if (del == NULL)
    {
        cout << "Linked List is empty";
        return;
    }
    if (del->data == x)
    {
        head = del->next;
        return;
    }
    if (del->next == NULL)
    {
        cout << "Cannot be deleted";
        return;
    }
    while (del->next != NULL)
    {
        if (del->next->data == x)
        {
            del->next = del->next->next;
            return;
        }
        del = del->next;
    }
    cout << "Element cannot be deleted";
}
void LinkedList::display()
{
    Node *current = head;
    if (current == NULL)
    {
        cout << "the list is empty" << endl;
    }
    while (current != NULL)
    {
        cout << current->data << " -> " << flush;
        current = current->next;
    }
    cout << endl;
}

int main()
{
    LinkedList li; // li is object from linkedlist class

    li.display(); // empty list

    li.InsertElementAtFirst(25); // head->25->NULL
    li.InsertElementAtFirst(36); // head->36->25->NULL
    li.InsertElementAtFirst(49); // head->49->36->25->NULL
    li.InsertElementAtFirst(64); // head->64->49->36->25->NULL
    cout << "After adding in the first of linked list" << endl;
    li.display();
    // 64
    // 49
    // 36
    // 25

    cout << endl;
    // head->64->49->36->25->NULL	//current linked list from prev InsertElementAtFirst method

    cout << "After adding in the end of linked list" << endl;
    li.InsertElementAtEnd(25); // head->25->NULL
    li.InsertElementAtEnd(36); // head->25->36->NULL
    li.InsertElementAtEnd(49); // head->25->36->49->NULL
    li.InsertElementAtEnd(64); // head->25->36->49->64->NULL
    li.display();
    // head->64->49->36->25->25->36->49->64->NULL

    cout << endl;

    // head->64->49->10->36->25->25->36->49->64->NULL
    cout << "linked list after adding deleting 49" << endl;
    li.deleteElement(49);
    li.display();
    // head->64->10->36->25->25->36->49->64->NULL
    // Notice :delete the first 49 ... not permission for duplicates

    return 0;
}