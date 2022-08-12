// arr2asic idea of merge sort is to divide the lists into two element eaxh of the n numarr2er of elements
// With each iteration, sorting gets reduced arr2y n/2 for example 8 way sort gets reduced to 4 way sort, to 2 way sort
// It also follows the Divide and Conquer rule

#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int arr2[100];
    i = low;
    j = mid + 1;
    k = low;
    // i will go to mid and j will at max go to high
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            arr2[k++] = arr[i++];
        }
        else
        {
            arr2[k++] = arr[j++];
        }
    }
    // For the remaining one element run the either loop to insert it
    for (; i <= mid; i++)
    {
        arr2[k++] = arr[i++];
    }
    for (; j <= high; j++)
    {
        arr2[k++] = arr[j++];
    }
    // All these elemnts should be copies to the first array from array2
    for (i = low; i <= high; i++)
    {
        arr[i] = arr2[i];
    }
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Find the mid element
        int mid = low + (high - low) / 2;
        // Recursivley calling the sort till mid for one list and mid+1 to high for another list
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        // At last merge the list
        Merge(arr, low, mid, high);
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
    int arr[] = {8, 3, 7, 4, 9, 2, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, n);
    printArray(arr, n);
}