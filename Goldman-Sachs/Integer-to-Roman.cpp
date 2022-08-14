// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Input: num = 3
// Output: "III"
// Explanation: 3 is represented as 3 ones.

#include <bits/stdc++.h>
using namespace std;

string IntegerToRoman(int num)
{
    string res;
    string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for (int i = 0; num != 0; i++)
    {
        while (num >= val[i])
        {
            num = num - val[i];
            res = res + symbol[i];
        }
    }
    return res;
}

int main()
{
    int num = 6969;
    cout << IntegerToRoman(num);
}