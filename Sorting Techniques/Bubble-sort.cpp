// It's based on the idea that if the element to be compared is smaller then they will swap their positions

// 8,5,7,3,2 => 5,8,7,3,2 => 5,7,8,3,2 => 5,7,3,8,2 => 5,7,3,2,8  (Now 8 is sorted) => First-pass
// 5,7,3,2,8 => 5,7,3,2,8 => 5,3,7,2,8 => 5,3,2,7,8 (Now 7 is sorted) => Second pass
// 5,3,2,7,8 => 3,5,2,7,8 => 3,2,5,7,8 (Now 5 is sorted) => Third pass
// 3,2,5,7,8 => 2,3,5,7,8 (Everything is sorted) => Fourth pass

// N=5 => 4 pass  N => (N-1) pass
// Time complexity of any sorting algorithms is given by the number of comparison
// No. of comparison => 1+2+3+4+... => N(N-1)/2 => O(N^2)
// TC:O(N^2)

// Approach
// 1. Make two nested loops, one for comparison and other for pass
// 2. Passes are from n-1, comparions reduce with every other ith pass

// Code

#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
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
    int arr[] = {8, 5, 7, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr, n);
    printArray(arr, n);
}

// An algorithm that changes its behaviour based on information available ar the time it ran is called adaptivity
// Bublle sort is adaptive
// Bubble sort is stable as it doesn't swap the duplciate values