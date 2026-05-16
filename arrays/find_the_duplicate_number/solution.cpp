#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Duplicate Number
// Link: https://leetcode.com/problems/find-the-duplicate-number/
// Difficulty: Medium
// Pattern: Hashing / Floyd's Cycle Detection

// ------------------------------------------------------------
// Approach 1: Hash Map
// ------------------------------------------------------------

class SolutionHashing {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
            if (hash[nums[i]] > 1) {
                return nums[i];
            }
        }
        return -1;
    }
};

// ------------------------------------------------------------
// Approach 2: Floyd's Cycle Detection (Optimal)
// ------------------------------------------------------------

class SolutionOptimal {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Detect intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find entrance of cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    SolutionOptimal s;

    cout << s.findDuplicate(nums) << "\n";

    return 0;
}