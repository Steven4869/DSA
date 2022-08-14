// Input: s = "III"
// Output: 3
// Explanation: III = 3.

#include <bits/stdc++.h>
using namespace std;

int RomanToInteger(string s)
{
    unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    int result = mp[s.back()];
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            result = result - mp[s[i]];
        }
        else
        {
            result = result + mp[s[i]];
        }
    }
    return result;
}

int main()
{
    string s = "MMXIXI";
    cout << RomanToInteger(s);
}