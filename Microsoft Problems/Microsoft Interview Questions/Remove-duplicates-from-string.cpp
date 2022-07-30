#include <bits/stdc++.h>
using namespace std;

string Duplicates(char str[], int n)
{

    // initialise index to 0
    int index = 0;
    for (int i = 0; i < n; i++)
    {

        int j;
        for (j = 0; j < n; j++)
        {
            if (str[i] == str[j])
            {
                break;
            }
        }
        if (j == i)
        {
            str[index++] = str[i];
        }
    }
    return str;
}

// string RemoveDuplicates(char str[], int n){
//     unordered_set<char>s (str, str+n);
//     int i=0;
//     for(auto x:s){
//         str[i++]=x;
//     }
//     str[i] = "\0";
//     return str;
// }

int main()
{
    char str[] = "geekforgeeks";
    int n = sizeof(str) / sizeof(str[0]);
    cout << Duplicates(str, n);
    return 0;
}