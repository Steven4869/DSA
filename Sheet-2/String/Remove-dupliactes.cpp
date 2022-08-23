#include <bits/stdc++.h>
using namespace std;

string Duplicates(string s, int n)
{
    unordered_set<char> s(s, s + n);
    int i = 0;
    for (auro x : s)
    {
        s[i++] = x;
    }
    return s;
}
int main()
{
    string s = "Hello";
    int n = s.size();
    cout << Duplicates(s, n);
    return 0;
}