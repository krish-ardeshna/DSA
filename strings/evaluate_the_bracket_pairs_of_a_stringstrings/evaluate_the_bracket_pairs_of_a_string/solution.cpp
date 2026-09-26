#include <bits/stdc++.h>
using namespace std;

// Problem: Evaluate the Bracket Pairs of a String
// Link: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
// Difficulty: Medium
// Pattern: String - Hashmap Lookup + Single Pass Parsing

// ------------------------------------------------------------
// Approach: Build Key-Value Map, Single Pass Replace Bracketed Keys
// ------------------------------------------------------------
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                string key = "";

                i++;

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if (mp.count(key)) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = {{"name", "bob"}, {"age", "two"}};
    cout << obj.evaluate(s, knowledge);
    return 0;
}