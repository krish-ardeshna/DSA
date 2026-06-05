#include <bits/stdc++.h>
using namespace std;

// Problem: Valid Parentheses
// Link: https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy
// Pattern: Stack

// ------------------------------------------------------------
// Approach 1: Stack
// ------------------------------------------------------------

class SolutionOptimal {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for (char ch : s) {
           
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {

                if (st.empty()) {
                    return false;
                }
                
                if (ch == ')' && st.top() != '(') {
                    return false;
                }

                if (ch == ']' && st.top() != '[') {
                    return false;
                }

                if (ch == '}' && st.top() != '{') {
                    return false;
                }

                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {

    string s = "()[]{}";
    SolutionOptimal obj;

    cout << boolalpha << obj.isValid(s) << "\n";

    return 0;
}