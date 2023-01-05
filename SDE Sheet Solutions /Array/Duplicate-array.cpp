#include <bits/stdc++.h>
using namespace std;

// Finding Duplicates in a sorted array

void Duplicates(int arr[], int n)
{
    int lastDuplicate = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1] && lastDuplicate != arr[i])
        {
            cout << "Duplicate " << arr[i] << endl;
            lastDuplicate = arr[i];
        }
    }
}

// Count number of duplicates

void NumberDuplicates(int arr[], int n)
{
    int j;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            j = i + 1;
            while (arr[j] == arr[i])
            {
                j++;
            }
            cout << arr[i] << " appears for " << j - i << " times " << endl;
            i = j + 1;
        }
    }
}
int main()
{
    int arr[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    Duplicates(arr, n);
    NumberDuplicates(arr, n);
    string hello1 = "shivam";
    char hello[] = "shivam";
    cout << sizeof(hello1) << endl;
    cout << sizeof(hello);
}