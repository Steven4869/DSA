// Find position of an element in a sorted array of infinite numbers

// Suppose you have a sorted array of infinite numbers, how would you search an element in the array?

// Approach
// 1. Since the array is soted we'll go with Binary Search, but we don't the size of array since it's infinite
// 2. For that we have to take bounds to perform binary search, lowe bound, l will be the first index and higher bound, h will be second index
// 3. Take value to be first element of arr, run the loop until the value becomes greater than key
// 4. Keep on changing the bounds, l to h and h to 2*h, and value to be the lower bound value of array
// 5. Perform Binary Search in it

#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return BinarySearch(arr, mid + 1, high, key);
        }
        else
        {
            return BinarySearch(arr, low, mid - 1, key);
        }
    }
    return -1;
}

int Find(int arr[], int key)
{
    int low = 0;
    int high = 1;
    int value = arr[0];

    while (value < key)
    {
        low = high;
        high = 2 * high;
        value = arr[high];
    }
    return BinarySearch(arr, low, high, key);
}

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int key = 100;
    int result = Find(arr, key);
    if (result == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at index " << result;
    }
    return 0;
}