// Sliding Window Maximum
// Problem Statement: Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

// Input: arr = [4,0,-1,3,5,3,6,8], k = 3

// Output: [4,3,5,5,6,8]

// Explanation:

// Window position                   Max
// ------------------------         -----
// [4  0  -1] 3  5  3  6  8           4
//  4 [0  -1  3] 5  3  6  8           3
//  4  0 [-1  3  5] 3  6  8           5
//  4  0  -1 [3  5  3] 6  8           5
//  4  0  -1  3 [5  3  6] 8           6
//  4  0  -1  3  5 [3  6  8]          8

// Approach
// 1. Take a for loop for the elements (there are total n-k elemenets)
// 2. Intialise the maximum as the arr[i]th element
// 3. Run another loop from 1 to k
// 4. if(i+j)th term of arr is greater than maximum then change the maximum
// 5. Return the maximum

#include <bits/stdc++.h>
using namespace std;

void MaximumSlidingWindow(int arr[], int n, int k)
{
    // Intiale the loop till n-k elements
    for (int i = 0; i <= n - k; i++)
    {
        int maxi = arr[i];
        for (int j = 1; j < k; j++)
        {
            if (arr[i + j] > maxi)
            {
                maxi = arr[i + j];
            }
        }
        cout << maxi << " ";
    }
}
// TC:O(N*K) SC:O(1)

// Better approach
// To use Heap, as we need to find maximum and k is given
// 1. We need to use the max elements at the top, so we have to go with Max Heap
// 2. We need to take pair, first one will arr[i] as it'll get sorted automatically and i in the second
// 3. Push the first elemennt, then do the loop for k elements and add elements into it
// 4. Pop the unnecssary elements and return the array

int HeapSlidingWindow(int arr[], int n, int k)
{
    priority_queue<pair<int, int>> pq;
    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i], i});
    }
    result.push_back(pq.top().first);
    for (int i = k; i < n; i++)
    {
        pq.push({arr[i], i});
        while (!(pq.top().second > i - k))
        {
            pq.pop();
        }
        result.push_back(pq.top().first);
    }
    return result;
}

int main()
{
    int arr[] = {4, 0, -1, 3, 5, 3, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    HeapSlidingWindow(arr, n, k);
    return 0;
}