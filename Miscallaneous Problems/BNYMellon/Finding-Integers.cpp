// n=4, k=2
// arr[]={4,2,1,3}

// OP:[2,2,3] => i=2 arr[4,2], i=3 arr[4,2,1], i=4 arr[4,2,1,3]

#include <bits/stdc++.h>
using namespace std;

void KthLargestElement(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);

        if (pq.size() > k)
        {
            pq.pop();
        }
        if (i >= k - 1)
        {
            cout << i << endl;
            v.push_back(pq.top());
        }
    }
    // while (pq.size() > 0)
    // {
    //     cout << pq.top();
    //     pq.pop();
    // }
    cout << v.size() << endl;
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 2, 1, 3};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << KthLargestElement(arr, n, k);
}