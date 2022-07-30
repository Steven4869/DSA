#include <bits/stdc++.h>
using namespace std;

string RemoveDuplicates(string s)
{
    string str = "";
    int n = s.length();
    if (n == 0)
    {
        return str;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            str = str + s[i];
        }
    }
    str.push_back(s[n - 1]);
    return str;
}

int main()
{

    string s1 = "geeksforgeeks";
    cout << RemoveDuplicates(s1) << endl;

    string s2 = "aabcca";
    cout << RemoveDuplicates(s2) << endl;

    return 0;
}