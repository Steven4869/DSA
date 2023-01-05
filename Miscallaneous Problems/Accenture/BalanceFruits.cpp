// Balance Fruits

// Implement the following function: int BalanceFruits(int a, int m, int rs);

// You have a basket full of apples and mangoes, your job is to make the numer of apples and given a function that accepts three integers 'a', 'm' and 'rs' as its argument where 'a' and a basket respectively and 'rs' is the rupees that you have. Implement the function to balance the basket. If 'a' > 'm', then buy (a - m) mangoes at the rate of Rs 1 per mango. If 'a' < 'm', then sell (m - a) mangoes at the rate of Rs 1 per mango. Return the total rupees left with you after balancing the fruits.
#include <bits/stdc++.h>
using namespace std;
int BalanceFruits(int a, int m, int rs)
{
    int buy = 0, sell = 0;
    int profit = 0;
    if (a > m)
    {
        buy = buy + (a - m) * 1;
    }
    else
    {
        sell = sell + (m - a) * 1;
    }
    if (buy > 0)
    {
        profit = profit + (rs - buy);
    }
    else if (sell > 0)
    {
        profit = profit + (rs + sell);
    }
    return profit;
}

int main()
{
    int a = 6, m = 10, rs = 6;
    cout << BalanceFruits(a, m, rs);
}