#include <bits/stdc++.h>
using namespace std;

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
    // Base condition
    if (i >= j)
    {
        return 0;
    }
    if (isPalindrome(s, i, j))
    {
        return 0;
    }

    // Finding Minimum partitions for the palindrome
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = 1 + solve(s, i, k) + solve(s, k + 1, j);
        if (temp < mn)
        {
            mn = temp;
        }
    }
    return mn;
}

int main()
{
    string s = "shivam";
    cout << "Palindrome Partition " << solve(s, 0, s.length() - 1);
}