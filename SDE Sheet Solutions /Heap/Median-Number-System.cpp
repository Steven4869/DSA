// Find Median of a Number System
// Input :3,1,5,4
// Output : 3, 2, 3, 3.5

// Create two heaps, Max Heap for the left elements and Min heap for the right element
// If the elements are odd then the median is the top element of the Max heap
// If the elements are even then the median is the average of the top element of Min and Max Heap

#include <bits/stdc++.h>
using namespace std;

void MedianDataStream(int arr[], int n)
{
    // Creating Max Heap
    priority_queue<int> left;
    // Creating Min heap
    priority_queue<int, vector<int>, greater<int>> right;

    // First element will always be the median
    int median = arr[0];
    left.push(arr[0]);
    cout << median << " ";
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        // If the left side has more elements
        if (left.size() > right.size())
        {
            if (x < median)
            {
                right.push(left.top());
                left.pop();
                left.push(x);
            }
            else
            {
                right.push(x);
            }
            median = (left.top() + right.top()) / 2;
        }
        else if (left.size() == right.size())
        {
            if (x < median)
            {
                left.push(x);
                median = left.top();
            }
            else
            {
                right.push(x);
                median = right.top();
            }
        }
        else
        {
            if (x < median)
            {
                left.push(right.top());
                right.pop();
                right.push(x);
            }
            else
            {
                left.push(x);
            }
            median = (left.top() + right.top()) / 2;
        }
        cout << median << " ";
    }
}