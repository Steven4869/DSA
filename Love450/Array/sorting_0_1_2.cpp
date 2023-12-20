// Sort an array of 0s, 1s and 2s

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

// Approach 
// 1. Count the number of 0, 1, 2 then print the array -> O(N) + O(N)
//  This is a variation of Dutch national Flag Problem 
// 2. This can be solved by taking low, mid to be 0th index then high at n-1th index, then perform the following cases
// 3. if(mid==0){
//     swap(low,mid)
//     low++,mid++
// }
//    if(mid==1){
//         mid++;
// }
//     if(mid==2){
//     swap(mid,high)
//     high--;
// }

#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main(){
    int arr[]={1,0,1,2,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
