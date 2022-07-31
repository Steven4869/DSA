// Merge two Sorted Arrays Without Extra Space
// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Approach
// 1. Make a new array with arr3 and insert elements then sort them - TC:O(NlogN + N) SC:O(N+M)-we are taking new space
// 2. Change the exisiting array by comaring the elementd TC:O(N+M) SC:O(1)
// Second approach is better, for that we'll use reverse sorting
// 1. Take three variables, i, j, k and allot them values of n-1, m-1, m+n-1 respectivley
// 2 Run thw hile loop for i and j until they become 0
// 3. if the ith element at arr is greater than jthe element then make kth element equal to i
// 4. otherise make kth element eqaul to jth element of other arry
// 5 Run the while loop for the leftover elemennts

#include <bits/stdc++.h>
using namespace std;

void Merge(int arr1[], int arr2[], int n, int m)
{
    int i = n - 1;
    int j = m - 1;
    int k = m + n - 1;
    // Run the loop
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k--] = arr1[i--];
        }
        else
        {
            arr1[k--] = arr2[j--];
        }
    }
    // Run loop for the remaining elements because one of them will end early
    while (i >= 0)
    {
        arr1[k--] = arr1[i--];
    }
    while (j >= 0)
    {
        arr1[k--] = arr2[j--];
    }
}

int main()
{
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
}