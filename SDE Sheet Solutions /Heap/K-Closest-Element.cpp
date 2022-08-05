// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b

// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Approach
// 1. Identification of Heap - K closest
// 2. We'll find the absolute differnce of arr[i] with x value
// 3. Arrange them with the max elements on the top, so we'll go with max heap
// 4. Pair them up with absolute difference along with the arr value
// 5. We'll only take the remaining value of size k from the heap

#include <bits/stdc++.h>
using namespace std;
void KClosestElements(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({abs(arr[i] - x), arr[i]});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (pq.size() > 0)
    {
        cout << pq.top().second;
        pq.pop();
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    KClosestElements(arr, n, k, x);
}