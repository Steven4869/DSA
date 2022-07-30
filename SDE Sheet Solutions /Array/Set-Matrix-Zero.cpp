// Set Matrix Zero
// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

// Approach
// 1. Run the loop to check for where the matrix is zero
// 2. Check for the first row and column to see if there zero exists or not, if exists make them true
// 3. Make the i and j respective to that row and column to be zero
// 4. Run the loop for the elements except for first row and first column and make them zero
// 5/ Now check for the firstcols and firstrows, if the firstrow is true make the col to be zero similar for firstcol

// Code

#include <bits/stdc++.h>
using namespace std;

// Return type is void

void SetMatrixZero(vector<vector<int>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    // Make two variable for first row and col
    bool firstRow = false;
    bool firstCol = false;
    // Running the loop for the first row and  col
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Check for the matrix value where it's zero
            if (arr[i][j] == 0)
            {
                if (i == 0)
                {
                    firstRow = true;
                }
                if (j == 0)
                {
                    firstCol = true;
                }
                // Make the row and col adjacent to it to be zero
                arr[0][j] = 0;
                arr[i][0] = 0;
            }
        }
    }
    // Run the loop for the other rows and cols
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (arr[i][0] == 0 || arr[0][j] == 0)
            {
                arr[i][j] = 0;
            }
        }
    }
    // Check for the first row, if it's true make the colum to be zero
    if (firstRow)
    {
        for (int i = 0; i < cols; i++)
        {
            arr[0][i] = 0;
        }
    }
    // Check for the first col, if it's true make the row to be zero
    if (firstCol)
    {
        for (int i = 0; i < rows; i++)
        {
            arr[i][0] = 0;
        }
    }
}

// Main function

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    SetMatrixZero(arr);
    cout << "Resultant Matrix is " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}