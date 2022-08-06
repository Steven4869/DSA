#include <bits/stdc++.h>
using namespace std;

// To check if integer is odd or even
// n&1->returns if number is even or odd, because in case of odd number there will always be a digit at units place

int OddEven(int n)
{
    if (n & 1)
    {
        cout << n << " is Odd";
    }
    else
    {
        cout << n << " is Even";
    }
    return 0;
}

// Add 1 to an integer
//  The expression -~x will add 1 to x, for negative number we need to invert the bits
//  -x = ~x + 1 => -~x = x+1

int AddOne(int n)
{
    cout << n << " + " << 1 << " is " << -~x << endl;
}

// Swapping of two numbers
//  We are using the XOR operatios of x^x=0
void swap(int &x, int &y)
{
    if (x != y)
    {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
}

// Turning of kth bit in a number
// The ides is to use << wise operator
// The expresssion ~(1<<(k-1)) will give us a number with all bits set
// If we do AND with n we'll get all the same bit but except for kth bit
int turnOffKthBit(int n, int k)
{
    return n & ~(1 << (k - 1));
}