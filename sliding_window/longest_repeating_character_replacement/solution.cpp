#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Repeating Character Replacement
// Link: https://leetcode.com/problems/longest-repeating-character-replacement/
// Difficulty: Medium
// Pattern: Sliding Window

// ------------------------------------------------------------
// Approach: Sliding Window
// ------------------------------------------------------------

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {

            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    string s = "AABABBA";
    int k = 1;

    Solution obj;

    cout << obj.characterReplacement(s, k) << "\n";
    return 0;
}