// Reverse words in a given string

// Input: s = “geeks quiz practice code”
// Output: s = “code practice quiz geeks”

// Input: s = “getting good at coding needs a lot of practice”
// Output: s = “practice of lot a needs coding at good getting”

// Approach
// 1. Reverse the string first
// 2. Then find the space at which the first sentence ends
// 3. Make it into startIndex then incremenet the element into the string and find the lastIndex
// 4. Reverse the word and include the space, then resize the string with lastIndex

#include <bits/stdc++.h>
using namespace std;

string ReverseWords(string str)
{
    reverse(str.begin(), str.end());

    int i = 0, j = 0, n = str.size(), lastIndex;
    while (j < n)
    {
        while (j < n && str[j] =='')
        {
            j++;
        }
        int startIndex = i;
        while (j < n && str[j] !='')
        {
            str[i++] = str[j++];
            lastIndex = i;
        }
        reverse(str.begin() + startIndex, str.begin() + i);
        str[i++] ='';
    }
    str.resize(lastIndex);
    return str;
}