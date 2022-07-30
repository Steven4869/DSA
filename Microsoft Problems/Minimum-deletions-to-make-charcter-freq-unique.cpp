#include <bits/stdc++.h>
using namespace std;
int MinDeletions(string s)
{
    unordered_map<char, int> map;
    for (int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
    }
    int count = 0;
    set<int> result;
    for (auto [i, j] : map)
    {
        while (result.find(j) != result.end())
        {
            count++;
            j--;
        }
        if (j > 0)
        {
            result.insert(j);
        }
    }
    return count;
}