// Merging Two lists
// Merging two sorted lists into one sorted lists
#include <bits/stdc++.h>
using namespace std;

void Merge(int list1[], int list2[], int m, int n)
{
    // Intialise i, j, k to be 0
    int i = j = k = 0;
    int list3[m + n];
    while (i < m && j < n)
    {
        if (list1[i] < list2[j])
        {
            list3[k++] = list1[i++];
        }
        else
        {
            list3[k++] = list2[j++]
        }
    }
    for (; i < m; i++)
    {
        list3[k++] = list1[i];
    }
    for (; j < n; j++)
    {
        list3[k++] = list2[j];
    }
}

int main()
{
    int list1[] = {2, 10, 18, 20, 23};
    int list2[] = {4, 9, 19, 25};
    int m = list1.size();
    int n = list2.size();
    Merge(list1, list2, m, n);
}