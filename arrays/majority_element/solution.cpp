#include <bits/stdc++.h>
using namespace std;

// Problem: Majority Element
// Link: https://leetcode.com/problems/majority-element/
// Difficulty: Easy
// Pattern: Arrays / Hashing / Boyer-Moore Voting Algorithm

// ------------------------------------------------------------
// Approach 1: Hashmap Counting
// ------------------------------------------------------------

class SolutionHashing {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        int maxFreq = 0;
        int ans = 0;

        for (auto const& [key, val] : mp) {
            if (maxFreq < val) {
                maxFreq = val;
                ans = key;
            }
        }
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Boyer-Moore Voting Algorithm
// ------------------------------------------------------------

class SolutionOptimal {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {

            // Choose new candidate
            if (count == 0) {
                candidate = num;
            }

            // Increase or decrease count
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    SolutionOptimal s;

    cout << s.majorityElement(nums) << "\n";

    return 0;
}