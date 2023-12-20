// Write a method to replace all spaces in a string with '%20'. You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string.

#include<bits/stdc++.h>
using namespace std;

void URLify(string &str, int trueLength){
    int spaces=0;
    for(int i=0;i<trueLength;i++){
        if(str[i]==' '){
            spaces++;
        }
    }
    int newLength=spaces*2+trueLength;
    str.resize(newLength);

    for(int i=trueLength-1;i>=0;i--){
        if(str[i]==' '){
            str[newLength-1]='0';
            str[newLength-2]='2';
            str[newLength-3]='%';
            newLength=newLength-3;
        }
        else{
            str[newLength-1]=str[i];
            newLength--;
        }
    }
}

int main(){
    string str = "Shivam Sinha";
    int trueLength = 13;
    URLify(str, trueLength);
    cout<<str<<endl;
}