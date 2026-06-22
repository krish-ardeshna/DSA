#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Number of Balloons
// Link: https://leetcode.com/problems/maximum-number-of-balloons/
// Difficulty: Easy
// Pattern: Hash Map / Counting

// ------------------------------------------------------------
// Approach: Frequency Counting
// ------------------------------------------------------------

class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> freq;

        for (char ch : text) {
            freq[ch]++;
        }

        return min({
            freq['b'],
            freq['a'],
            freq['l'] / 2,
            freq['o'] / 2,
            freq['n']
        });
    }
};

int main() {
    string text = "loonbalxballpoon";
    Solution s;

    cout << s.maxNumberOfBalloons(text) << "\n";

    return 0;
}