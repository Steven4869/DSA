// Sort the elements based on their frequencies

// Approach
// 1.Initalise the map to insert the elemens into frequencies
// 2. Since we need the one with most frequenices at top, we'll go with max heap
// 3. We'll induce pair with first element being mapped element and other being the array element and push it into pq
// 4. We'll have a frequency and element for it to be diaplyed for each top of pq
#include <bits/stdc++.h>
using namespace std;

void FrequencySort(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto i : mp)
    {
        pq.push({i.second, i.first});
    }
    while (pq.size() > 0)
    {
        int freq = pq.top().first;
        int element = pq.top().second;
        for (int i = 0; i < freq; i++)
        {
            cout << element << " ";
        }
        pq.pop();
    }
}

int main()
{
    int arr[] = {2, 1, 1, 2, 3, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    FrequencySort(arr, n);
    return 0;
}