// Next Greater Frequency Element

// Given an array, for each element find the value of the nearest element to the right which is having a frequency greater than as that of the current element. If there does not exist an answer for a position, then make the value ‘-1’.

// Input : a[] = [1, 1, 2, 3, 4, 2, 1]
// Output : [-1, -1, 1, 2, 2, 1, -1]

// Approach

// 1. here we have to find the NGE based on the frequencies, so hashmmap is the option to go beacuse there we can arrange by frequencies in a new array result where we'll store them in form of frequencies
//  a[] = [1, 1, 2, 3, 4, 2, 1]
//  res[] = [3,3,2,1,1,2,3]
//  OP: [-1,-1,1,2,2,1,-1]
// 2. Then use the usual stack prodecure we did for the NGE