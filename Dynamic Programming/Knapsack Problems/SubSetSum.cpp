// arr[]={2,3,5,7,8,10}
// sum=11
// Output:true Subset{8,3}

#include <iostream>
using namespace std;

int SubsetSum(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1];
    // Base condition
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

int main()
{
    int arr[] = {2, 3, 5, 8, 10};
    int sum = 11;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << SubsetSum(arr, sum, n);
}