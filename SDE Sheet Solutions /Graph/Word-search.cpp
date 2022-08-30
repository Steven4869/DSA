// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<char>> &board, string word, int i, int j, int n)
{
    // Check if all the alphabets in the word is checked
    if (n == word.size())
    {
        return true;
    }
    // Check if any of them are out of bounds
    if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n])
    {
        return false;
    }
    // Mark as visited
    board[i][j] = '0';
    bool status = DFS(board, word, i + 1, j, n + 1) ||
                  DFS(board, word, i, j + 1, n + 1) ||
                  DFS(board, word, i - 1, j, n + 1) ||
                  DFS(board, word, i, j - 1, n + 1);
    board[i][j] = word[n];
    return status;
}
bool exists(vector<vector<char>> &board, string word)
{
    if (word == "")
    {
        return false;
    }
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == word[0] && DFS(board, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}