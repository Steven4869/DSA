// Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

// In case of multiple subarrays, return the subarray which comes first on moving from left to right.

// Input:
// N = 5, S = 12
// A[] = {1,2,3,7,5}
// Output: 1 3
// Explanation: The sum of elements
// from 2nd position to 4th position
// is 12.

// Approach
// 1. We'll go with two loops and check with each element
// 2. Assign sum with first element of arr, if the sum happens to be equal to target
// 3. then return the ith index and j-1th index
// 4. Otherwise increment sum with arr[j]
// 5. If the value exceeds target or j reaches to its end then break the loop

#include <bits/stdc++.h>
using namespace std;

void SubarraySum(int arr[], int n, int target)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (sum == target)
            {
                cout << i << " " << j - 1 << endl;
                return;
            }
            if (sum > target || j == n)
            {
                break;
            }
            sum = sum + arr[j];
        }
    }
    cout << "No subarray found";
    return;
}

int main()
{
    int arr[] = {1, 2, 3, 7, 5};
    int target = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    SubarraySum(arr, n, target);
}