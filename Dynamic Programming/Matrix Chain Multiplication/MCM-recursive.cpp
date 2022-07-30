// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

#include <bits/stdc++.h>
using namespace std;
// Creating a function solve
int solve(int arr[], int i, int j)
{
    // Base Condition
    if (i >= j)
    {
        return 0;
    }
    int mn = INT_MAX;
    int k;
    for (k = i; k <= j - 1; k++)
    {
        // First function for i to k, then for k+1 to j then for the extra cost of combining
        int temp = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (temp < mn)
        {
            mn = temp;
        }
    }
    return mn;
}
//

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << solve(arr, 1, n - 1);
}