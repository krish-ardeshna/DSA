#include <bits/stdc++.h>
using namespace std;

// Problem: Separate the Digits in an Array
// Link: https://leetcode.com/problems/separate-the-digits-in-an-array/
// Difficulty: Easy
// Pattern: Arrays / Simulation

// Approach 1: String Conversion
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            string s = to_string(num);
            for (char ch : s) {
                ans.push_back(ch - '0');
            }
        }
        return ans;
    }
};

// Approach 2: Manual Digit Extraction
class SolutionAlternative {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int x : nums) {
            if (x == 0) {
                res.push_back(0);
                continue;
            }
            
            vector<int> temp;
            while (x > 0) {
                temp.push_back(x % 10);
                x /= 10;
            }
            reverse(temp.begin(), temp.end());
            for (int digit : temp) {
                res.push_back(digit);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {13, 25, 83, 77};
    Solution s;

    vector<int> res = s.separateDigits(nums);

    for (int digit : res) {
        cout << digit << " ";
    }

    return 0;
}