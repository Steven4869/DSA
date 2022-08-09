// Check for Balanced Parentheses
// Problem Statement: Check Balanced Parentheses. Given string str containing just the characters ‘(‘, ‘)’, ‘{‘, ‘}’, ‘[‘ and ‘]’, check if the input string is valid and return true if the string is balanced otherwise return false.

// Note: string str is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Input: str = “( )[ { } ( ) ]”

// Output: True

// Approach
// 1. We'll be using stack for this question
// 2. Intialise the stack first and push the bracket into it then check if top of the element is opening bracket then other paranthesis exists or not
// 3. If exists then pop the element into stack otherwise push it into stack
// 4. If the stack is empty then return true otherwise return false

#include <bits/stdc++.h>
using namespace std;

bool GenerateParanthesis(string str)
{
    // Initialise the stack
    stack<char> st;
    // Push the first elememt into stack
    for (int i = 0; i < str.length(); i++)
    {
        // Check if stack is empty
        if (st.empty())
        {
            st.push(str[i]);
        }
        else if ((st.top() == '(' && str[i] == ')') ||
                 (st.top() == '{' && str[i] == '}') ||
                 (st.top() == '[' && str[i] == ']'))
        {
            st.pop();
        }
        else
        {
            st.push(str[i]);
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}

// TC:O(N) SC:O(N)
int main()
{
    string str = "[()]{}{[()()]()}";
    if (GenerateParanthesis(str))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }
    return 0;
}