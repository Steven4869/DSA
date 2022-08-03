#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    if (n > 0)
    {
        print(n - 1);
        cout << n << " ";
    }
    return;
}
int main()
{
    print(7);
    return 0;
}