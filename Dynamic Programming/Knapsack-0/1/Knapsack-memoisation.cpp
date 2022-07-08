#include <iostream>
using namespace std;
int Knapsack(int wt[], int val[], int W, int n)
{
    // Memoisation Initialisation
    int t[n + 1][W + 1];
    memset(t, -1, sizeof(t));
    // Allocating values
    if (t[n][W] != -1)
    {
        return t[n][W];
    }
    // Base Condition
    if (n == 0 || W == 0)
        return 0;
    // Choice Diagram
    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1), Knapsack(wt, val, W, n - 1)); // Accept the choice or reject it
    }
    else if (wt[n - 1] > W)
    {
        return t[n][W] = Knapsack(wt, val, W, n - 1); // not accpeting the choice as the weight is more than W
    }
    return -1;
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << Knapsack(wt, val, W, n);
    return 0;
}