#include <bits/stdc++.h>
using namespace std;
// Initialisation of Node structure
class Node
{
public:
    int data;
    Node *next;
};

int getCount(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int sum(Node *head)
{
    int sum = 0;
    Node *current = head;
    while (current != NULL)
    {
        sum = sum + current->data;
        current = current->next;
    }
    return sum;
}
int max_element(Node *head)
{
    int maximum = INT_MIN;
    Node *current = head;
    while (current != NULL)
    {
        maximum = max(maximum, current->data);
        current = current->next;
    }
    return maximum;
}
bool search(Node *head, int x)
{
    if (head == NULL)
    {
        return false;
    }
    if (head->data == x)
    {
        return true;
    }
    return search(head->next, x);
}
int main()
{
    int arr[] = {3, 5, 7, 10, 15};
    // Making up a new node
    Node *head = new Node;
    Node *temp;
    Node *last;

    // As the LL is empty we'll take the first data to head
    head->data = arr[0];
    head->next = NULL;
    last = head;

    // size of LL
    int n = sizeof(arr) / sizeof(arr[0]);
    // Creating a LL
    // i from 1 beecause 0th element is created
    for (int i = 1; i < n; i++)
    {
        // Creating a temp node;
        temp = new Node;

        temp->data = arr[i];
        temp->next = NULL;

        // last's next is pointing to temp
        last->next = temp;
        // Last should move to temp and temp should become a new node
        last = temp;
    }

    // Display of LL

    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " -> " << flush;
        p = p->next;
    }
    cout << endl;
    // Count of LL
    cout << "count of Linked List  is " << getCount(head);
    cout << endl;
    // Sum of LL
    cout << "sum of Linked List  is " << sum(head);
    cout << endl;
    // Sum of LL
    cout << "Maximum element in Linked List  is " << max_element(head);
    cout << endl;
    // Sum of LL
    cout << search(head, 15);
    return 0;
}