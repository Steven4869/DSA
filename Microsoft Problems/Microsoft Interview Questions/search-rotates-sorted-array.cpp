#include <bits/stdc++.h>
using namespace std;

int SearchRotated(int arr[], int target, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] >= arr[low])
        {
            if (arr[low] <= target && arr[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] < target && arr[high] >= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << SearchRotated(arr, target, n);
    return 0;
}