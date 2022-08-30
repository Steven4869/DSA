#include <bits/stdc++.h>
using namespace std;
int maxHeight(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    int max_area = 0;
    while (left < right)
    {
        int area = 0;
        int width = right - left;
        int height = min(arr[left], arr[right]);
        area = height * width;
        max_area = max(max_area, area);
        if (arr[left] > arr[right])
        {
            right--;
        }
        else if (arr[right] > arr[left])
        {
            left++;
        }
        else
        {
            right--;
            left++;
        }
    }
    return max_area;
}

int main()
{
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxHeight(arr, n);
}