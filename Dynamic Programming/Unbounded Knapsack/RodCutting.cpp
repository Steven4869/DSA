#include <iostream>
using namespace std;

int RodCutting(int length[], int price[], int n, int N)
{
    int t[n + 1][N + 1];
    // Base Condition will remain same as Knapsack
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
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
        for (int j = 1; j < N + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                // Accepted  & Rejected
                t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
            }
            else if (length[i - 1] > j)
            {
                // Rejected
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][N];
}

int main()
{
    // int N = 8;
    // int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    // If length is not given
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }
    int N = n;
    cout << "Maximum obtained value  is " << RodCutting(length, price, n, N);
    return 0;
}