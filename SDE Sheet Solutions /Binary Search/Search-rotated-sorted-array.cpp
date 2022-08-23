// Search an element in a sorted and rotated Array

// Given a sorted and rotated array arr[] of size N and a key, the task is to find the key in the array.

// Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key = 3
// Output : Found at index 8

// Approach

// 1. We need to find the pivot elemetn at which the array is divided
// 2. We'll apply Binary search on the array, if the rotation has happened at left half then low will be grater than mid
// 3. Otherwise the mid will be greater than right side and left side will be sorted
// 4. After the pivot is found, divide the array into two parts, then apply binary search in them to find the key element

// Consider arr[] = {3, 4, 5, 1, 2}, key = 1

// Pivot finding:

// low = 0, high = 4:
//         =>  mid = 2
//         =>  arr[mid] = 5, arr[mid + 1] = 1
//         => arr[mid] > arr[mid +1],
//         => Therefore the pivot = mid = 2

// Array is divided into two parts {3, 4, 5}, {1, 2}
// Now  according to the conditions and the key, we need to find in the part {1, 2}

// Key Finding:

// We will apply Binary search on {1, 2}.
// low = 3 , high = 4.
//             =>  mid = 3
//             =>  arr[mid] = 1 , key = 1, hence arr[mid] = key matches.
//             =>  The required index = mid = 3

// So the element is  found at index 3.

#include <bits/stdc++.h>
using namespace std;

// Binary Search Function

int BinarySearch(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            return BinarySearch(arr, mid + 1, high, key);
        }
        return BinarySearch(arr, low, mid - 1, key);
    }
    return -1;
}

int findPivot(int arr[], int low, int high)
{
    // Base Case
    if (low > high)
    {
        return -1;
    }
    if (low == high)
    {
        return low;
    }

    int mid = low + (high - low) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
    {
        return mid;
    }
    if (mid > low && arr[mid] < arr[mid - 1])
    {
        return (mid - 1);
    }
    if (arr[low] >= arr[mid])
    {
        return findPivot(arr, low, mid - 1);
    }
    return findPivot(arr, mid + 1, high);
}

// Search element in pivot

int PivotBinarySearch(int arr[], int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);

    // If the array is not rotated then apply simple binary search
    if (pivot == -1)
    {
        return BinarySearch(arr, 0, n - 1, key);
    }

    // IF we find the pivot then compare to see the subarrays

    if (arr[pivot] == key)
    {
        return pivot;
    }
    if (arr[0] <= key)
    {
        return BinarySearch(arr, 0, pivot - 1, key);
    }
    return BinarySearch(arr, pivot + 1, n - 1, key);
}

int Search(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] >= arr[low])
        {
            if (key >= arr[low] && key < arr[mid])
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
            if (key > nums[mid] && key <= arr[high])
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
}
int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    cout << PivotBinarySearch(arr, n, key);
    return 0;
}