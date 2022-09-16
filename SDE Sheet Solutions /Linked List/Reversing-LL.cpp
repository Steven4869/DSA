// Both Iterative and Recurisve

// Iterative

struct Node
{
    int data;
    Node *next = NULL;
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

void Display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void ReverseLL(Node *head)
{
    Node *q = NULL;
    Node *r = NULL;
    while (head != NULL)
    {
        r = q;
        q - head;
        head = head->next;
        q->next = r;
    }
    first = q;
}

void RecursiveReverseLL(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp =
}