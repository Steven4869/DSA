// Rat in a Maze

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

// Note: In a path, no cell can be visited more than one time.

// Print the answer in lexicographical(sorted) order

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//         {1, 1, 0, 1},
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}}

// Output: DDRDRR DRDDRR

// Approach
// 1. Backtracking is the way to go
// 2. Our job is to make the rat go from inital starting point to the ending point
// 3. Rat can go through only the 1's, 0's are blocked for rat
// 4. There are four directions with which the rat can move: Up, Left, Right, Down
// 5. Declare a 2D array known as visited where we will keep track of rat's movements
// 6. IF a cell is in path, then mark it in the visited array
// 7. Make a check for the out of bounds conditions
// 8. Once we reach the ending point we need to come back and keep on unmarking the visited array, and try for other possible directions
// 8. Inistalise an empty string and store the directions in it, keep in mind that we need to print it in the lexirographical order

// (i->position(x-axis), j->position(y-axis, arr->matrix array, ans->storing string where result will be there, Move->to store the directions , visited->array to mark and unmak the visits)
void solve(int i, int j, vector<vector<int>> &arr, int n, vector<string> &ans, string move, vector<vector<int>> &visited)
{
    // Base Condition - If we reach to the destination then push the result
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }

    // Downward Movement
    // Check if the i+1th position is less than n and if it's already visited and if it's allowed to move that side
    if (i + 1 < n && (!visited[i + 1][j]) && arr[i + 1][j] == 1)
    {
        visited[i][j] = 1;
        solve(i + 1, j, arr, n, ans, move + 'D', visited);
        visited[i][j] = 0;
    }
    // similarly for other movements like Up, left and right
    // Upward Movement
    if (i - 1 >= 0 && (!visited[i - 1][j]) && arr[i - 1][j] == 1)
    {
        visited[i][j] = 1;
        solve(i - 1, j, arr, n, ans, move + 'U', visited);
        visited[i][j] = 0;
    }
    // Right Movement
    if (j + 1 < n && (!visited[i][j + 1]) && arr[i][j + 1] == 1)
    {
        visited[i][j] = 1;
        solve(i, j + 1, arr, n, ans, move + 'R', visited);
        visited[i][j] = 0;
    }
    // Left Movement
    if (j - 1 >= 0 && (!visited[i][j - 1]) && arr[i][j - 1] == 1)
    {
        visited[i][j] = 1;
        solve(i, j - 1, arr, n, ans, move + 'L', visited);
        visited[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    if (m[0][0] == 1)
    {
        solve(0, 0, m, n, ans, "", visited);
    }
    return ans;
}