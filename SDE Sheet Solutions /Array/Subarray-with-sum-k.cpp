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

// We can optimise by using extra space

int SubarraySumII(int arr[], int n, int k)
{
    int sum = 0;
    int count = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum == k)
        {
            count++;
        }
        if (mp.find(sum - k) != mp.end())
        {
            count = count + mp[sum - k];
        }
        mp[sum]++;
    }
    return count;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 9;
    cout << SubarraySum(arr, n, k);
}