#include <iostream>
#include <vector>
using namespace std;

vector<int> SubsetSum(int arr[], int range, int n)
{
    int t[n + 1][range + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
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
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < range + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
            }
            if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    vector<int> result;
    for (int i = n; i < n + 1; i++)
    {
        for (int j = 0; j <= range / 2; j++)
        {
            if (t[i][j] == 1)
            {
                result.push_back(j);
            }
        }
    }
    return result;
}

int minDifference(int arr[], int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range = range + arr[i];
    }
    vector<int> v;
    v = SubsetSum(arr, range, n);
    int mn = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        mn = min(mn, range - 2 * v[i]);
    }
    return mn;
}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is "
         << minDifference(arr, n);
    return 0;
}