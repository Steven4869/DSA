#include<bits/stdc++.h>
using namespace std;

int main() {
    int n =2;

    int num_servers[] = {4, 3};
    int money[] = {8, 9};
    int sell[] = {4, 2};
    int upgrade[] = {4, 5};

    int res = 0;
    for (int i = 0; i < n; i++) {
        int lo = 0, hi = num_servers[i];
        int temp = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid * upgrade[i] <= money[i] + sell[i] * (num_servers[i] - mid)) {
                temp = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        res += temp;
    }
    cout << res << '\n';
    return 0;
}
