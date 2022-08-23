// Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

// Input: [[1,2,3],[4,5,6],[7,8,9]]

// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Approach
// 1. Find the Transpose of the matrix by swapping i and j values
// 2. Then reverse the indivual row of matrix (since we are going for 90)

// Code

#include <bits/stdc++.h>
#define N 4
using namespace std;

void printArr(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void solve(int arr[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        reverse(arr[i], arr[i] + N);
    }
}

// TC:O(N^2) SC:O(1)

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{
    int arr[N][N] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    solve(arr);
    printArr(arr);
    return 0;
}