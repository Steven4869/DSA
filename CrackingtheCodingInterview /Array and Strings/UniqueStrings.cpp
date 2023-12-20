// Implement an algorithm to determine if the string has unique characters

#include <bits/stdc++.h>
using namespace std;

bool isUnique(string str){
    int size = str.length();

    int i=0;
    while (i<size)
    {
        int j = i+1;
        while(j<size){
            if(str[i]==str[j]){
                return false;
                break;
            }
            else{
                j++;
            }
        }
        i++;
    }
    return true;
}

// We can do it using hashset as well


bool isUniqueHashSet(string str){
    set<char> st;

    for(char c : str){
        if(st.count(c)>0){
            return false;
        }
        st.insert(c);
    }
    return true;
}

int main(){

    string str = "hello";
    bool ans = isUniqueHashSet(str);
    cout<<ans<<endl;
    return 0;
}