#include <bits/stdc++.h>
using namespace std;

// Problem: Single Number III
// Link: https://leetcode.com/problems/single-number-iii/
// Difficulty: Medium
// Pattern: Hashing / Bit Manipulation

// ------------------------------------------------------------
// Approach 1: Hash Map
// ------------------------------------------------------------

class SolutionHashing {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        vector<int> res;
        for (const auto& [key, val] : freq) {
            if (val == 1) {
                res.push_back(key);
            }
        }
        return res;
    }
};

// ------------------------------------------------------------
// Approach 2: XOR + Bit Manipulation
// ------------------------------------------------------------

class SolutionOptimal {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;

        // XOR of all elements
        for (int x : nums) {
            xorAll ^= x;
        }

        // Extract rightmost set bit
        int rightMostBit = xorAll & (-xorAll);
        int num1 = 0;
        int num2 = 0;

        // Divide numbers into two groups
        for (int x : nums) {

            if (x & rightMostBit) {
                num1 ^= x;
            }
            else {
                num2 ^= x;
            }
        }
        return {num1, num2};
    }
};

int main() {
    vector<int> nums = {1,2,1,3,2,5};
    SolutionOptimal s;

    vector<int> res = s.singleNumber(nums);

    for (int x : res) {
        cout << x << " ";
    }
    return 0;
}