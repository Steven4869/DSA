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

    void create(int arr[], int n);
    void reverse(Node *head);
    void display();
};

void LinkedList::reverse(Node *head)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = head;
        head = head->next;
        q->next = r;
    }
    head = q;
}
void LinkedList::create(int arr[], int n)
{
    Node *temp, *last;
    head = new Node;
    head->data = arr[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
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
    LinkedList li;
    int arr[] = {3, 5, 7, 10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    li.create(arr, n);
    li.display();
    li.reverse(head);
    li.display();
    return 0;
}