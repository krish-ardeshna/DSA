#include <bits/stdc++.h>
using namespace std;

// Problem: Swap For Longest Repeated Character Substring
// Link: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
// Difficulty: Medium
// Pattern: Sliding Window

// ------------------------------------------------------------
// Approach: Sliding Window
// ------------------------------------------------------------

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> total(26, 0);

        for (char ch : text) {
            total[ch - 'a']++;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {

            int left = 0;
            int diff = 0;

            for (int right = 0; right < text.size(); right++) {
                if (text[right] - 'a' != i) {
                    diff++;
                }

                while (diff > 1) {
                    if (text[left] - 'a' != i) {
                        diff--;
                    }
                    left++;
                }

                int window = right - left + 1;

                if (window > total[i]) {
                    ans = max(ans, total[i]);
                }
                else {
                    ans = max(ans, window);
                }
            }
        }

        return ans;
    }
};

int main() {
    string text = "ababa";
    Solution s;

    cout << s.maxRepOpt1(text) << "\n";
    return 0;
}