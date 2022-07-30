// This problem is also called as Dutch National Flag Problem
//  Given an array consisting of only 0s, 1s and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Approach 1
// Count the 0 1 2 then increment them in the array

#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
// Creating solve function
void solve(int arr[], int n)
{
    // Alloacating count variables
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count_0++;
        }
        else if (arr[i] == 1)
        {
            count_1++;
        }
        else
        {
            count_2++;
        }
    }

    // Apply an while loop for all the counts and increment the array
    int i = 0;
    while (count_0 > 0)
    {
        arr[i++] = 0;
        count_0--;
    }
    while (count_1 > 0)
    {
        arr[i++] = 1;
        count_1--;
    }
    while (count_2 > 0)
    {
        arr[i++] = 2;
        count_2--;
    }
    printArr(arr, n);
}
// TC:O(N + N) SC:O(1)

// Approach-2 - In one pass
// 1. Create three varaibles, low, mid, high
// 2. Traverse the array and if the element lies in low (0) then swap low with mid, increment mid and low value
// 3. If element is 1 then increment the mid value
// 4. If element is 2 then swap high and low values, decrement high value
// 5. Run the loop until mid <=high

void solve2(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
    printArr(arr, n);
}

// TC:O(N)-Single Traversal SC:O(1)
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve2(arr, n);
    return 0;
}