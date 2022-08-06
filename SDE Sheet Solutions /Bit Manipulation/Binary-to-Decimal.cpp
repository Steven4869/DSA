// Binary is represented by 0 and 1
// To get Decimal just do the 2 power to the last digits of binary number

// Input : 111
// Output : 7

// Approach
// 1. Initalise remainder, base and decimal
// 2. Allot temp to be num and Run the loop until number becomes 0
// 3. Get the remainder, and make decimal to be remainder times base
// 4. Increment the power of base by 2 witth each iteration
// 5. Make temp to be divided by 10

// Code

#include <bits/stdc++.h>
using namespace std;

int Binary2Decimal(int n)
{
    //  base and decimal
    int base = 1;
    int dec = 0;

    int temp = n;
    while (temp)
    {
        int rem = temp % 10;
        dec = dec + rem * base;
        base = base * 2;
        temp = temp / 10;
    }
    return dec;
}

int main()
{
    int n = 101;
    cout << Binary2Decimal(n);
}