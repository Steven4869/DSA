#include <bits/stdc++.h>
using namespace std;

int SubarraySum(int arr[], int n, int k)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = arr[i];
        if (sum == k)
        {
            ans++;
        }
        for (int j = i + 1; j < n; j++)
        {
            sum = sum + arr[j];
            if (sum == k)
            {
                ans++;
            }
        }
    }
    return ans;
}

// TC:O(N^2) SC:O(1)
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 9;
    cout << SubarraySum(arr, n, k);
}