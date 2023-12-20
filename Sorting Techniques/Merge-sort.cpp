#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    vector<int> left(n1);
    vector<int> right(n2);

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    // Merge the two sorted subarrays back into arr[]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = low; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy the remaining elements of left[], if any
    while (i < n1) {
        arr[k++] = left[i++];
    }

    // Copy the remaining elements of right[], if any
    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void MergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Sort first and second halves
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        Merge(arr, low, mid, high);
    }
}

int main() {
    vector<int>arr = {40, 9, 8, 10, 15, 13, 21, 37};
    int n = arr.size();

    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    MergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
