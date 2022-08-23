#include <bits/stdc++.h>
using namespace std;

int PrintKadane(int arr[], int n)
{
    int sum = 0, max_sum = arr[0], start = 0, end = 0, temp_s = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum > max_sum)
        {
            max_sum = sum;
            start = temp_s;
            end = i;
        }
        if (sum < 0)
        {
            sum = 0;
            temp_s = i + 1;
        }
    }
    cout << "Maximum sub array from arr[" << start << "] = " << arr[start] << " till arr[" << end << "] = " << arr[end] << " = " << max_sum << endl;
    return max_sum;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    PrintKadane(arr, n);
    return 0;
}