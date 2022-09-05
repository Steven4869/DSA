#include <bits/stdc++.h>
using namespace std;

int LongestSubarray(int arr[], int k, int n)
{
    int sum = 0, count = 0, max_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] <= k)
        {
            sum = sum + arr[i];
            count++;
        }
        else if (sum != 0)
        {
            sum = sum - arr[i - count] + arr[i];
        }
        max_count = max(max_count, count);
    }
    return max_count;
}

int main()
{
    int arr[] = {1, 2, 1, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << LongestSubarray(arr, k, n);
    return 0;
}