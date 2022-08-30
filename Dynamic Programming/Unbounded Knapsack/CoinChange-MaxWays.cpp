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
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
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
    int coins[] = {1, 2, 3};
    int sum = 3;
    int n = sizeof(coins) / sizeof(coins[0]);
    cout << "Total number of ways are " << CoinChange(coins, sum, n);
    return 0;
}