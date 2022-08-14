//  Longest Substring Without Repeating Characters
//  Given a string s, find the length of the longest substring without repeating characters.

//  Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Approach
// We'll be using set, along with sliding window for this question
// If we find the element then erase it otherwise insert the element

#include <bits/stdc++.h>
using namespace std;

int MaxLengthSubstring(string s)
{
    unordered_set<char> set;
    int i = 0, j = 0, n = s.size(), ans = 0;

    // Run the loop until the last element of string
    while (j < n)
    {
        // If the string exits then erase it
        if (set.find(s[j]) != set.end())
        {
            set.erase(s[i++]);
        }
        else
        {
            set.insert(s[j++]);
            ans = max(ans, j - i);
        }
    }
    return ans;
}

int main()
{
    string s = "abcabcbb";
    cout << MaxLengthSubstring(s);
}