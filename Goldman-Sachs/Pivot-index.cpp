#include <bits/stdc++.h>
using namespace std;

int pivotIndex(int nums[], int n)
{
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];
    }
    long long int leftSum = 0;
    long long int rightSum = sum;
    for (int i = 0; i < n; i++)
    {
        rightSum = rightSum - nums[i];
        // cout << rightSum << " ";
        if (leftSum == rightSum)
            return i;
        leftSum = leftSum + nums[i];
        // cout << leftSum << " ";
    }
    return -1;
}

int main()
{
    int nums[] = {1, 7, 3, 6, 5, 6};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << pivotIndex(nums, n);
}