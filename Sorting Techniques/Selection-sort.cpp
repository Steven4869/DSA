// it's based on the idea that sorting takes place by finding the minimum element from the unsorted array and placing it at the beginning
// With each iteration of sselection sort, the minimum element from the unsorted array is picked and moved to the sorted subarray

// Approach
// Intialsie a minimum value with that of i
// Traverse the array to find the minimum element
// While traversing if any element is smaller than the min index then swap the values
// Then increment the min index to next element

#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int n)
{
    int i, j, min_index;
    // For passes
    for (i = 0; i < n; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                // If the element is smaller then bring min_index upon j
                min_index = j;
            }
        }
        // Swappiong the found element with the first element
        swap(arr[min_index], arr[i]);
        // if (min_index != i)
        // {
        //     swap(arr[min_index], arr[i]);
        // }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {8, 5, 7, 3, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, n);
    printArray(arr, n);
}

// TC:O(N^2) SC:O(1)
// Selection sort is not adaptive as it'll always have O(N^2) time and we can't say whether the list is sorted or not
// Selection sort is not stable