#include <bits/stdc++.h>
using namespace std;

void Permuations(string s, int left, int right)
{
    if (left == right)
    {
        cout << s << endl;
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(s[left], s[i]);
            Permuations(s, left + 1, right);
            swap(s[left], s[i]);
        }
    }
}

int main()
{
    string s = "ABC";
    int n = s.size();
    Permuations(s, 0, n - 1);
    return 0;
}