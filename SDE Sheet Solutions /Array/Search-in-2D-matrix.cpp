// Search in a sorted 2D matrix
// Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

// Given matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row

// Approach
// 1. Search all the elements by going through two loops - TC:O(N^2) SC:O(1)
// 2. Since integeres are given in sorted order, we can apply binary search - TC:O(Log(N*M)) SC:O(1)

// Code
// 1. First check if the element to be found is greater than or equal to the ith row first element of the matrix ans smaller than last columm element
// 2. Apply binary search

#include <bits/stdc++.h>
using namespace std;

#define M 3
#define N 3

bool SearchMatrix(int arr[M][N], int target)
{
    int rows = M;
    int cols = N;

    for (int i = 0; i < rows; i++)
    {
        if (arr[i][0] <= target && arr[i][cols - 1] >= target)
        {
            int low = 0;
            int high = cols - 1;
            while (left <= right)
            {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target)
                {
                    return true;
                }
                else if (arr[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return false;
        }
    }
    return false;
}

int main()
{
    int arr[M][N] = {{1, 3, 5},
                     {10, 11, 16},
                     {23, 30, 34}};
    int target = 3;
    if (SearchMatrix(arr, target))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
}