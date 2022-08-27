// Given an array of positive integers, and a positive number k, find the maximum sum of any contiguous subarray of size k.

// Example 1

// Input: [3, 5, 2, 1, 7], k=2
// Output: 8
// Explanation: Subarray with maximum sum is [1, 7].

// Sliding Window -> k(tick), array(tick)
// Fixed size SWM
// Window size is always (j-i+1)

// 1. Initalise two variables start, end set to zero and point it to first element of array
// 2. Initalise window sum and max sum, window sum stores the sum of current widnow
// 3. Check for the window size, if (j-i+1==k) then we have found the required window
// 4. Find the max sum from it
// 5. Basic idea is that we are subtarcting the element that's going out from the windoe and adding the upcoming element

#include <bits/stdc++.h>
using namespace std;

int MaximumSumSubarray(int arr[], int n, int k)
{
    // Base condition
    int i = 0, j = 0, sum = 0;
    int maximum = INT_MIN;
    while (j < n)
    {
        sum = sum + arr[j];
        // If the window size is less than k then increment the j
        if (j - i + 1 < k)
        {
            j++;
        }
        // If the size is equal to k
        else if (j - i + 1 == k)
        {
            maximum = max(maximum, sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    return maximum;
}

int main()
{
    int arr[] = {3, 5, 2, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << MaximumSumSubarray(arr, n, k);
    return 0;
}