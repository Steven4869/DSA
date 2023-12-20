// Given two strings write a method to decide if one is a permutation of the other.

#include<bits/stdc++.h>
using namespace std;

bool isPermutation(string str1, string str2){

    //Base condition 
    if(str1.length() != str2.length()){
        return false;
    }
    unordered_map<char, int>mp1;
    for(int i=0;i<str1.length();i++){
        mp1[str1[i]]++;
    }
    //Now compare the map1 with the characters of the string 2

    for(char c : str2){
        if(mp1.find(c)==mp1.end() || mp1[c]==0){
            return false;
        }
        mp1[c]--;
    }
    return true;
}

int main(){
    string str1 = "abcd";
    string str2 = "efgh";

    bool ans = isPermutation(str1, str2);
    cout<<ans;
}