#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    } // Parameterised Constructor
    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int stackTop();
    void Display();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    } // Value pushed it into the stack
}

int Stack::pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

int Stack::isEmpty()
{
    if (top == NULL)
        cout << "Stack is Empty";
    else
        cout << "Stack is not Empty";
    return 0;
}

void Stack::Display()
{
    Node *t = top;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int Stack::stackTop()
{
    if (top == NULL)
        cout << "Stack is empty";
    else
    {
        cout << top->data;
    }
    return 0;
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.Display();
    st.pop();
    st.Display();
    cout << endl;
    st.isEmpty();
    cout << endl;
    st.stackTop();

    return 0;
}