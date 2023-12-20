// Two Sum : Check if a pair with given sum exists in Array
// Problem Statement: Given an array of integers nums[] and an integer target, return indices of the two numbers such that their sum is equal to the target.

// Input: nums = [2,7,11,15], target = 9

// Output: [0,1]

// Approach
// 1. Use two for loops and get the required sum
// 2. use map and do it single traversal

// Code

#include <bits/stdc++.h>
using namespace std;

int TwoSum(int arr[], int target, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            }
        }
    }
    return 0;
}
// TC:O(N^2) SC:O(1)

// Better way

void Pairs(int arr[], int target, int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int temp = target - arr[i];

        if (s.find(temp) != s.end)
        {
            cout << "(" << arr[i] << "," << temp << ")" << endl;
        }
        s.insert(arr[i]);
    }
}
void TwoSumMap(int arr[], int n, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find([target - arr[i]]) != mp.end())
        {
            return {mp[target - arr[i]], i};
        }
        else
        {
            mp[arr[i]] = i;
        }
    }
    return {-1, -1};
}
int main()
{
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << TwoSum(arr, target, n);
    Pairs(arr, target, n);
    return 0;
}