// It's a index based sorting, fastest but consumes a lot of memory
// Transfer the number from arr to count array and increment it at its index if element matches to it
// Now transfer the count array numbers to arr by putting the values that not 0

#include <bits/stdc++.h>
using namespace std;

int Max(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void CountSort(int arr[], int n)
{
    int max = Max(arr, n);
    int *count = new int[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    int i = 0;
    int j = 0;
    while (j < max + 1)
    {
        if (count[j] > 0)
        {
            arr[i++] = j;
        }
        else
        {
            j++;
        }
    }
    // delete[] count;
}
void Print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    CountSort(arr, n);
    Print(arr, n);
}