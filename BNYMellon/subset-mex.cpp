#include <bits/stdc++.h>
using namespace std;
#define long long int

void solve(int n, int arr[])
{

    set<int> st;
    for (int i = 0; i < n; i++)
    {

        st.insert(arr[i]);
    }
    int x = 0;

    for (int i = 0; i < 32; i++)
    {
        int t = (1 << 1);

        if (st.find(t) == st.end())
        {
            int tmp = x + 1;

            while (1)
            {

                if (st.find(tmp) == st.end())
                {
                    cout << tmp << endl;
                    return;
                }
                tmp++;
            }
        }
        x += t;
    }
}
int main()
{
    int t = 3;
    int n = 2;
    int arr[] = {2, 3};
    while (t--)
    {
        solve(n, arr);
    }
    return 0;
}