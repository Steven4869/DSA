struct Node
{
    int data;
    struct Node *next = NULL;
} *first = NULL;

void create(int arr[], int n)
{
    Node *last, *temp;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node;
        temp->dat = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = NULL;

    return merge(sortList(head), sortList(fast));
}

Node *merge(Node *list1, Node *list2)
{
    Node *dummy = new Node(0);
    Node *tail = dummy;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if (list1 != NULL)
    {
        tail->next = list1;
    }
    if (list2 != NULL)
    {
        tail->next = list2;
    }
    return dummy->next;
}