// Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
// A palindrome is a word or phrase that is the same forwards and backwards. A permutation
// is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

#include <bits/stdc++.h>
using namespace std;

bool PalindromePermutation(string str){
    unordered_map<char, int>mp;
    int OddCharCount=0;

    for(auto c:str){
        if(c!=' '){
            mp[c]++;
            if(mp[c]%2==1){
                OddCharCount++;
            }
            else{
                OddCharCount--;
            }
        }
    }
    if(OddCharCount<=1){
        return true;
    }
    return false;
}

int main(){
    string str = "hello world";

    bool ans = PalindromePermutation(str);
    cout<<ans<<endl;
    return 0;
}