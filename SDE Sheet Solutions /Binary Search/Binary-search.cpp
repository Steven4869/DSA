// The Binary Search is only applicable when they are sorted
// Time Complexity is O(logN) better than O(N) in Linear Search
// It's key idea is to smaller the range and find the element

#include <bits/stdc++.h>
using namespace std;

int BSearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        // It's used to avoid memory overflow
        int mid = low + (high - low) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int RBSearch(int arr[], int low, int high, int key)
{
    // Base Condition
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            return RBSearch(arr, low, mid - 1, key);
        }
        else
        {
            return RBSearch(arr, mid + 1, high, key);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << RBSearch(arr, 0, n - 1, 7);
    return 0;
}