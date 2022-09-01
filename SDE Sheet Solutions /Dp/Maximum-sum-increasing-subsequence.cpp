// Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.

// Example 1:

// Input: N = 5, arr[] = {1, 101, 2, 3, 100}
// Output: 106
// Explanation:The maximum sum of a
// increasing sequence is obtained from
// {1, 2, 3, 100}

// Approach
// This question is similar to that of Longest Increasing Subsequence but we only have to make few chnages about the sum

#include <bits/stdc++.h>
using namespace std;

int SumOfLIS(int arr[], int n)
{
    // TO get the sum
    int result = 0;
    // Make up a dp table of size n
    int t[n];
    // Initalise the table with the array values
    for (int i = 0; i < n; i++)
    {
        t[i] = arr[i];
    }
    // To gather the maximum sum for the increasing subsequence
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                t[i] = max(t[i], t[j] + arr[i]);
            }
        }
    }
    for (auto i : t)
    {
        result = max(result, i);
    }
    return result;
}

int main()
{
    int arr[] = {1, 101, 2, 3, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << SumOfLIS(arr, n);
}