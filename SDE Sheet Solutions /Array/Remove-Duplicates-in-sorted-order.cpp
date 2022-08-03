// Remove Duplicates in-place from Sorted Array
// Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

// If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

// Input: arr[1,1,2,2,2,3,3]

// Output: arr[1,2,3,_,_,_,_]

#include <bits/stdc++.h>
using namespace std;
int Duplicate(int arr[], int n)
{
    int i = 0;
    for (int j = i; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = Duplicate(arr, n);
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}