// Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

// Input:
// N = 4
// arr[] = {1, 5, 3, 2}
// Output: 2
// Explanation: There are 2 triplets:
// 1 + 2 = 3 and 3 +2 = 5

// Approach
// 1. Run two loops and check for the sum, if it exists then increment the count

#include <bits/stdc++.h>
using namespace std;

int CountTriplets(int arr[], int n)
{
    int count = 0;
    unordered_set<int> st(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j++)
        {
            if (st.count(arr[i] + arr[j]))
            {
                count++;
            }
        }
    }
    return count;
}