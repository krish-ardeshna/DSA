#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Positive Sum Subarray
// Link: https://leetcode.com/problems/minimum-positive-sum-subarray/
// Difficulty: Easy
// Pattern: Brute Force with Running Sum + Prefix Sum and Ordered Set (Sliding Window)

// ------------------------------------------------------------
// Approach 1: Brute Force (Running Sum From Every Start)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n && j < i + r; j++) {
                sum += nums[j];

                int len = j - i + 1;

                if (len >= l && sum > 0)
                    ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Prefix Sum + Ordered Set (Sliding Window of Starts)
// ------------------------------------------------------------
class SolutionPrefixSet {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        // pref[i] = sum of the first i elements, sum of nums[i..e-1] = pref[e] - pref[i]
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        // prefix sums of all valid starts for the current end e
        multiset<int> starts;
        int ans = INT_MAX;

        for (int e = 1; e <= n; e++) {
            // start e - l becomes valid (length exactly l)
            if (e - l >= 0)
                starts.insert(pref[e - l]);

            // start e - r - 1 is now too far (length r + 1)
            if (e - r - 1 >= 0)
                starts.erase(starts.find(pref[e - r - 1]));

            // the smallest positive sum needs the largest pref[start] below pref[e]
            auto it = starts.lower_bound(pref[e]);

            if (it != starts.begin())
                ans = min(ans, pref[e] - *prev(it));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    vector<int> a1 = {3, -2, 1, 4};
    vector<int> a2 = {-2, 2, -3, 1};
    vector<int> a3 = {1, 2, 3, 4};

    SolutionBruteForce s1;
    cout << s1.minimumSumSubarray(a1, 2, 3) << " "
         << s1.minimumSumSubarray(a2, 2, 3) << " "
         << s1.minimumSumSubarray(a3, 2, 4) << "\n";

    SolutionPrefixSet s2;
    cout << s2.minimumSumSubarray(a1, 2, 3) << " "
         << s2.minimumSumSubarray(a2, 2, 3) << " "
         << s2.minimumSumSubarray(a3, 2, 4) << "\n";

    return 0;
}