// Next Greater Element

// Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1.

// Examples:

// For an array, the rightmost element always has the next greater element as -1.
// For an array that is sorted in decreasing order, all elements have the next greater element as -1.
// For the input array [4, 5, 2, 25], the next greater elements for each element are as follows.

// Element       NGE
//    4      -->   5
//    5      -->   25
//    2      -->   25
//    25     -->   -1

// Approach
// 1. Using nested Loop
// 2. Run the loop and take the first element in it, initalise the dummy varlaible with -1
// 3, Run another loop with i+1 and check if arr[i]<arr[j], if then make the next as arr[j] then break the loop

#include <bits/stdc++.h>
using namespace std;

void NextGreaterElement(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                temp = arr[j];
                break;
            }
        }
        cout << "NGE of " << arr[i] << " is " << temp << endl;
    }
}
// TC:O(N^2) SC:O(1)

// To lower the time complexity we'll use stack
// 1. Initalise the stack and push the first element into stack
// 2. Iterate a for loop for the remaining elemnets
// 3. If the stack is empty then push the element in it
// 4. If it's not empty and top value is less than ith value, then that's its next greater element
// 5. Pop the element
// 6. All the remaining elements in the stack will have its NGE as -1

void SNextGreaterElement(int arr[], int n)
{
    // Initalise the stack
    stack<int> st;
    // Push the first element into stack
    st.push(arr[0]);
    // Iterate an for loop for the remainig elements
    for (int i = 1; i < n; i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
            continue;
        }
        // If stack is not empty then check it's top value
        while (!st.empty() && st.top() < arr[i])
        {
            cout << "NGE of " << st.top() << " is " << arr[i] << endl;
            st.pop();
        }

        // Push next to stack to find NGE
        st.push(arr[i]);
    }
    // For the remaining elements in stack will havr -1
    while (!st.empty())
    {
        cout << "NGE of " << st.top() << " is " << -1 << endl;
        st.pop();
    }
}
// TC:O(N) SC:O(N)
int main()
{
    int arr[] = {3, 3, 2, 1, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    SNextGreaterElement(arr, n);
    return 0;
}