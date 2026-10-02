#include <bits/stdc++.h>
using namespace std;

// Problem: Generate Parentheses
// Link: https://leetcode.com/problems/generate-parentheses/
// Difficulty: Medium
// Pattern: Backtracking (Constrained Choice Generation)

// ------------------------------------------------------------
// Approach: Backtrack Tracking Open/Close Counts, Prune Invalid Branches
// ------------------------------------------------------------
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;

        backtrack(n, 0, 0, curr, ans);

        return ans;
    }

    void backtrack(int n, int open, int close,
                   string& curr, vector<string>& ans) {

        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');

            backtrack(n, open + 1, close, curr, ans);

            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');

            backtrack(n, open, close + 1, curr, ans);

            curr.pop_back();
        }
    }
};

int main() {
    Solution obj;
    vector<string> result = obj.generateParenthesis(3);

    for (const string& s : result) {
        cout << s << " ";
    }

    return 0;
}