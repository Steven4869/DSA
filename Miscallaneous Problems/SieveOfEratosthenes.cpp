#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void SieveOfEratosthene(int n)
{
    bool Prime(n + 1);
    memset(Prime, true, sizeof(Prime));
    Prime[0] = false;
    Prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = 2 * i; j <= n; j = j + i)
        {
            Prime[j] = false;
        }
    }
    for (int p = 0; p <= n; p++)
        if (Prime[p])
            cout << p << " ";
}
// int main()
// {
//     isPrime(11) ? cout << " true\n" : cout << " false\n";
//     isPrime(15) ? cout << " true\n" : cout << " false\n";
//     return 0;
// }

int main()
{
    int n = 30;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}