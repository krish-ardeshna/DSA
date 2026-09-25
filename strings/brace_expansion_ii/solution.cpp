#include <bits/stdc++.h>
using namespace std;

// Problem: Brace Expansion II
// Link: https://leetcode.com/problems/brace-expansion-ii/
// Difficulty: Hard
// Pattern: Recursive Descent Parsing (Union + Concatenation)

// ------------------------------------------------------------
// Approach: Recursive Parser, Set Union for Comma, Cross-Product for Concatenation
// ------------------------------------------------------------
class Solution {
public:
    string s;
    int i = 0;

    set<string> parseExpression() {
        set<string> result;

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                i++;
                set<string> next = parseExpression();

                result.insert(next.begin(), next.end());
            }
            else {
                set<string> next = parseTerm();

                if (result.empty()) {
                    result = next;
                }
                else {
                    set<string> temp;

                    for (const string& a : result) {
                        for (const string& b : next) {
                            temp.insert(a + b);
                        }
                    }

                    result = temp;
                }
            }
        }

        return result;
    }

    set<string> parseTerm() {
        set<string> result;

        if (s[i] == '{') {
            i++;  // skip '{'

            result = parseExpression();

            i++;  // skip '}'
        }
        else {
            result.insert(string(1, s[i]));
            i++;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};

int main() {
    Solution obj;
    string expression = "{a,b}{c,{d,e}}";
    vector<string> result = obj.braceExpansionII(expression);

    for (const string& s : result) {
        cout << s << " ";
    }

    return 0;
}