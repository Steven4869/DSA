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

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Miscallaneous LL operatons

// 1. To find the middle of LL
void Middle(struct Node *head)
{
    Node *slow = head;
    Node *fast = head;
    if (head != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element of the list :" << slow->data;
    }
}

// 2. Sum of All elements
int Sum(struct Node *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum = sum + head->data;
        head = head->next;
    }
    return sum;
}
// 3. Search in LL
bool Search(struct Node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}
// 4. Inserting a new node in between nodes
void Insert(int position, int x)
{
    struct Node *temp, *prev;
    // At the beginning
    if (position == 0)
    {
        temp = new Node;
        temp->data = x;
        temp->next = first;
        first = temp;
    }
    else if (position > 0)
    {
        prev = first;
        for (int i = 0; i < position - 1 && prev != NULL; i++)
        {
            prev = prev->next;
        }
        if (prev != NULL)
        {
            temp = new Node;
            temp->data = x;
            temp->next = prev->next;
            prev->next = temp;
        }
    }
}

// 5. Deleting node from LL
// 2->3->4->5
int Delete(struct Node *head, int position)
{
    struct Node *q;
    int x = -1;
    if (position == 1)
    {
        x = first->data;
        head = first;
        first = first->next;
        delete head;
    }
    else
    {
        head = first;
        q = NULL;
        for (int i = 0; i < position - 1; i++)
        {
            q = head;
            head = head->next;
        }
        if (head != NULL)
        {
            q->next = head->next;
            x = head->data;
            delete head;
        }
    }
    return x;
}
// 6. Reversing the LL
// We'll use the idea of sliding pointers
void Reverse(struct Node *head)
{
    // Initialising two pointers
    Node *q = NULL;
    Node *r = NULL;
    while (head != NULL)
    {
        r = q;
        q = head;
        head = head->next;
        q->next = r;
    }
    first = q;
}
int main()
{
    int arr[] = {3, 5, 7, 10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    Display(first);
    Middle(first);
    cout << "\n"
         << Sum(first);
    cout << "\n"
         << Search(first, 15);
    Insert(2, 18);
    Display(first);
    Delete(first, 3);
    Display(first);
    Reverse(first);
    Display(first);
}
