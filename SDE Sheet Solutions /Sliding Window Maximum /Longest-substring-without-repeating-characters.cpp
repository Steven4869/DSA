// Given a string s, find the length of the longest substring without repeating characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Approach
// 1.We'll go with sliding window concept as we have string, and substring we need to find
// 2.Here the k size is variable
// 3.Use hashmap for the value to get the frequency

#include <bits/stdc++.h>
using namespace std;

int LongestSubstring(string s, int n)
{
    if (s.length() == 0)
    {
        return 0;
    }
    unordered_map<char, int> mp;
    int i = 0, j = 0, result = INT_MIN;
    while (j < s.length())
    {
        mp[s[j]]++;
        if (mp.size() == j - i + 1)
        {
            result = max(result, j - i + 1);
        }
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                // Remove dupliactes
                mp[s[i]]--;
                // If the frequency becomes zero then delete it completly
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return result;
}