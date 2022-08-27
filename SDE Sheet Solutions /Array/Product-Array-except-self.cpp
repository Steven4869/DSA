// Product of Array Except Self

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Approach
// 1. Create two variables left and right that will store the product of the left and right side
// 2. Make up a new array result and store the final product there
#include <bits/stdc++.h>
using namespace std;

vector<int> ProductArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);
    vector<int> left(n);
    vector<int> right(n);
    left[0] = 1;
    right[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
    for (int j = n - 2; j >= 0; j--)
    {
        right[j] = right[j + 1] * nums[j + 1];
    }
    for (int i = 0; i < n; i++)
    {
        result[i] = left[i] * right[i];
    }
    return result;
}

int main()
{
    vector<int> nums{1, 2, 3, 4};
    vector<int> res = ProductArray(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}