// You are required to implement the following function: int CountSpecificNumbers(int m, int n)

// The function accepts two arguments m and n which are integers. You are required to calculate the count of numbers having only 1, 4 and 9 as their digits between the numbers lying in the range m and n both inclusive, and return the same. Return -1 if m>n.
#include <bits/stdc++.h>
using namespace std;
int CountSpecificNumbers(int m, int n)
{
    if (m > n)
    {
        return -1;
    }
    int temp, count = 0, flag, last_digit;
    for (int i = m; i <= n; i++)
    {
        temp = i;
        flag = 0;
        while (temp > 0)
        {
            last_digit = temp % 10;
            if (last_digit == 0 || last_digit == 2 || last_digit == 3 ||
                last_digit == 5 || last_digit == 6 || last_digit == 7 || last_digit == 8)
            {
                flag = 1;
                break;
            }
            temp = temp / 10;
        }
        if (flag == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int m = 100;
    int n = 200;
    cout << CountSpecificNumbers(m, n);
}