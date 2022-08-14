// 1-3-2 Pattern
// Input: 142
// Output true

// Approach
// 1. We'll use stack for this question
// 2. Put inside the stack and check for the values to be greater than array's ith value
// 3. if the last number happens to be less than val then return true

#include <bits/stdc++.h>
using namespace std;

bool 132Pattern(int arr[], int n)
{
    int val = INT_MIN;
    // Intialise stack
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (val > arr[i])
        {
            return true;
        }
        else
        {
            while (!st.empty() && arr[i] > st.top())
            {
                val = st.top();
                st.pop();
            }
        }
        st.push(arr[i]);
    }
    return false;
}

int main()
{
    int arr[] = {1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    132Pattern(arr, n);
}