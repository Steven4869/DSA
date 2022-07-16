#include <iostream>
using namespace std;

int LCS(string x, string y, int n, int m)
{
    int t[n + 1][m + 1];
    int result = 0;
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
                result = max(result, t[i][j]);
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    return result;
}

int main()
{
    char x[] = "abcde";
    char y[] = "abced";
    int n = strlen(x);
    int m = strlen(y);

    cout << "Length of Substring is " << LCS(x, y, n, m);
}