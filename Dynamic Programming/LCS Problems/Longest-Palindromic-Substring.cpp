#include <bits/stdc++.h>
using namespace std;

int LPS(string x, string y, int n, int m)
{
    int res = 0;
    string ans;
    int t[n + 1][m + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = 0;
            }

            if (t[i][j] > res)
            {
                string temp = x.substr(i - t[i][j], t[i][j]);
                string rev = temp;
                reverse(rev.begin(), rev.end());
                if (temp == rev)
                {
                    ans = temp;
                }
                res = t[i][j];
            }
        }
    }
    return ans;
}