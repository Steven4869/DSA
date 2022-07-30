// You are given an array of prices where prices[i] is the price of a given stock on an ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Input: prices = [7,1,5,3,6,4]
// Output: 5

// Approach
// 1. Traverse the arry and find the minimum value from the array
// 2. then find the next biggest element, profit would be maximum found element - minimum found element

#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int n)
{
    int minimum = INT_MAX;
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        minimum = min(minimum, arr[i]);
        maximum = max(maximum, arr[i] - minimum);
    }
    return maximum;
}

// TC:O(N) SC:O(1)

int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << solve(arr, n);
    return 0;
}