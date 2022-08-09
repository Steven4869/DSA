// Next Smaller Element

// Given an array, print the Next Smaller Element (NSE) for every element. The NSE for an element x is the first smaller element on the right side of x in array. Elements for which no smaller element exist (on right side), consider NSE as -1.
// Examples:
// a) For any array, rightmost element always has NSE as -1.
// b) For an array which is sorted in increasing order, all elements have NSE as -1.
// c) For the input array [4, 8, 5, 2, 25}, the NSE for each element are as follows.

// Element         NSE
//    4      -->    2
//    8      -->    5
//    5      -->    2
//    2      -->   -1
//    25     -->   -1

// Approach
//  1. Question is similar to NGE

#include <bits/stdc++.h>
using namespace std;

void NSE(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                break;
            }
        }
        cout << "NSE of " << arr[i] << " is " << temp << endl;
    }
}

// Using stack

void StackNSE(int arr[], int n)
{
    stack<int> st;
    st.push(arr[0]);
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
            continue;
        }

        else if (!st.empty() && st.top() > arr[i])
        {
            cout << "NSE of " << st.top() << " is " << arr[i] << endl;
            st.pop();
        }
        st.push(arr[i]);
    }
    while (!st.empty())
    {
        cout << "NSE of " << st.top() << " is " << -1 << endl;
        st.pop();
    }
}
int main()
{
    int arr[] = {4, 8, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    StackNSE(arr, n);
    return 0;
}