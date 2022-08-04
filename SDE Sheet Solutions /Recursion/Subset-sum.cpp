// Subset Sum : Sum of all Subsets
// Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

// Input: s="ab"

// Output: " ", "a", "b", "ab"

// Approach
// 1.Draw the recursive tree by taking no output and as we go down smaller the input and increment the output
// 2.Leaf Node of it makes it to the base condition

// Code
// 1. If the input is emptyh then return the string
// 2. Intialise two output formed from the inital recursive tree
// 3. rease the first index of input to smaller the input
// 4. Call the function again for the other two outputs

#include <bits/stdc++.h>
using namespace std;
void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << " ";
        return;
    }

    // Recursive Tree
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
}

int main()
{
    string ip = "ab";
    string op = "";
    solve(ip, op);
}