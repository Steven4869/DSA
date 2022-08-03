#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void createA(int arr[], int n)
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
void createB(int arr[], int n)
{
    struct Node *temp, *last;
    second = new Node;
    second->data = arr[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void Merge(struct Node *list1, struct Node *list2)
{
    // Creating another node last
    struct Node *last;
    // Making the first merged node
    if (list1->data < list2->data)
    {
        third = last = list1;
        list1 = list1->next;
        third->next = NULL;
    }
    else
    {
        third = last = list2;
        list2 = list2->next;
        third->next = NULL;
    }

    // Merging of differnet nodes
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            last->next = list1;
            last = list1;
            list1 = list1->next;
            last->next = NULL;
        }
        else
        {
            last->next = list2;
            last = list2;
            list2 = list2->next;
            last->next = NULL;
        }
    }

    if (list1 != NULL)
    {
        last->next = list1;
    }
    if (list2 != NULL)
    {
        last->next = list2;
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

int main()
{
    int arr1[] = {3, 38, 31, 37, 55};
    int arr2[] = {20, 25, 30, 35, 40};
    createA(arr1, 5);
    createB(arr2, 5);
    Merge(first, second);
    Display(third);
}