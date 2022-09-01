// 1. Maintain a boolean table[n][n] that is filled in bottom up manner.
// 2. The value of table[i][j] is true, if the substring is palindrome, otherwise false.
// 3. To calculate table[i][j], check the value of table[i+1][j-1], if the value is true and str[i] is same as str[j], then we make table[i][j] true.
// 4. Otherwise, the value of table[i][j] is made false.
// 5. We have to fill table previously for substring of length = 1 and length =2 because
// as we are finding , if table[i+1][j-1] is true or false , so in case of
// (i) length == 1 , lets say i=2 , j=2 and i+1,j-1 doesn’t lies between [i , j]
// (ii) length == 2 ,lets say i=2 , j=3 and i+1,j-1 again doesn’t lies between [i , j].

#include <bits/stdc++.h>
using namespace std;

void PrintSubstr(string str, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        cout << str[i];
    }
}
void LPS(string str)
{
    int n = str.size();
    int t[n][n];
    memset(t, 0, sizeof(t));

    // All substrings of length 1 are palindrome
    int maxLength = 1;
    for (int i = 0; i < n; i++)
    {
        t[i][i] = 1;
    }
    // For substring of length 2
    int start = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            t[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }
    // For substring greater than 2
    for (int k = 3; k <= n; k++)
    {
        // Finding starting index
        for (int i = 0; i < n - k + 1; i++)
        {
            // Getting the ending index of substing
            // from index i and length k
            int j = i + k - 1;
            if (t[i + 1][j - 1] && str[i] == str[j])
            {
                t[i][j] = 1;
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    cout << "Longest Palindromic Substring ";
    PrintSubstr(str, start, start + maxLength - 1);
}

int main()
{
    string str = "babad";
    LPS(str);
}