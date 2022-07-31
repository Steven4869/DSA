// Merge Overlapping Sub-intervals
// Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

// Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

// Output: [[1,6],[8,10],[15,18]]

// Approach
// 1. Sort the intervals array, according to the starting time
// 2. Once we have sorted array, we can combine all the intervals in one traversal
// 3. If interval[i] doesn't overlap with interval[i-1], then interval[i+1] cannot overlap with interval[i-1] because stating time must be greater than interval[i]
// 4. [1,3],[2,6]: here 3 is greater than 2, then it can overrlap to [1,6]

// Code
// 1. Sort the elements based on the starting time
// 2. Push the first element into stack
// 3. If the interval doesn't overlap with top then push it into stack
// 4. if it overlaps then update stack top with ending time of interval
// 5. the end of stack conatins the merged intervals

// Creating interval structure of start and end

#include <bits/stdc++.h>
using namespace std;
struct Interval
{
    int start;
    int end;
};

// Compare function based on starting time
bool compare(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
void MergeIntervals(Interval arr[], int n)
{
    // Base condition if the length is lest then equal to zero then return nothinh
    if (n <= 0)
    {
        return;
    }
    // Sort the array based on the starting time
    sort(arr, arr + n, compare);

    // Stack to store the first element of Interval array
    stack<Interval> st;
    // Push the first array
    st.push(arr[0]);

    // Start from the next interval and check for the overlapping condition
    for (int i = 1; i < n; i++)
    {
        Interval top = st.top();
        // If the current element is not overlapping then push it into stack
        if (top.end < arr[i].start)
        {
            st.push(arr[i]);
        }
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            st.pop();
            st.push(top);
        }
    }

    // Printing the stack
    cout << "Merged Intervals are :";
    while (!st.empty())
    {
        Interval t = st.top();
        cout << "[" << t.start << "," << t.end << "]";
        st.pop();
    }
    return;
}

int main()
{
    Interval arr[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeIntervals(arr, n);
    return 0;
}