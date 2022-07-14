#include <iostream>
using namespace std;

int UnboundedKnapsack(int wt[], int val[], int W, int n)
{
    int t[n + 1][W + 1];
    // Base Condition will remain same as Knapsack
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    // Choice Diagram
    // Here in unbounded diagram we'll not process the rejected item but we are allowed
    // to select the accepetd items more than once, so instead of moving to n-1 we'll reamin with n
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                // Accepted  & Rejected
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            }
            else if (wt[i - 1] > j)
            {
                // Rejected
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val) / sizeof(val[0]);

    cout << UnboundedKnapsack(wt, val, W, n);
    return 0;
}