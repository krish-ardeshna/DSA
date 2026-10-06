#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Add to Make Parentheses Valid
// Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Difficulty: Medium
// Pattern: String - Running Counter (Unmatched Open/Close Tracking)

// ------------------------------------------------------------
// Approach: Track Open Count, Count Unmatched Closes Immediately
// ------------------------------------------------------------
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                open++;
            }
            else {
                if (open > 0) {
                    open--;
                }
                else {
                    ans++;
                }
            }
        }

        return ans + open;
    }
};

int main() {
    Solution obj;
    string s = "())";
    cout << obj.minAddToMakeValid(s);
    return 0;
}