// Length of the longest subarray with zero Sum
// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

// Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}

// Result: 5

// Explanation: The following subarrays sum to zero:
// {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
// Since we require the length of the longest subarray, our answer is 5!

// Approach
// 1. Run two for loops and take the sum that gets into zero and take the maximum length

#include <bits/stdc++.h>
using namespace std;
int LargestSumZero(int arr[], int n)
{
    int max_len = 0;
    // Initialise the for loop
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];

            if (sum == 0)
            {
                max_len = max(max_len, j - i + 1);
            }
        }
    }
    return max_len;
}

// TC:O(N^2) SC:O(1)

// Efficient Approach
// Using Hashmap

int MaxLengthSum0(int arr[], int n)
{
    // Creating map
    unordered_map<int, int> mp;
    int sum = 0;
    int max_length = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (arr[i] == 0 && max_length == 0)
        {
            max_length = 1;
        }
        if (sum == 0)
        {
            max_length = i + 1;
        }
        if (mp.find(sum) != mp.end())
        {
            max_length = max(max_length, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return max_length
}
int main()
{
    int arr[] = {6, -2, 2, -8, 1, 7, 4, -10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << "Length of the longest 0 sum subarray is "
         << LargestSumZero(arr, n);
    return 0;
}