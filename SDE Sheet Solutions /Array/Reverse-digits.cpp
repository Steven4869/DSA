#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int result = 0;
    while (x)
    {
        int temp = x % 10;
        x = x / 10;
        if (result > 0 && result > (INT_MAX - temp) / 10 || result < 0 && result < (INT_MIN - temp) / 10)
        {
            return 0;
        }
        result = result * 10 + temp;
    }
    return result;
}
int main()
{
    int x = 521;
    cout << reverse(x);
}