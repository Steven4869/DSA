// Two Pointer Appraoch
// Take two pointers p and q, point it at respective nodes
// Run the loop until both of them meet
// If p is NULL then point it to q's node otherwise point it to next pointer
// Do the similar for the q
// return p pointer

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
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
void IntersectionPoint(Node *headA, Node *headB)
{
    Node *p = headA;
    Node *q = headB;
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    while (p != q)
    {
        p = p == NULL ? headB : p->next;
        q = q == NULL ? headA : q->next;
    }
    return p;
}