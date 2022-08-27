// Approach
// 1. Create a vecctor to store the result and lenght will be the sum both the strings
// 2. Start wiht the very last and multiply the vector for i+j+1

#include <bits/stdc++.h>
using namespace std;

string Multiply(string num1, string num2)
{
    int n = num1.size();
    int m = num2.size();
    vector<int> result(n + m, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            result[i + j] = result[i + j + 1] / 10;
            result[i + j + 1] = result[i + j + 1] % 10;
        }
    }
    int i = 0;
    string ans = "";
    while (res[i] == 0)
    {
        i++;
    }
    while (i < res.size())
    {
        ans = ans + to_string(res[i++]);
    }
    return ans;
}
