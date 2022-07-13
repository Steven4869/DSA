#include <iostream>
using namespace std;

int SubsetSum(int arr[], int sum, int n)
{
    // Base condition
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }
    // Choice Diagram
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int equalPartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    else if (sum % 2 == 0)
    {
        return SubsetSum(arr, sum / 2, n);
    }
    return 0;
}

int main()
{
    int arr[] = {1, 5, 11, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << equalPartition(arr, n);
}