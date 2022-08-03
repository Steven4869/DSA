// Print All Permutations of a String/Array
// Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.

// Input: arr = [1, 2, 3]

// Output:
// [
//   [1, 2, 3],
//   [1, 3, 2],
//   [2, 1, 3],
//   [2, 3, 1],
//   [3, 1, 2],
//   [3, 2, 1]
// ]

// Approach
// 1. Go with BAacktracking Approach
// 2. Make the variables left and right in the recurisve call
// 3. If the left and right are equal then print the result
// 4. Run the loop from left to right
// 5. Swap the left element with the ith element of the string
// 6. Swap->Recursive Call->swap

#include <bits/stdc++.h>
using namespace std;

void permute(string s, int left, int right)
{
    if (left == right)
    {
        cout << s << endl;
    }
    else
    {
        // Permutations made
        for (int i = left; i <= right; i++)
        {
            // Swapping
            swap(s[left], s[i]);
            // Recursive Call
            permute(s, left + 1, right);
            // Backtracked
            swap(s[left], s[i]);
        }
    }
}

int main()
{
    string s = "ABC";
    int n = s.size();
    permute(s, 0, n - 1);
    return 0;
}