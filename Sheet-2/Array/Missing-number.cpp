// Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

// Example 1:

// Input:
// N = 5
// A[] = {1,2,3,5}
// Output: 4

#include <bits/stdc++.h>
using namespace std;

int MissingNumber(int arr[], int n)
{
    int sum = n * (n + 1) / 2;
    int total = 0;
    for (int i = 0; i < n - 1; i++)
    {
        total = total + arr[i];
    }
    return sum - total;
}

int AMissingNumber(int arr[], int n)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1;
        }
    }
    cout << -1;
}

int main()
{
    int arr[] = {1, 2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << AMissingNumber(arr, n);
}