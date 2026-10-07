#include <bits/stdc++.h>
using namespace std;

// Problem: Remove Invalid Parentheses
// Link: https://leetcode.com/problems/remove-invalid-parentheses/
// Difficulty: Hard
// Pattern: DFS Backtracking (Forward Pass Then Mirrored Backward Pass)

// ------------------------------------------------------------
// Approach: Detect First Invalid Point, Branch Over Candidate Removals, Flip Direction
// ------------------------------------------------------------
class Solution {
public:
    vector<string> ans;

    void dfs(string s, int start, int last, char open, char close) {
        int balance = 0;

        for (int i = start; i < s.size(); i++) {
            if (s[i] == open)
                balance++;
            else if (s[i] == close)
                balance--;

            if (balance < 0) {
                for (int j = last; j <= i; j++) {
                    if (s[j] == close &&
                        (j == last || s[j - 1] != close)) {

                        string t = s.substr(0, j) + s.substr(j + 1);
                        dfs(t, i, j, open, close);
                    }
                }
                return;
            }
        }

        if (open == '(') {
            reverse(s.begin(), s.end());
            dfs(s, 0, 0, ')', '(');
        } else {
            reverse(s.begin(), s.end());
            ans.push_back(s);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        dfs(s, 0, 0, '(', ')');
        return ans;
    }
};

int main() {
    Solution obj;
    string s = "()())()";
    vector<string> result = obj.removeInvalidParentheses(s);

    for (const string& r : result) {
        cout << r << " ";
    }

    return 0;
}