// One Away: There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.

#include <bits/stdc++.h>
using namespace std;

bool OneAway(string str1, string str2){
    int len1 = str1.length();
    int len2 = str2.length();

    if(abs(len1-len2)>1){
        return false;
    }

    int edits=0;
    int i=0, j=0;
    //If two strings are equal 
    if(len1==len2){
        while (i<len1&&j<len2)
        {
            if(str1[i]!=str2[j]){
                edits++;

            }
            i++;
            j++;
        }   
    }

    //When they differ by 1
    else{
        while(i<len1&&j<len2){
            if(str1[i]!=str2[j]){
                edits++;
                if(len1>len2){
                    i++;
                }
                else{
                    j++;
                }
            }
            i++;
            j++;
        }
    }

    if(edits<=1){
        return true;
    }
    return false;
}

int main(){
    string str1 = "pale";
    string str2 = "bale";
    bool ans = OneAway(str1, str2);
    cout<<ans<<endl;
}