// Given an array of positive integers. All numbers occur an even number of times except one number which occurs an odd number of times. Find the number in O(n) time & constant space.

#include <bits/stdc++.h>
using namespace std;

int OddOcuurence(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto i : mp)
    {
        if (i.second % 2 != 0)
        {
            return i.first;
        }
    }
    return -1;
}

// Using bitwise operator
// Xor operator will give

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << OddOcuurence(arr, n);
    return 0;
}