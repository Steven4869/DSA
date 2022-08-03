// Count Maximum Consecutive One’s in the array
// Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

// Input: prices = {1, 1, 0, 1, 1, 1}

// Output: 3

// Approach
// 1. Make a count variable to get the count of 1
// 2. Create a maximum variable to get maximum count of 1
// 3. Run the loop, if the arr[i] happens to be zero then make count to 0

#include <bits/stdc++.h>
using namespace std;

int MaxCount(int arr[], int n)
{
    int count = 0;
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        maximum = max(maximum, count);
    }
    return count;
}
// TC:O(N) SC:O(1)
int main()
{
    int arr[] = {1, 1, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MaxCount(arr, n);
}