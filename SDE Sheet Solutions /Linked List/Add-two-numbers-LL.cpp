// Add two numbers represented as Linked Lists
// Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// num1  = 342, num2 = 564

// l1 = [2,4,3]
// l2 = [5,6,4]

// Result: sum = 807; L = [7,0,8]

// Approach
// 1. First create a dummy node and have temp pointer point on it
// 2. then create two varianles sum and carry
// 3. check if the l1 is not Null, if not then add it to sum , do the same for l2
// 4. Add the sum with carry
// 5. Make carry = sum/10;
// 6. Create another node with value sum%10
// 7. Point the temp's next to the above node and move the temp to temp's next

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

void AddTwoNumbers(struct Node *list1, struct Node *list2)
{
    Node *dummy = new Node;
    Node *temp = dummy;
    int carry = 0;
    while (list1 != NULL || list2 != NULL || carry != 0)
    {
        int sum = 0;
        if (list != NULL)
        {
            sum = sum + list1->data;
            list1 = list1->next;
        }
        if (list2 != NULL)
        {
            sum = sum + list2->data;
            list2 = list2->next;
        }
        sum = sum + carry;
        carry = sum / 10;
        Node *newNode = new Node(sum % 10);
        temp->next = newNode;
        temp = temp->next;
    }
    return dummy->next;
}