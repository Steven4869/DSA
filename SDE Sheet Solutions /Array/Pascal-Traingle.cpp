// Program to generate Pascal’s Triangle
// Problem Statement: Given an integer N, return the first N rows of Pascal’s triangle.

// Input Format: N = 5

// Result:
//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1

// Approach
// 1. Always the first and last element of the row are going to be one
// 2. The middle element is alwasy the sum of first two elements of previous row
// 3. N gives us the number of rows it'll have

// Code
// 1. create an auxiliary array of nxn space
// 2. Make two for loops one for the line and other for the elements, there will be n lines and line elements
// 3. So if line is 3 there will be three elements

#include <bits/stdc++.h>
using namespace std;
void Pascal(int n)
{
    // Creating auxilary space
    int arr[n][n];

    // Creating two for loops
    for (int line = 0; line < n; line++)
    {
        for (int i = 0; i <= line; i++)
        {
            // The first and last element will be i
            if (i == 0 || line == i)
            {
                arr[line][i] = 1;
            }
            else
            {
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
            }
            cout << arr[line][i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n = 5;
    Pascal(n);
    return 0;
}