// Insertion sort places an unsorted element at its suitable place in each direction

// It checks from the last element whether the element is greater or not
// if it;s greater then move them one position back
// Do it until we reach the smaller comparison, from there on insert the element in that empty space

// 8,5,7,3,2

// 8 => Insert 5 => 5,8 => Insert 7 => 5,7,8 => Insert 3 => 3,5,7,8 => Insert 2 => 2,3,5,7,8

// Approach
// 1. Create a loop for the n element starting form 1, then intialise j as i-1 and x as i th value of array
// 2. Run another loop to check until the arr[j] is greater than the x value then assign with j+1 th value

// Code

#include <bits/stdc++.h>
using namespace std;
void InsertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        int x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// TC:O(N^2)
int main()
{
    int arr[] = {8, 5, 7, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, n);
    PrintArray(arr, n);
}

// Insertion sort is adaptuve
// Insertion sort is stable
