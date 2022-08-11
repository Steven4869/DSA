// The Celebrity Problem

// In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. Find the stranger (celebrity) in the minimum number of questions.
// We can describe the problem input as an array of numbers/characters representing persons in the party. We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false otherwise. How can we solve the problem.

// Approach
//  1. Create two variables in, out that will have n space. In refers to the person who knows i, whereas out refers to how many persons i knows
// 2. Run two nested loop to determine where the person exists, arr[i][j] refers to person i knows person j
// 3. THe condition for the celebrity is when everyone knows him and he knows nobody, so in[i]==n-1 and out[i]==0 and return its index

// Code

#include <bits/stdc++.h>
using namespace std;

void Celebrity(vector<vector<int>> &arr, int n)
{
    int in[n];
    int out[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Checking if the person exists who knows celebrity or not
            if (arr[i][j] == 1)
            {
                // It means Person i knows person j
                // Then someone knows j
                //  i have known j
                in[j]++;
                out[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (in[i] == n - 1 && out[i] == 0)
        {
            return i;
        }
        return -1;
    }
}

int main()
{
    vector<vector<int>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    } int n = arr.size();
    Celebrity(arr, n);
    return 0;
}