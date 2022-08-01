// Grid Unique Paths | Count paths from left-top to the right bottom of a matrix
// Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.

// Input Format: m = 2, n= 2
// Output: 2

//  0 0  start
//  0 0  end

// the person can move only right and down, so he can go to right and down or down then right making two ways possibe;

// Approach
// We need to find total number of ways to reach bottom, this can be done with recurisve approach
//  We'll draw the recursive tree for the each case and come to conclusion
// Code

#include <bits/stdc++.h>
using namespace std;

int CountPath(int i, int j, int m, int n)
{
    if (i == (m - 1) && j == (n - 1))
    {
        return 1;
    }
    // Base Condition
    if (i >= m || j >= n)
    {
        return 0;
    }
    else
    {
        // Left Path + Right Path
        return CountPath(i + 1, j, m, n) + CountPath(i, j + 1, m, n);
    }
    return -1;
}

int UniquePath(int m, int n)
{
    return CountPath(0, 0, m, n);
}

// TC:O(2^N) SC:O(2^N)
// Since we are dealing with choices(right and down), we can use the Dynamic Programming

static int t[1001][1001];
int DCountPath(int i, int j, int m, int n)
{
    if (t[i][j] != -1)
    {
        return t[i][j];
    }
    if (i == (m - 1) && j == (n - 1))
    {
        return 1;
    }
    if (i >= m || j >= n)
    {
        return 0;
    }
    else
    {
        return t[i][j] = DCountPath(i + 1, j, m, n) + DCountPath(i, j + 1, m, n);
    }
    return -1;
}

int DUniquePath(int m, int n)
{
    return DCountPath(0, 0, m, n);
}
int main()
{
    memset(t, -1, sizeof(t));
    int m = 2;
    int n = 2;
    cout << "Total unique paths possible are: " << DUniquePath(m, n);
}