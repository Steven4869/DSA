#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    struct Node
    {
        int val;
        int minimum;
        Node *next;

        Node(int val, int minimum, Node *next)
        {
            this->val = val;
            this->minimum = minimum;
            this->next = next;
        }
    };
    Node *head;

public:
    MinStack()
    {
        head = NULL;
    }
    void push(int val)
    {
        if (head == NULL)
        {
            head = new Node(val, val, NULL);
        }
        else
        {
            head = new Node(val, min(val, head->minimum), head);
        }
    }
    void pop()
    {
        head = head->next;
    }
    int top()
    {
        return head->val;
    }
    int getMin()
    {
        return head->minimum;
    }
}