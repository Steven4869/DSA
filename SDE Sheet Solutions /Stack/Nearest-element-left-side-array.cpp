#include <bits/stdc++.h>
using namespace std;

int Nearest(int arr[], int n)
{
    vector<int> result;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            result.push_back(-1);
        }
        else
        {
            result.push_back(st.top());
        }
        st.push(arr[i]);
    }
    return result;
}