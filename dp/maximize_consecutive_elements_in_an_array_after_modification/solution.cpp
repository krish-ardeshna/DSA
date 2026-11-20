#include <bits/stdc++.h>
using namespace std;

// Problem: Maximize Consecutive Elements in an Array After Modification
// Link: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/
// Difficulty: Hard
// Pattern: Sorting + DP on Value (Longest Run of Consecutive Values Ending at Each Value)

// Every element may stay the same or grow by 1, so an element x can become x or x + 1.
// We want the longest run of consecutive final values, each made by a different element.

// ------------------------------------------------------------
// Approach 1: Brute Force (Try Every +0 / +1 Choice)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // bit i of mask = 1 means nums[i] grows by 1
        for (int mask = 0; mask < (1 << n); mask++) {
            set<int> values;

            for (int i = 0; i < n; i++)
                values.insert(nums[i] + ((mask >> i) & 1));

            // longest run of consecutive values in the set
            int run = 0, prev = INT_MIN;

            for (int v : values) {
                run = (prev != INT_MIN && v == prev + 1) ? run + 1 : 1;
                prev = v;
                ans = max(ans, run);
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Sort + DP with a Hash Map (Chain Length Ending at Each Value)
// ------------------------------------------------------------
class SolutionDPMap {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // dp[v] = longest run of consecutive values that ends exactly at value v
        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            // x becomes x + 1: extends a run that ends at x (read before dp[x] changes)
            dp[x + 1] = dp[x] + 1;

            // x stays x: extends a run that ends at x - 1
            dp[x] = dp[x - 1] + 1;

            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 3: Sort + DP with O(1) Extra Space (Rolling Window of 3 Values)
// ------------------------------------------------------------
class SolutionDPRolling {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // window = dp[base - 1], dp[base], dp[base + 1] for the current value base
        int base = nums[0];
        int left = 0, mid = 0, right = 0;
        int ans = 0;

        for (int x : nums) {
            // move the window from base to x
            int d = x - base;

            if (d == 1) {
                left = mid;
                mid = right;
                right = 0;
            } else if (d == 2) {
                left = right;
                mid = 0;
                right = 0;
            } else if (d >= 3) {
                left = 0;
                mid = 0;
                right = 0;
            }

            base = x;

            right = mid + 1;   // dp[x + 1] = dp[x] + 1
            mid = left + 1;    // dp[x]     = dp[x - 1] + 1

            ans = max({ans, mid, right});
        }

        return ans;
    }
};

int main() {
    vector<int> a1 = {2, 1, 5, 1, 1};
    vector<int> a2 = {1, 4, 7, 10};
    vector<int> a3 = {1, 1, 3, 3};

    SolutionBruteForce s1;
    cout << s1.maxSelectedElements(a1) << " "
         << s1.maxSelectedElements(a2) << " "
         << s1.maxSelectedElements(a3) << "\n";

    SolutionDPMap s2;
    cout << s2.maxSelectedElements(a1) << " "
         << s2.maxSelectedElements(a2) << " "
         << s2.maxSelectedElements(a3) << "\n";

    SolutionDPRolling s3;
    cout << s3.maxSelectedElements(a1) << " "
         << s3.maxSelectedElements(a2) << " "
         << s3.maxSelectedElements(a3) << "\n";

    return 0;
}