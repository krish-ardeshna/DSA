#include <bits/stdc++.h>
using namespace std;

// Problem: Process String with Special Operations I
// Link: https://leetcode.com/problems/process-string-with-special-operations-i/
// Difficulty: Medium
// Pattern: Strings / Simulation

// ------------------------------------------------------------
// Approach: String Simulation
// ------------------------------------------------------------

class Solution {
public:
    string processStr(string s) {

        string result = "";

        for (char ch : s) {
            if (islower(ch)) {
                result += ch;
            }

            else if (ch == '*') {
                
                if (!result.empty()) {
                    result.pop_back();
                }
            }

            else if (ch == '#') {
                result += result;
            }

            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};

int main() {
    string s = "a#b%*";
    Solution obj;

    cout << obj.processStr(s) << "\n";
    return 0;
}