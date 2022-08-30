#include <bits/stdc++.h>
using namespace std;
vector<string> result;
vector<string> generateParanthesis(int n)
{
    solve("", n, n);
    return result;
}
void solve(string s, int open, int close)
{
    if (open == 0 && close == 0)
    {
        result.push_back(s);
        return;
    }
    if (open > 0)
    {
        solve(s + "(", open - 1, close);
    }
    if (open < close)
    {
        solve(s + ")", open, close - 1);
    }
}