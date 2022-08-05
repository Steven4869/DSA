#include <bits/stdc++.h>
using namespace std;

void KLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    while (pq.size() > 0)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    KLargest(arr, n, k);
    return 0;
}