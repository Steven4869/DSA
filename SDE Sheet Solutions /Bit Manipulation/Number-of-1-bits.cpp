// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
#include <bits/stdc++.h>
using namespace std;
int HammingWeight(uint32_t n)
{
    int result = 0;
    while (n != 0)
    {
        result++;
        // Checks if n is power of 2
        n &= n - 1;
    }
    return result;
}