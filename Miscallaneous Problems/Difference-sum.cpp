#include <bits/stdc++.h>
using namespace std;

int DifferenceSum(int n, int m)
{
    vector<int> add;
    vector<int> sub;
    for (int i = 0; i <= m; i++)
    {
        if (m % i == 0)
        {
            add.push_back(i);
        }
        else
        {
            sub.push_back(i);
        }
    }
    int sum = 0;
    for (int i = 0; i < add.size(); i++)
    {
        sum = sum + add[i];
    }
    int sum2 = 0;
    for (int i = 0; i < sum2.size(); i++)
    {
        sum2 = sum2 + sub[i];
    }
    int result = sum2 - sum1;
}