#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty: Medium
// Pattern: Sliding Window / Hash Map

// ------------------------------------------------------------
// Approach: Sliding Window with Hash Map
// ------------------------------------------------------------

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            if (lastIndex.count(s[right])) {
                left = max(left, lastIndex[s[right]] + 1);
            }

            lastIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    string s = "abcabcbb";
    Solution obj;
    
    cout << obj.lengthOfLongestSubstring(s) << "\n";
    return 0;
}