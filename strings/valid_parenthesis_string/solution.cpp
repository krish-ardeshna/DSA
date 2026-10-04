#include <bits/stdc++.h>
using namespace std;

// Problem: Valid Parenthesis String
// Link: https://leetcode.com/problems/valid-parenthesis-string/
// Difficulty: Medium
// Pattern: Greedy (Balance Range Tracking)

// ------------------------------------------------------------
// Approach: Track Min and Max Possible Open-Count Simultaneously
// ------------------------------------------------------------
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else {
                low--;
                high++;
            }

            if (high < 0) {
                return false;
            }

            low = max(low, 0);
        }
        return low == 0;
    }
};

int main() {
    Solution obj;
    string s = "(*))";
    cout << obj.checkValidString(s);
    return 0;
}