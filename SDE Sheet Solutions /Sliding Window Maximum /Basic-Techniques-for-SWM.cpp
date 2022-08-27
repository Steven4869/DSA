// To, find out a sliding window problem :-
// First thing is, we have given something like an "Array" | OR | "String"
// Second thing is, they are talking about either "subsequence" | OR | "substring"
// And third most thing is, either we have given a "window size i.e. k" | OR | we have to "manually find out window size"

// There's exist basically 2 types of sliding window.

// Fix size sliding window {means K is given}

// Variable silze sliding window {means K is not given}

// Before moving to the problem I want to give you a template which you can use in any sliding window {Variable size} problem

// while(j < size()){

//     // Calculation's happen's here
// -----------------------------------------------
//     if(condition < k){
//         j++;
//     }
// -----------------------------------------------

// -----------------------------------------------
//     else if(condition == k){
//         // ans <-- calculation
//         j++;
//     }
// ----------------------------------------------

// ----------------------------------------------
//     else if(condition > k){
//         while(condition > k){
//             // remove calculation for i
//             i++;
//         }
//         j++;
//     }
// ----------------------------------------------
// }
// return ans;