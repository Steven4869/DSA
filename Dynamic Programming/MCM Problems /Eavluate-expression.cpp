// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
// Let the input be in form of two arrays one contains the symbols (T and F) in order and the other contains operators (&, | and ^}

// Approach
// The question is similar to the MCM, but her we'll do some modification in the code

#include <bits/stdc++.h>
using namespace std;

// MCM-4 points
// Finding i and j
//  i=0, j = size -1

int solve(string s, int i, int j, int isTrue)
{
    // Base Condition
    // Determining that the string is empty
    if (i > j)
    {
        return 0;
    }
    // If the string has only one element
    if (i == j)
    {
        // Checking if the element is true or not, if it's true then returning the value to the string
        if (isTrue == 1)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }

    // Initialisng the k loop
    // The operator starts with i+1, and we need to move k+2 every time
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        // Intialise all the possible values
        int LT = solve(s, i, k - 1, 1);
        int LF = solve(s, i, k - 1, 0);
        int RT = solve(s, k + 1, j, 1);
        int RF = solve(s, k + 1, j, 0);

        // Initialising the function

        if (s[k] == '&')
        {
            if (isTrue == 1)
            {
                ans = ans + LT * RT;
            }
            else
            {
                ans = ans + (LT * RF + LF * RT + LF * RF);
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
            {
                ans = ans + (LT * RT + LT * RF + RF * LT);
            }
            else
            {
                ans = ans + (LF * RF);
            }
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
            {
                ans = ans + (LT * RF + LF * RT);
            }
            else
            {
                ans = ans + (LT * RT + LF * RF);
            }
        }
    }
    return ans;
}

int main()
{
    string s = "T|T&F^T";
    int n = s.length();

    cout << solve(s, 0, n - 1, 1);
    return 0;
}