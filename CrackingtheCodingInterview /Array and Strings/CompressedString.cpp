// String Compression: Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
// "compressed" string would not become smaller than the original string, your method should return
// the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include <bits/stdc++.h>
using namespace std;

string CompressedString(string str){
    int len = str.length();
    //If the length of string is less than 2 then it can't be compressed
    if(len<2){
        return str;
    }

    string compressed;
    char curr_char = str[0];
    int count=1;

    for(int i=1;i<len;i++){
        if(str[i]==curr_char){
            count++;
        }
        else{
            compressed=compressed+curr_char+to_string(count);
            curr_char=str[i];
            count=1;
        }
    }

    compressed=compressed+curr_char+to_string(count);

    return compressed.length()<len?compressed:str;
}

int main(){
    string str = "aabcccccaaa";
    cout<<CompressedString(str)<<endl;
    return 0;
}