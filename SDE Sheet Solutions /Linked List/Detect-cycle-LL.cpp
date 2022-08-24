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

void Display(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Detecting Cycle in Linked List
bool Cycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

// Finding the starting point of the cycle
Node *DetectStartingPoint(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *result = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (slow == fast)
        {
            while (slow != result)
            {
                slow = slow->next;
                result = result->next;
            }
            return result;
        }
    }
    return NULL;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    Display(first);
    Node *res = DetectStartingPoint(first);
    if (res == NULL)
    {
        cout << "loop doesn't exist" << endl;
    }
    else
    {
        cout << "Loop's starting point is " << res->data << endl;
    }
}