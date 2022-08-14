// Print a given matrix in spiral form
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Approach
// 1. Since we need to traverse the matrix and print it simantanousely, we need to have 4 variables denoting the left, right, top and bottom. Another one for the direction
// 2. First traverse the loop until top becomes less than bottom and similar for left and right
// 3. Traverse the loop from left to right and print the top element, push back into the vector
// 4. Keep doing it for the remaining directions and return the vector

// Code

#include <bits/stdc++.h>
using namespace std;

vector<int> SpiralOrder(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
    int direction = 1;
    vector<int> ans;

    // Condition to run the loop
    while (left <= right && top <= bottom)
    {
        if (direction == 1)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            direction = 2;
            top++;
        }
        else if (direction == 2)
        {
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            direction = 3;
            right--;
        }
        else if (direction == 3)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            direction = 4;
            bottom--;
        }
        else if (direction == 4)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            direction = 1;
            left++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    SpiralOrder(matrix);
}