// Given a string S, find length of the longest substring with all distinct characters.

// Example 1:

// Input:
// S = "geeksforgeeks"
// Output: 7
// Explanation: "eksforg" is the longest
// substring with all distinct characters.

#include <bits/stdc++.h>
using namespace std;

int LongestDistinctCharcters(string s)
{
    unordered_set<char> set;
    int i = 0, j = 0, n = s.size(), result = 0;
    while (j < n)
    {
        if (set.find(s[j]) != set.end())
        {
            set.erase(s[i++]);
        }
        else
        {
            set.insert(s[j++]);
            result = max(result, j - i);
        }
    }
    return result;
}