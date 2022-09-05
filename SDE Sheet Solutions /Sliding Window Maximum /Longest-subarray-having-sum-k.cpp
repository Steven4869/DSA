#include <bits/stdc++.h>
using namespace std;

int LongestSubarray(int arr[], int n, int k)
{
    int i = 0, j = 0, sum = 0;
    int maxLen = INT_MIN;
    while (j < n)
    {
        sum = sum + arr[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum = sum - arr[i];
                i++;
            }
            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
    }
    return maxLen;
}

int main()
{
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;
    cout << LongestSubarray(arr, n, k);
    return 0;
}