// Given a array of N strings, find the longest common prefix among all strings present in the array.

// Example 1:

// Input:
// N = 4
// arr[] = {geeksforgeeks, geeks, geek,
//          geezer}
// Output: gee
// Explanation: "gee" is the longest common
// prefix in all the given strings.

// Approach
//  1. Sort the array based on the size and the run the loop for the shortest string
//  2. Compare the last element and first element of the array
//  3. Pass the matching letters to the result string
//  4. Print the result string

#include <bits/stdc++.h>
using namespace std;

string LCP(string arr[], int n)
{
    string result = "";
    sort(arr, arr + n);
    string first = arr[0], q = arr[n - 1];
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == q[i])
        {
            result = result + p[i];
        }
        else
        {
            break;
        }
    }
    if (result == "")
    {
        return -1;
    }
    else
    {
        return result;
    }
}