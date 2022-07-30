#include <bits/stdc++.h>
using namespace std;

static int t[1001][1001];

// Palindrome Function
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string s, int i, int j)
{
    if (t[i][j] != -1)
    {
        return t[i][j];
    }
    // Base Condition
    if (i >= j || isPalindrome(s, i, j))
    {
        return 0;
    }
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = 1 + solve(s, i, k) + solve(s, k + 1, j);
        if (temp < mn)
        {
            mn = temp;
        }
    }
    return t[i][j] = mn;
}
int main()
{
    memset(t, -1, sizeof(t));
    string s = "nitik";
    cout << "Palindromic Partitioning " << solve(s, 0, s.length() - 1);
    return 0;
}