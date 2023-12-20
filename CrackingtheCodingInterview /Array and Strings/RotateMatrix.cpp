// Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

#include <bits/stdc++.h>
using namespace std;

void RotateMatrix(vector<vector <int> > &matrix){
    int n = matrix.size();

    //Transpose the matrix 
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //Reverse the matrix
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    vector<vector<int> >matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    RotateMatrix(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
    }
    return 0;
}
