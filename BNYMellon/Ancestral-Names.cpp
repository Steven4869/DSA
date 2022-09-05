#include <bits/stdc++.h>
using namespace std;

int RomanaToInt(string s)
{
    int n = s.size();
    int value = 0;
    unordered_map<char, int> mp{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = 0; i < n - 1; i++)
    {
        if (mp[s[i]] >= mp[s[i + 1]])
        {
            value = value + mp[s[i]];
        }
        else
        {
            value = value - mp[s[i]];
        }
    }
    value = value + mp[s[n - 1]];
    return value;
}

void SortRomans()
{
    vector<string> names = {
        "Steven XL", "Steven XVI", "Mary XV", "David IX"};
    sort(names.begin(), names.end(), [](string &a, string &b)
         {
        // find the breakpoint i.e.(' ') for both strings
		auto breakpoint_a = a.find(' '), breakpoint_b = b.find(' ');
		string token1a = a.substr(0, breakpoint_a), token1b = b.substr(0, breakpoint_b);
		string token2a = a.substr(breakpoint_a + 1), token2b = b.substr(breakpoint_b + 1);
        // If token1 i.e. the name is same then sort by roman value else by name
		if(token1a == token1b)
			return romanToInt(token2b) >= romanToInt(token2a);
		return token1b > token1a; });
    return names;
}