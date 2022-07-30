#include <bits/stdc++.h>
using namespace std;

int UniqueSum(int n)
{
    vector<int> result;
    if (n % 2 != 0)
    {
        result.push_back(0);
    }
    for (int i = 1; result.size() < n; i++)
    {
        result.push_back(i * pow(-1, i));
        result.push_back(-1 * i * pow(-1, i));
    }
    return result;
}

int main()
{
    int n = 5;
    cout << UniqueSum(n);
    return 0;
}