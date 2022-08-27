#include <bits/stdc++.h>
using namespace std;

int minSubarrayLength(int arr[], int n, int k)
{
    int i = 0, j = 0, sum = 0;
    int minimum = INT_MAX;
    while (j < n)
    {
        sum = sum + arr[j];
        while (sum >= k)
        {
            minimum = min(minimum, j - i + 1);
            sum = sum - arr[i];
            i++;
        }
        j++;
    }
    return minimum;
}
int main()
{
    int arr[] = {2, 3, 1, 2, 4, 3};
    int k = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minSubarrayLength(arr, n, k);
    return 0;
}