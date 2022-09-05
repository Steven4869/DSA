// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

// Example 1:

// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

// Approach

// Brute Force
// 1. TAke two nested loops and find the occurence of each subarray profuct less than k

#include <bits/stdc++.h>
using namespace std;
int CountSubarray(int arr[], int n, int k)
{
    int count = 0;
    int multi;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < k)
        {
            count++;
        }
        multi = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            multi = multi * arr[j];
            if (multi < k)
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}

// Better method
// To use Sliding Window Method
// Subarray+k+array

int SlidingWindowProductSubarray(int arr[], int n, int k)
{
    int i = 0, j = 0;
    int count = 0;
    int multi = 1;
    while (j < n)
    {
        if (multi * arr[j] < k)
        {
            multi = multi * arr[j];
            count = count + (j - i + 1);
            j++;
        }
        else
        {
            if (i < j)
            {
                multi = multi / arr[i];
            }
            else
            {
                j++;
            }
            i++;
        }
    }
    return count;
}
int main()
{
    int arr[] = {10, 5, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 100;
    cout << SlidingWindowProductSubarray(arr, n, k);
}