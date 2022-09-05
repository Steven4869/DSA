#include <bits/stdc++.h>
using namespace std;

// Make up a function to count set bits

int CountBits(int n)
{
    int count = 0;
    while (n)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int compactor(int a, int b)
{
    int count1 = CountBits(a);
    int count2 = CountBits(b);
    if (count1 <= count2)
    {
        return false;
    }
    return true;
}
void SortBySetBits(int arr[], int n)
{
    sort(arr, arr + n, compactor);
}
void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    SortBySetBits(arr, n);
    PrintArray(arr, n);
}