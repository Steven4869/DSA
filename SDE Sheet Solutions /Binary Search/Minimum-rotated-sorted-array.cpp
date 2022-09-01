#include <bits/stdc++.h>
using namespace std;

int MinRotatedSortedArray(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[high])
        {
            high = mid;
        }
        else if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else
        {
            return arr[mid];
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MinRotatedSortedArray(arr, n);
}