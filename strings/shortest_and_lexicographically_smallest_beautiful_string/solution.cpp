#include <bits/stdc++.h>
using namespace std;

// Problem: Shortest and Lexicographically Smallest Beautiful String
// Link: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
// Difficulty: Medium
// Pattern: Sliding Window (Fixed Count via Index Tracking)

// ------------------------------------------------------------
// Approach: Track '1' Positions + Window Between K-th Apart Ones
// ------------------------------------------------------------
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }

        if (ones.size() < k) {
            return "";
        }

        int minLen = INT_MAX;
        string ans = "";

        for (int i = 0; i + k - 1 < ones.size(); i++) {
            int start = ones[i];
            int end = ones[i + k - 1];

            int len = end - start + 1;

            string curr = s.substr(start, len);

            if (len < minLen) {
                minLen = len;
                ans = curr;
            }
            else if (len == minLen && curr < ans) {
                ans = curr;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string s = "100011001";
    int k = 3;
    cout << obj.shortestBeautifulSubstring(s, k);
    return 0;
}