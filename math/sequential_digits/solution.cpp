#include <bits/stdc++.h>
using namespace std;

// Problem: Sequential Digits
// Link: https://leetcode.com/problems/sequential-digits/
// Difficulty: Medium
// Pattern: String Generation

// ------------------------------------------------------------
// Approach: String Generation
// ------------------------------------------------------------

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;
        string sampleNum = "123456789";

        int minLen = to_string(low).length();
        int maxLen = to_string(high).length();

        for (int len = minLen; len <= maxLen; len++) {
            for (int start = 0; start <= 9 - len; start++) {

                string sub = sampleNum.substr(start, len);
                int num = stoi(sub);

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};

int main() {
    
    int low = 100;
    int high = 300;

    Solution s;
    vector<int> ans = s.sequentialDigits(low, high);

    for (int num : ans) {
        cout << num << " ";
    }

    cout << "\n";
    return 0;
}