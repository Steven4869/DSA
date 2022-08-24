#include <bits/stdc++.h>
using namespace std;

string LPS(string x, string y, int n, int m)
{
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
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    // Printing result
    string result;
    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            result.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i - 1][j] > t[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string x = "apple";
    string y = x;
    reverse(y.begin(), y.end());
    int n = x.size();
    int m = y.size();
    cout << LPS(x, y, n, m);
}