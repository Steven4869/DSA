// Find the only rpeating element in array where element repeats twice

// XOR operator-properties
// 1. n^n=0
// 2. n^0=0

#include <bits/stdc++.h>
using namespace std;
int Repeating(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = result ^ arr[i];
    }
    return result;
}
// TC:O(N)  SC:O(1)
int main()
{
    int arr[] = {5, 4, 1, 4, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << Repeating(arr, n);
}