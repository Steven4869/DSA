// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Approach

// 1. Check for where the islands are located, if the horixontal and vertical to form a island, so we need to check all four sides
// 2. If we succeed then increment the result value

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j, int rows, int cols)
{
    // Base condition
    //  If element doesn't exits then return none
    if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] != '1')
    {
        return;
    }
    grid[i][j] = '2'; // Visited island
    dfs(grid, i + 1, j, rows, cols);
    dfs(grid, i - 1, j, rows, cols);
    dfs(grid, i, j + 1, rows, cols);
    dfs(grid, i, j - 1, rows, cols);
}
int NumOfIslands(vector<vector<char>> &grid)
{
    int row = grid.size();
    int cols = grid[0].size();
    int total = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1')
            {
                // Perform dfs
                dfs(grid, i, j, rows, cols);
                total++;
            }
        }
    }
    return total;
}