#include <bits/stdc++.h>
using namespace std;

int LCS(string x, string y, int n, int m)
{
    int t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = t[i - 1][j - 1] + 1;
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[n][m];
}

int main()
{
    string x = "axym";
    string y = "adxcpy";
    int n = x.size();
    int m = y.size();
    int result = LCS(x, y, n, m);

    if (n == result)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}