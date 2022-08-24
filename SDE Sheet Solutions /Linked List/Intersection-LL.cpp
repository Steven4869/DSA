#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *IntersectionLL(Node *head1, Node *head2)
{
    while (head2 != NULL)
    {
        Node *temp = head1;
        while (temp != NULL)
        {
            if (temp == head2)
            {
                return head2;
            }
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}