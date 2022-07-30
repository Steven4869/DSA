#include <bits/stdc++.h>
using namespace std;

// IP:{3,1,3}  OP:Missing:2 Repeating:3

int MissingElements(int arr[], int n)
{
    sort(arr, arr + n);
    int missing;
    //{1,3,3}
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) != arr[i])
        {
            missing = i + 1; // Missing element
        }
    }
    return missing;
}

int RepeatingElements(int arr[], int n)
{
    sort(arr, arr + n);
    int repeating;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            repeating = arr[i]; // Repeating element
        }
    }
    return repeating;
}
// TC:O(NlogN) SC:O(1)

int main()
{
    int arr[] = {3, 1, 2, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MissingElements(arr, n) << endl;
    cout << RepeatingElements(arr, n);
    return 0;
}