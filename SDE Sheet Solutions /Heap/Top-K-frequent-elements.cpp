// Find k numbers with most occurrences in the given array

// Given an array of n numbers and a positive integer k. The problem is to find k numbers with most occurrences, i.e., the top k numbers having the maximum frequency. If two numbers have the same frequency then the larger number should be given preference. The numbers should be displayed in decreasing order of their frequencies. It is assumed that the array consists of k numbers with most occurrences.

// Input:
// arr[] = {3, 1, 4, 4, 5, 2, 6, 1},
// k = 2
// Output: 4 1

// Approach
// 1. We have to sort the elemnts based on the frequencies, so usse map for the frequency
// 2. Sice we need most freuquenices, then the one with most will be at the bottom, so we are using min heap
// 3. The k elements remaining are the answer, pop them out like usuall method

#include <bits/stdc++.h>
using namespace std;
void KFrequent(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
    for (auto i : mp)
    {
        minH.push({i.second, i.first});
        if (minH.size() > k)
        {
            minH.pop();
        }
    }
    while (minH.size() > 0)
    {
        cout << minH.top().second << " ";
        minH.pop();
    }
}

int main()
{
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    KFrequent(arr, n, k);
    return 0;
}