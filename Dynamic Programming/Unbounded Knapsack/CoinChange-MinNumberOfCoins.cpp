#include <iostream>
using namespace std;

int CoinChange(int coins[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = INT_MAX - 1;
            }
            if (j == 0)
            {
                t[i][j] = 0;
            }
            if (i == 1)
            {
                if (j % coins[0] == 0)
                {
                    t[i][j] = j / coins[0];
                }
                else
                {
                    t[i][j] = INT_MAX - 1;
                }
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                t[i][j] = min(t[i - 1][j], t[i][j - coins[i - 1]] + 1);
            }
            if (coins[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    int coins[] = {2};
    int sum = 3;
    int n = sizeof(coins) / sizeof(coins[0]);
    int result = CoinChange(coins, sum, n);
    if (result < INT_MAX - 1)
    {
        cout << "Minimum number of coins required " << result;
    }
    else
    {
        cout << "No sum exists for it, -1";
    }
    return 0;
}