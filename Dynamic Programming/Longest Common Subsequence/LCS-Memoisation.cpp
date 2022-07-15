#include <iostream>
using namespace std;

static int t[1001][1001];
int LCS(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (t[n][m] != -1)
    {
        return t[n][m];
    }

    if (x[n - 1] == y[m - 1])
    {
        return t[n][m] = 1 + LCS(x, y, n - 1, m - 1);
    }
    else
    {
        return t[n][m] = max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1));
    }
    return t[n][m];
}

int main()
{
    memset(t, -1, sizeof(t));
    char x[] = "AGGTAB";
    char y[] = "GXTXAYB";
    int n = strlen(x);
    int m = strlen(y);
    cout << "Length of LCS is " << LCS(x, y, n, m);
}