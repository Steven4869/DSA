// Reverse bits of a given 32 bits unsigned integer.

#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i <= 32; i++)
    {
        res <<= 1;
        res = res + n % 2;
        n >> 1;
    }
    return res;
}