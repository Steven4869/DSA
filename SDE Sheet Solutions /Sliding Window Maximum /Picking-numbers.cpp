#include <bits/stdc++.h>
using namespace std;

int PickingNumbers(int arr[], int n)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) <= 1)
            {
                len = max(len, j - i);
            }
        }
    }
    return len;
}

int main()
{
    int arr[] = {4, 6, 5, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << PickingNumbers(arr, n);
}