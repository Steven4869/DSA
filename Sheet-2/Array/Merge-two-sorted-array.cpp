
// Given two sorted arrays, the task is to merge them in a sorted manner.
// Examples:

// Input: arr1[] = { 1, 3, 4, 5}, arr2[] = {2, 4, 6, 8}
// Output: arr3[] = {1, 2, 3, 4, 4, 5, 6, 8}

#include <bits/stdc++.h>
using namespace std;

void Merge(int arr1[], int arr2[], int n, int m)
{
    int i = n - 1;
    int j = m - 1;
    int k = m + n - 1;
    while (j >= 0 && i >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k--] = arr1[j--];
        }
        else
        {
            arr1[k--] = arr2[i--];
        }
    }
    while (i >= 0)
    {
        arr1[k--] = arr1[i--];
    }
    while (j >= 0)
    {
        arr1[k--] = arr1[j--];
    }
}
int arr1[] = {1, 4, 8, 10};
int arr2[] = {2, 3, 9};
int n = sizeof(arr1) / sizeof(arr1[0]);
int m = sizeof(arr2) / sizeof(arr2[0]);
Merge(arr1, arr2, n, m);
for (int i = 0; i < n; i++)
{
    cout << arr1[i] << " ";
}
return 0;