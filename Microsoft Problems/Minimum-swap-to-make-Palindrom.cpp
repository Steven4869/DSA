#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int MinSwap(string s)
{
    int odd = 0, left = 0, right = s.size() - 1, result = 0;
    // Base Condition-checking if the odd elements are more than one or not
    unordered_map<char, int> map;
    for (int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
    }
    for (auto i : map)
    {
        if (i.second % 2 == 1)
        {
            odd++;
        }
    }
    if (odd > 1)
    {
        return -1;
    }

    while (left < right)
    {
        int l = left, r = right;
        while (s[l] != s[r])
        {
            r--;
        }
        if (l == r)
        {
            swap(s[r], s[l + r]);
            result++;
            continue;
        }
        else
        {
            while (r < right)
            {
                swap(s[r], s[l + r]);
                result++;
                r++;
            }
        }
        left++;
        right--;
    }
    return result;
}

int main()
{
    string s = "aabcc";
    cout << MinSwap(s);
    return 0;
}