#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void create(int arr[], int n)
{
    struct Node *last, *temp;
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
void OddneEven(struct Node *head)
{
    // Base condition
    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return;
    }
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        even->next = odd->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
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
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    Display(first);
    cout << "Printing Odd-Even List" << endl;
    OddneEven(first);
    Display(first);
}