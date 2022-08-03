// Rotate a Linked List
// Problem Statement: Given the head of a linked list, rotate the list to the right by k places.

// Input:
// 	head = [1,2,3,4,5]
// 	k = 2
// Output:
//  head = [4,5,1,2,3]

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

// Approach
// 1. Caluclate the length of the listh
// 2. Connect the last node to the first node
// 3. Iterate to cut the link fo last node and start a node of k%length of the list

void RotateList(struct Node *head, int k)
{
    if (head == NULL || head->next = NULL || k == 0)
    {
        return head;
    }
    Node *temp = head;
    int length = 1;
    while (temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }

    // Linking last node to first node
    temp->next = head;
    k = k % length;
    int end = length - k;
    while (end--)
    {
        temp = temp->next;
    }
    // breaking last node and point it to NULL
    head = temp->next;
    temp->next = NULL;
}
