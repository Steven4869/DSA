#include<bits/stdc++.h>
using namespace std;

void NaiveStringMatching(string text, string pattern){
    int n = text.length();
    int m = pattern.length();

    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j<m&&text[i+j]==pattern[j]){
            j++;
        }
        if(j==m){
            cout<<"Pattern is found at index "<<i<<endl;
        }
    }

    // cout<<n<<" "<<m<<endl;
}

int main(){
    string text = "This is sample sample";
    string pattern = "sample";
    NaiveStringMatching(text, pattern);
    return 0;
}