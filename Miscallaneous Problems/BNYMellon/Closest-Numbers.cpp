// Given an array of distinct integers, determine the minimum absolute difference between any two integers
// arr[]={6,2,4,10}
// OP: {2,4}, {4,6}

#include <bits/stdc++.h>
using namespace std;

void PrintMinDifference(int arr[], int n)
{
    sort(arr, arr + n);
    int minDiff = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
    {
        minDiff = min(minDiff, arr[i] - arr[i - 1]);
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] == minDiff)
        {
            cout << "(" << arr[i - 1] << "," << arr[i] << ")" << endl;
        }
    }
}

int main()
{
    int arr[] = {6, 2, 4, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    PrintMinDifference(arr, n);
}