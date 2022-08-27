// uppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.

// Approach
// 1. Check if the element is rotated or not, by checking if the first element is less than last element
// 2. If not then the array has been rotated
// 3. Find the mid element and check with the last element
// 4. If the mid element is greater then its rotated in left array otherwise the right array
// 5. Return the start point of the array
// 6. Note in Binary Search : we do start<=end when we need to return the element in loop
// 7. We use start<end when we traverse the loop and have to return the result after traversal of the loop

#include <bits/stdc++.h>
using namespace std;
int MinSortedArray(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        if (arr[low] < arr[high])
        {
            return arr[low];
        }
        int mid = low + (high - low) / 2;
        if (arr[mid] >= arr[low])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return arr[low];
}

int main()
{
    int arr[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MinSortedArray(arr, n);
    return 0;
}