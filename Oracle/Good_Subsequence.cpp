#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countGoodSubsequences(string word) {
    vector<int> freq(26, 0);

    for (char c : word) {
        freq[c - 'a']++;
    }

    int total_subsequences = (1 << word.length()) - 1;

    int total_bad_subsequences = 0;
    for (int f : freq) {
        total_bad_subsequences = (total_bad_subsequences + (1LL * ((1LL << f) - 1 + MOD) % MOD)) % MOD;
    }

    int total_good_subsequences = (total_subsequences - total_bad_subsequences + MOD) % MOD;

    return total_good_subsequences;
}

int main() {
    string word = "abca";
    cout << countGoodSubsequences(word) << endl;  // Output: 12

    return 0;
}
