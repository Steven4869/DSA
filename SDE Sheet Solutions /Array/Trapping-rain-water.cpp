// Trapping Rainwater
// Problem Statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.

// Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]

// Output: 6

// Approach
// 1. Traverse the array and find the max value of left and right side(incremental of one more i to the left)
// 2. height of trapped water will be just min of left, and right - the element at that position
// 3. Print the result

#include <bits/stdc++.h>
using namespace std;
int MaxTrappedWater(int arr[], int n)
{
    // Creating result variable to store the answer
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
        {
            left = max(left, arr[j]);
        }
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            right = max(right, arr[j]);
        }
        result = result + min(left, right) - arr[i];
    }
    return result;
}
// TC:O(N^2) SC:O(1)
// How to optimise it? We can use space in it
// Approach
// 1. Create a left array to store the height from left tower
// 2. Create a right array to store the height from right tower
// 3. Make left of 0 to be first element of array
// 4. Make right of 0 to be last element of array
// 5. For water trapping, take min of left, right then subtract the tower height

int DMaxTrappedWater(int arr[], int n)
{
    // Creating a left and right array
    int *left = new int[n];
    int *right = new int[n];
    left[0] = arr[0];
    right[0] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = result + (min(left[i], right[i]) - arr[i]);
    }
    return result;
}

int main()
{
    int arr[] = {4, 2, 0, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << DMaxTrappedWater(arr, n);
}