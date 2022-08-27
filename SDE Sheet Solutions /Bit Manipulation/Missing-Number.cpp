#include <bits/stdc++.h>
using namespace std;

int MissingNumber(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result ^= arr[i];
    }
    for (int i = 0; i <= n; i++)
    {
        result ^= i;
    }
    return result;
}

int main()
{
    int arr[] = {0, 1, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MissingNumber(arr, n);
}