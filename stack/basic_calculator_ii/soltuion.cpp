#include <bits/stdc++.h>
using namespace std;

// Problem: Basic Calculator II
// Link: https://leetcode.com/problems/basic-calculator-ii/
// Difficulty: Medium
// Pattern: Stack

// ------------------------------------------------------------
// Approach 1: Stack
// ------------------------------------------------------------

class SolutionStack {
public:
    int calculate(string s) {

        stack<int> st;

        long long num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {

                if (op == '+') {
                    st.push(num);
                }
                else if (op == '-') {
                    st.push(-num);
                }
                else if (op == '*') {

                    int top = st.top();
                    st.pop();

                    st.push(top * num);
                }
                else if (op == '/') {

                    int top = st.top();
                    st.pop();

                    st.push(top / num);
                }

                op = c;
                num = 0;
            }
        }

        int ans = 0;

        while (!st.empty()) {

            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Constant Space Optimization
// ------------------------------------------------------------

class SolutionOptimal {
public:
    int calculate(string s) {

        long long num = 0;
        long long last = 0;
        long long res = 0;

        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {

                if (op == '+') {

                    res += last;
                    last = num;
                }
                else if (op == '-') {

                    res += last;
                    last = -num;
                }
                else if (op == '*') {

                    last *= num;
                }
                else if (op == '/') {

                    last /= num;
                }

                op = c;
                num = 0;
            }
        }
        return res + last;
    }
};

int main() {
    string s = "3+2*2-1+6/3";
    SolutionOptimal obj;

    cout << obj.calculate(s) << "\n";

    return 0;
}