// Maximum Contagious Sum
//  Given an integer array arr, find the contiguous subarray (containing at least one number) which
//  has the largest sum and return its sum and print the subarray.

// Input: arr = [-2,1,-3,4,-1,2,1,-5,4]

// Output: 6

// Approach
// Brute Force
// Run two loops and find the max subarray by maing current sum and max sum - O(N^2)
// Better Approach
// Run a single loop and find the current sum with each number of array and check for its max sum

// Brute Force

#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int n)
{
    int max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        int current_sum = 0;
        for (int j = i; j < n; j++)
        {
            current_sum = current_sum + arr[j];
            if (current_sum > max_sum)
            {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}
// TC:O(N^2) SC:O(1)

// Efficient Approach
// Runnning the loop only once to obtain sum
// Compare it with maximum sum, if it's greater then allot its value to max sum
// if current sum is < 0 then make the sum =0

int solve2(int arr[], int n)
{
    int curr_sum = 0;
    int maximum_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
        if (curr_sum > maximum_sum)
        {
            maximum_sum = curr_sum;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return maximum_sum;
}
// TC:O(N) SC:O(1)

int main()
{
    int arr[] = {-1, -2, -3, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum sum of subarray is " << solve2(arr, n);
}