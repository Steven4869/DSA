// N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle
// Problem Statement: The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen’s placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.

// Input: n = 4

// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

// Approach
// 1. Make up a recursive Tree
// 2. We'll try to fill the Queen by column wise approach and will get n cases initially
// 3. Now check if it's possibel for them to be insrted in that position
// 4. If possible then continue on doing so, if not then go back and remove the previous queen;s position
// 5. Once it reaches to nth position that means we have got the answer and then push it into it.

// Checking for the permissible location for the Queen

bool isSafe(int row, int col, vector<string> &board, int n)
{
    // Queen can now move in three directions - Left Upper Diagonal, Left, Left Lower Diagonal
    int duprow = row;
    int dupcol = col;

    // For the upper left diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    // For the left column
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    // For the lower left diagonal
    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    // Base Condition
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    // For each row push the Q if it's available otherwise don't do it
    for (int row = 0; row < n; row++)
    {
        // To check if it's permissible to insert Queen
        if (isSafe(row, col, board, n))
        {
            // Basic Backtracking Algorithm
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = ','
        }
    }
}

vector<vector<string>> NQueens(int n)
{
    // Create a answer variable
    vector<vector<string>> ans;
    // Create a board string filled with string of size n
    vector<string> board(n);
    string s(n, ',');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    // Creating a recursive function
    solve(0, board, ans, n);
    return ans;
}