// N meetings in one room
// Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.

// Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}

// Output: 1 2 4 5

// start: 1 3 0 5 8 5
// end:   2 4 5 7 9 9
// pos:   1 2 3 4 5 6

// Approach
// 1. Sort the data in the order of end time
// 2. Create avariable to store result and initalise to 1
// 3. Make an variable limit that will keep track of all ending time of meeting that was performed
// 4. If starting time of limit is greater than limit thenm we can perform the meeting, then update the limit with new end time
// 5. Otherwise just move ahead

// Code

#include <bits/stdc++.h>
using namespace std;

struct meeting
{
    int start;
    int end;
    int pos;
};

// Creating a compare function that sorts it basd on return type
bool compare(struct meeting m1, struct meeting m2)
{
    if (m1.end < m2.end)
    {
        return true;
    }
    else if (m1.end > m2.end)
    {
        return false;
    }
    else if (m1.pos < m2.pos)
    {
        return true;
    }
    return false;
}
void MaxMeeting(int s[], int e[], int n)
{
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        // Initialising the required values to the array
        meet[i].start = s[i];
        meet[i].end = e[i];
        meet[i].pos = i + 1;
    }

    // Sort the meeting based on ending time
    sort(meet, meet + n, compare);

    // Creating a variable to store result
    vector<int> result;

    // Making limit value to the ending time
    int limit = meet[0].end;

    // Pushing the inital meet value as it'll always have one meeting
    result.push_back(meet[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            limit = meet[i].end;
            result.push_back(meet[i].pos);
        }
    }
    cout << "The order in which the meetings will be performed is " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

// TC:O(Nlogn)-due to sorting  SC:O(N)-for meet
int main()
{
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};

    MaxMeeting(start, end, n);
    return 0;
}