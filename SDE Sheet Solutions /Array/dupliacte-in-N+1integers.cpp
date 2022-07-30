// Find the duplicate in an array of N+1 integers
// Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.

// Input: arr=[1,3,4,2,2]

// Output: 2

// Approach
// 1. Sorting - O(NlogN) and O(1) space
// 2. Mapping - O(N) time and O(N) space
// 3. Tortoise and hare method - O(N) time and O(1) space

#include <bits/stdc++.h>
using namespace std;
int Duplicate(int arr[])
{
    int slow = arr[0];
    int fast = arr[0];

    do
    {
        slow = arr[slow];      // move slow by 1
        fast = arr[arr[fast]]; // move fast by 2
    } while (slow != fast);

    // Finding the entrance point
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow; // point at which they meet
}

int main()
{
    int arr[] = {1, 3, 4, 2, 2};
    cout << Duplicate(arr);
    return 0;
}