// Add two numbers without using arithmetic operators

// Approach
//  1. Use Bitwise operators for it
//  2. We'll be using XOR operator for it

#include <bits/stdc++.h>
using namespace std;

int Add(int x, int y)
{

    // Iterate till there is no carry
    while (y != 0)
    {
        // Carry is unsigned to deal with negative numbers
        unsigned carry = x & y;
        x = x ^ y;
        // Carry is shifted by one bit, so adding it with x gives required sum
        y = carry << 1;
    }
    return x;
}

int Subtract(int x, int y)
{
    while (y != 0)
    {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x
}
int main()
{
    cout << Add(-105, 201);
    return 0;
}