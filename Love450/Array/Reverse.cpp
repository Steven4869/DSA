// Given an array (or string), the task is to reverse the array/string.

// Approach 
// 1. Simple reverse std function 
// 2. Two pointer approach 
#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n){
    int i =0;
    int j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

int main(){
    int arr[]={1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}