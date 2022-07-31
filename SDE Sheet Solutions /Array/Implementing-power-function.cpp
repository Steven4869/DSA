// Implement Pow(x,n) | X raised to the power N
// Problem Statement: Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).

// Approach
// 1. We'll need to consider two cases, one being negative and other being positive
// 2. For the negative number, make the power 1/x
// 3. If the number is even, then multply it by itself, and make the n half of it

// Code

#include <bits/stdc++.h>
using namespace std;

double myPower(double x, int n)
{
    // Base condittion
    if (n == 0)
    {
        return 1;
    }

    // For negative number
    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }
    return (n % 2 == 0) ? myPower(x * x, (n / 2)) : x * myPower(x * x, (n / 2));
}

int main()
{
    double x = 2.1;
    int n = -10;
    cout << myPower(x, n);
    return 0;
}