#include <bits/stdc++.h>
using namespace std;

// Problem: Remove K Digits
// Link: https://leetcode.com/problems/remove-k-digits/
// Difficulty: Medium
// Pattern: Monotonic Stack (Greedy Digit Removal)

// ------------------------------------------------------------
// Approach 1: Strip Leading Zeros AFTER Reversing
// ------------------------------------------------------------
class SolutionStripAfterReverse {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char c : num) {
            while (!st.empty() &&
                   k > 0 &&
                   st.top() > c) {
                st.pop();
                k--;
            }

            st.push(c);
        }

        while (k > 0) {
            st.pop();
            k--;
        }

        if (st.empty()) return "0";

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeroes
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Strip Trailing Zeros BEFORE Reversing (Equivalent Trick)
// ------------------------------------------------------------

class SolutionStripBeforeReverse {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        for (char c : num) {
            while (!st.empty() &&
                   k > 0 &&
                   (st.top() - '0') > (c - '0')) {
                st.pop();
                k--;
            }

            st.push(c);
        }

        while (k > 0) { st.pop(); k--; }
        if (st.empty()) return "0";

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Stripping trailing zeros here == stripping leading zeros
        // of the final answer, because ans is currently reversed.

        while (ans.size() != 0 && ans.back() == '0') ans.pop_back();
        if (ans.empty()) return "0";

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string num = "1432219";
    int k = 3;

    SolutionStripAfterReverse s1;
    cout << s1.removeKdigits(num, k) << "\n";

    SolutionStripBeforeReverse s2;
    cout << s2.removeKdigits(num, k) << "\n";

    return 0;
}