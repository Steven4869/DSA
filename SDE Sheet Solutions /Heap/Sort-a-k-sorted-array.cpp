// Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

// Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
//             k = 3
// Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

// Approach
// 1. By direct sorting- it'll take O(NLogN) time but given we have to do in NLogK so using Heap is right way here.
// 2. Since we'll be sorting we are expecting the bigger elements on the bottom and smaller elements on the top, so min heap is the way to go
// 3. Push the elements into heap, and if the size is greater than then push them into the array then pop them out from the heap
// 4. Keep doing it and for the remaining elements, make up a while loop until size gets to zero and push them into the array then pop them out

// Code
#include <bits/stdc++.h>
using namespace std;

void KSorted(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            arr[j++] = pq.top();
            pq.pop();
        }
    }
    // For remaining elements
    while (pq.size() > 0)
    {
        arr[j++] = pq.top();
        pq.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    KSorted(arr, n, k);
    return 0;
}