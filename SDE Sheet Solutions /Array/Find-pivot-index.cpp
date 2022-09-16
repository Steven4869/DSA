#include <bits/stdc++.h>
using namespace std;

// Approach
// 1. Use Prefix sum for this question
// 2. Find total sum
// 3. Find left and right sum and check if they are equal or not
// 4. Make left sum to be sum - current index of arr and right sum to be 0 initially

int PivotIndex(int arr[], int n)
{
    int sum = 0;
    int left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    left = sum - arr[0];
    int i = 1;
    for (int i = 1; i < n; i++)
    {
        if (left == right)
        {
            return i - 1;
        }
        left = left - arr[i];
        right = right + arr[i - 1];
    }
    if (left == right)
    {
        return i - 1;
    }
    return -1;
}