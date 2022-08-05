//

#include <bits/stdc++.h>
using namespace std;

int KSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

int main()
{
    int arr[] = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << KSmallest(arr, n, k);
    return 0;
}