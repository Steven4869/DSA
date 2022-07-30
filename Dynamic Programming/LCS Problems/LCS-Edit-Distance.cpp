#include <bits/stdc++.h>
using namespace std;

int EditDistance(string x, string y, int n, int m)
{
    int t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++)
    {
        t[0][j] = j;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = min((t[i - 1][j - 1], t[i - 1][j]), t[i][j - 1]) + 1;
            }
        }
    }
    return t[n][m];
}

int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";
    int n = str1.length();
    int m = str2.length();

    cout << EditDistance(str1, str2, n, m);

    return 0;
}