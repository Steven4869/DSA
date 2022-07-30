#include <bits/stdc++.h>
using namespace std;
double mean(int arr[], int n)
{
    double result = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return (double)sum / (double)n;
}

double median(int arr[], int n)
{
    double med = 0;

    if (n % 2 == 0)
    {
        med = arr[n / 2] + arr[(n / 2) + 1];
    }
    else
    {
        med = arr[n / 2];
    }
    return med;
}
int main()
{
    int arr[] = {1, 3, 4, 2, 6, 5, 8, 7};
    sort(arr.begin(), arr.end());
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "the mean is " << mean(arr, n);
    cout << endl;
    cout << "The median is " << median(arr, n);
    return 0;
}