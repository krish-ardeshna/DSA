#include <bits/stdc++.h>
using namespace std;

// Problem: Single Number
// Link: https://leetcode.com/problems/single-number/
// Difficulty: Easy
// Pattern: Hashing / Bit Manipulation (XOR)

// ------------------------------------------------------------
// Approach 1: Hashmap Frequency Count
// ------------------------------------------------------------
class SolutionHashmap {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& [key, val] : freq) {
            if (val == 1) {
                return key;
            }
        }
        return {};
    }
};

// ------------------------------------------------------------
// Approach 2: XOR Bit Trick
// ------------------------------------------------------------
class SolutionXOR {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    SolutionHashmap s1;
    cout << s1.singleNumber(nums) << "\n";

    SolutionXOR s2;
    cout << s2.singleNumber(nums) << "\n";

    return 0;
}