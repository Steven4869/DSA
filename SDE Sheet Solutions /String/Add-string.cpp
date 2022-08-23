// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// Input: num1 = "11", num2 = "123"
// Output: "134"

// Approach
//  1. We need to solve this in a similar way how we do the normal addition
//  2. Add the last two elements
//  3. Check if there's a carry element or not
//  4. Take the last digit in the result only

#include <bits/stdc++.h>
using namespace std;

string AddNumber(string num1, string num2)
{
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while (i >= 0 || j >= 0 || carry)
    {
        long sum = 0;
        if (i >= 0)
        {
            sum = sum + (num1[i] - '0');
            i--;
        }
        if (j >= 0)
        {
            sum = sum + (num2[j] - '0');
            j--;
        }
        sum = sum + carry;
        carry = sum / 10;
        sum = sum % 10;
        res = res + to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string num1 = "11";
    string num2 = "123";
    cout << AddNumber(num1, num2);
}