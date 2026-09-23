#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Length Substring With Two Occurrences
// Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
// Difficulty: Easy
// Pattern: Sliding Window + Frequency Array

// ------------------------------------------------------------
// Approach: Variable-Size Sliding Window with Fixed-Size Freq Array
// ------------------------------------------------------------
class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'a']++;

            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string s = "bcbbbcba";
    cout << obj.maximumLengthSubstring(s);
    return 0;
}