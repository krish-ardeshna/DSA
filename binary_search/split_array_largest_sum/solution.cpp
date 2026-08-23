#include <bits/stdc++.h>
using namespace std;

// Problem: Split Array Largest Sum
// Link: https://leetcode.com/problems/split-array-largest-sum/
// Difficulty: Hard
// Pattern: Binary Search on Answer

// ------------------------------------------------------------
// Approach: Binary Search on Max Subarray Sum + Greedy Partition Count
// ------------------------------------------------------------
class Solution {
public:
    int canHold(vector<int>& nums, long long maxSum) {
        int subarrays = 1;
        long long currentSum = 0;

        for (int x : nums) {
            if (currentSum + x <= maxSum) {
                currentSum += x;
            }
            else {
                subarrays++;
                currentSum = x;
            }
        }
        return subarrays;
    }

    long long totalSum(vector<int>& nums) {
        long long sum = 0;
        for (int x : nums) {
            sum += x;
        }
        return sum;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = totalSum(nums);

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canHold(nums, mid) <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << obj.splitArray(nums, k);
    return 0;
}