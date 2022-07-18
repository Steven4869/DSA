#include <bits/stdc++.h>
using namespace std;

string LCS(string x, string y, int n, int m)
{
    // Basic Initialisation of LCS
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
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    // Printing of SCS
    int i = n;
    int j = m;
    string result;
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
            if (t[i][j - 1] > t[i - 1][j])
            {
                result.push_back(y[j - 1]);
                j--;
            }
            else
            {
                result.push_back(x[i - 1]);
                i--;
            }
        }
    }
    while (i > 0)
    {
        result.push_back(x[i - 1]);
        i--;
    }
    while (j > 0)
    {
        result.push_back(y[j - 1]);
        j--;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    char x[] = "aaaaaaaa";
    char y[] = "aaaaaaaa";
    int n = strlen(x);
    int m = strlen(y);
    cout << "The LPS is " << LCS(x, y, n, m);
    return 0;
}