// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Approach
// Make up a result variable and store the first element of the array
// Create two other variables, imax, imin to get the max and min value of the array
// if the value of array is less than 0 then swap the imin and imax values

#include <bits/stdc++.h>
using namespace std;

int MaxProductSubarray(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1, imax = result, imin = result; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(imax, imin);
        }
        imax = max(arr[i], imax * arr[i]);
        imin = min(arr[i], imin * arr[i]);
        result = max(result, imax);
    }
    return result;
}

int main()
{
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MaxProductSubarray(arr, n);
}