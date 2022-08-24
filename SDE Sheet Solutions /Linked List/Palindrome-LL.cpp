#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *reverseList(Node *head)
{
    Node *q = NULL;
    Node *r = NULL;
    Node *first = head;
    while (head != NULL)
    {
        r = q;
        q = head;
        head = head->next;
        q->next = r;
    }
    first = q;
    return q;
}

bool isPalindrome(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverseList(slow);
    while (slow != NULL)
    {
        if (slow->data != head->data)
        {
            return false;
        }
        slow = slow->next;
        head = head->next;
    }
    return true;
}

struct Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

int main()
{
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(5);

    bool found = isPalindrome(head);
    cout << found;
    return 0;
}