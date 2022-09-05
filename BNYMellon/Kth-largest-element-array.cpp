// Given an integer array find the kth largest eleemnt in array where k is positive integer less than or equal to the length of array
// arr[]={7,4,6,3,9,1} k=2
// OP:7, 2nd largest element in array is 7

#include <bits/stdc++.h>
using namespace std;

void KthLargestElement(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    // while (pq.size() > 0)
    // {
    //     cout << pq.top();
    //     pq.pop();
    // }
    cout << pq.top();
}