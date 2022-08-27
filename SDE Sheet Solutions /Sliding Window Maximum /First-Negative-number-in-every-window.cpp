// Given an array of integers a, and a positive integer k, find the first negative integer for each and every window (contiguous subarray) of size k. If a window does not contain a negative integer, then print 0 for that window.

// Example 1

// Input: a[] = {-5, 1, 2, -6, 9}, k = 2
// Output : -5 0 -6 -6

// Explanation: First negative integer in every window of size 2
// {-5, 1} = -5
// {1, 2} = 0 (does not contain a negative integer)
// {2, -6} = -6
// {-6, 9} = -6

// Brute Force Approach
// 1. Traverse the array till n-k
// 2. Make up a variable to store the negative elements
// 3. Traverse the array till i+k
// 4. Now push back the elements in to the vector

#include <bits/stdc++.h>
using namespace std;

vector<int> FirstNegativeNumber(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> result;
    for (int i = 0; i <= n - k; i++)
    {
        int NegativeNum = 0;
        for (int j = i; j < i + k; j++)
        {
            if (arr[j] < 0)
            {
                NegativeNum = arr[j];
                break;
            }
        }
        result.push_back(NegativeNum);
    }
    return result;
}
// TC : O(N^2)
//  Better way to do it is by approaching sliding window concept
//  Since we are reusing the same element we need to have better approach

vector<int> FirstNegativeNumberII(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> result;
    vector<int> temp;
    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] < 0)
        {
            temp.push_back(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (temp.size() == 0)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(temp.front());
                if (arr[i] < 0)
                {
                    temp.erase(temp.begin());
                }
            }
            i++;
            j++;
        }
    }
    return result;
}

int main()
{
    vector<int> arr{-5, 1, 2, -6, 9};
    int k = 2;
    vector<int> ans = FirstNegativeNumber(arr, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}