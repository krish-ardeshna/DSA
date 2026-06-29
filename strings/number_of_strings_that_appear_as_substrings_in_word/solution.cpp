#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Strings That Appear as Substrings in Word
// Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
// Difficulty: Easy
// Pattern: Strings

// ------------------------------------------------------------
// Approach: String Matching using find()
// ------------------------------------------------------------

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string p : patterns) {
            if (word.find(p) != string::npos) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<string> patterns = {"a", "abc", "bc", "d"};
    string word = "abc";

    Solution s;
    cout << s.numOfStrings(patterns, word) << "\n";

    return 0;
}