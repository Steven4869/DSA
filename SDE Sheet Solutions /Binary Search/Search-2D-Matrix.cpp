// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Approach
//  1. Since matrix are row sorted we can apply binary search row wise

#include <bits/stdc++.h>
using namespace std;

bool Search2DMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] <= target && matrix[i][cols - 1] >= target)
        {
            int left = 0;
            int right = cols - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] == target)
                {
                    return true;
                }
                else if (matrix[i][mid] > target)
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
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int target = 9;
    bool result = Search2DMatrix(matrix, target);
    if (result == 1)
    {
        cout << "Element exists ";
    }
    else
    {
        cout << "Element doesn't exists ";
    }
}