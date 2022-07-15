#include <iostream>
using namespace std;

int LCS(string x, string y, int n, int m)
{
    // Base condition
    // If both the size of string is zero then LCS is 0
    if (n == 0 || m == 0)
    {
        return 0;
    }
    // Choice Diagram
    // If both the elemnts at last are equal then add 1 to the answer
    // and decrease the array
    if (x[n - 1] == y[m - 1])
    {
        return 1 + LCS(x, y, n - 1, m - 1);
    }
    else
    {
        return max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1));
    }
    return -1;
}
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int n = strlen(X);
    int m = strlen(Y);

    cout << "Length of LCS is " << LCS(X, Y, n, m);
}
