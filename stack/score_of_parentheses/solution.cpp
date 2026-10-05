#include <bits/stdc++.h>
using namespace std;

// Problem: Score of Parentheses
// Link: https://leetcode.com/problems/score-of-parentheses/
// Difficulty: Medium
// Pattern: Stack (Nested Score Accumulation)

// ------------------------------------------------------------
// Approach: Stack of Partial Scores, Combine on Closing Bracket
// ------------------------------------------------------------
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int inner = st.top();
                st.pop();

                int score = (inner == 0) ? 1 : 2 * inner;

                st.top() += score;
            }
        }

        return st.top();
    }
};

int main() {
    Solution obj;
    string s = "(()(()))";
    cout << obj.scoreOfParentheses(s);
    return 0;
}