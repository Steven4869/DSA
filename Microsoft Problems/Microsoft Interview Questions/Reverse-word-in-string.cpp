#include <bits/stdc++.h>
using namespace std;

string ReverseWords(string s)
{
    // Reverse the string
    reverse(s.begin(), s.end());

    int i = 0, j = 0, n = s.size(), lastIndex = 0;
    while (j < n)
    {
        // Finding the first index
        while (j < n && s[j] == ' ')
        {
            j++;
        }
        int startIndex = i;
        while (j < n && s[j] != ' ')
        {
            s[i++] = s[j++];
            lastIndex = i;
        }

        // Reverse the word
        reverse(s.begin() + startIndex, s.begin() + i);
        s[i++] = ' ';
    }
    // Reseize the string to last index
    s.resize(lastIndex);
    return s;
}

int main()
{
    string s = "Hello World";
    cout << ReverseWords(s);
    return 0;
}