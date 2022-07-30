#include <bits/stdc++.h>
using namespace std;

bool isPower(int n)
{
    if (n == 0)
    {
        return 0;
    }
    while (n != 1)
    {
        if (n % 2 != 0)
        {
            return 0;
        }
        n = n / 2;
    }
    return 1;
}

int main()
{
    int n = 16;
    bool count = isPower(n);
    cout << count;
    return 0;
}