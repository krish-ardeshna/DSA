#include <bits/stdc++.h>
using namespace std;

// Problem: Rotate String
// Link: https://leetcode.com/problems/rotate-string/
// Difficulty: Easy
// Pattern: Strings

class Solution {
public:
    bool rotateString(string s, string goal) {

        // Lengths must be equal
        if (s.length() != goal.length()) return false;

        // Concatenate string with itself
        string s1 = s + s;

        // Check if goal exists in concatenated string
        return s1.find(goal) != string::npos;
    }
};

int main() {
    string s, goal;
    cin >> s >> goal;

    Solution sol;
    cout << sol.rotateString(s, goal) << "\n";

    return 0;
}