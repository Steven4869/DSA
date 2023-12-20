// An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.
// Approach 
// Two Pointer Approach 
// Assign left to 0th index and right to n-1th index 
// if(l,r<0) l++
// if(l>0,r<0) swap(l,r) l++,r--
// if(l<0, r>0) r--

#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int n){
    int left = 0;
    int right = n-1;
    while(left<=right){
        if(arr[left]<0&&arr[right]<0){
            left++;
        }
        else if(arr[left]>0&&arr[right]<0){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        else if(arr[left]<0&&arr[right]>0){
            right--;
        }
    }
}

int main(){
    int arr[]={-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}