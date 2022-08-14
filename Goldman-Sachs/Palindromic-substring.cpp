// Palindromic Substrings

// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Approach
// Recursive Approach
// Take two nested loops, one for the traversal for string, other for the traversal of ith index to the string
// Take up a count varaible, incremenet it with help of palindrome function
// Return 1 if the ith index is greater than or equal to j
// If the string indixes are equal, call the recursive function by incrementing i and decrementing j
// Otherwise return 0

#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
int helper(string s, int i, int j)
{
    if (i >= j)
    {
        return 1;
    }
    return s[i] == s[j] ? helper(s, i + 1, j - 1) : 0;
}
int MemHelper(string s, int i, int j)
{
    if (i >= j)
    {
        return 1;
    }
    if (t[i][j] != -1)
    {
        return t[i][j];
    }
    if (s[i] != s[j])
    {
        return 0;
    }
    return t[i][j] = MemHelper(s, i + 1, j - 1);
}
int CountSubstring(string s)
{
    int count = 0;
    // Intialse two loops
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            count = count + MemHelper(s, i, j);
        }
    }
    return count;
}

// TC:O(N^3) SC:O(1)

// We can reduce the optimisation by using Dynamic Programming
// Memoisation
// TC:O(N^2) SC:O(N^2)
int main()
{
    memset(t, -1, sizeof(t));
    string s = "abc";
    cout << CountSubstring(s);
}