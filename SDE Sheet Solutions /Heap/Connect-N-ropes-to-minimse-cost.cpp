// Connect n ropes with minimum cost

// There are given n ropes of different arrgths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to the sum of their arrgths. We need to connect the ropes with minimum cost.

// For example, if we are given 4 ropes of arrgths 4, 3, 2, and 6. We can connect the ropes in the following ways.

// First, connect ropes of arrgths 2 and 3. Now we have three ropes of arrgths 4, 6, and 5.
// Now connect ropes of arrgths 4 and 5. Now we have two ropes of arrgths 6 and 9.
// Finally connect the two ropes and all ropes have connected.

// Approach
// 1. To get the minimium cost we'll have to take the first two smaller elements on the top take their sum and repeat the procedure until we get the answer
// 2. Our idea is to go with Min Heap because it'll have the smallest elements on the top and we can take thier sum easily by popping them out

// Code

#include <bits/stdc++.h>
using namespace std;
int ConnectRopes(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        result = result + (first + second);
        pq.push(first + second);
    }
    return result;
}

int main()
{
    int arr[] = {4, 3, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Total cost for connecting ropes is " << ConnectRopes(arr, size);
    return 0;
}