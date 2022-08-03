// Remove N-th node from the end of a Linked List
// Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.

// Input: head = [1,2,3,4,5], n = 2

// Output: [1,2,3,5]

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int arr[], int n)
{
    struct Node *temp, *last;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void DeleteFromBack(struct Node *head, int n)
{
    Node *start = new Node;
    start->next = head;
    Node *fast = head;
    Node *slow = head;
    for (int i = 1; i <= n; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return;
    // retrun start->nexr;
}

void Display(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// TC:O(N) SC:O(1)
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    Display(first);
    DeleteFromBack(first, 2);
    Display(first);
}