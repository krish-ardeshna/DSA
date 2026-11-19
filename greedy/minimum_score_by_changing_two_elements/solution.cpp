#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Score by Changing Two Elements
// Link: https://leetcode.com/problems/minimum-score-by-changing-two-elements/
// Difficulty: Medium
// Pattern: Greedy + Sorting (Remove Two Extremes, Low Score Is Always 0)

// The low score can always be made 0 (set a changed element equal to another element),
// so the task is to make high = max - min as small as possible.
// Changing an element to a value inside the range never hurts, so we may think of it as
// "removing" two elements and taking max - min of the rest.

// ------------------------------------------------------------
// Approach 1: Brute Force (Try Every Pair of Elements to Remove)
// ------------------------------------------------------------
class SolutionBruteForce {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mn = INT_MAX, mx = INT_MIN;

                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;

                    mn = min(mn, nums[k]);
                    mx = max(mx, nums[k]);
                }

                ans = min(ans, mx - mn);
            }
        }

        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2: Sort + Three Options
// ------------------------------------------------------------
class SolutionSort {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return min({
            nums[n - 1] - nums[2],
            nums[n - 2] - nums[1],
            nums[n - 3] - nums[0]
        });
    }
};

// ------------------------------------------------------------
// Approach 3: One Pass (Keep the 3 Smallest and 3 Largest)
// ------------------------------------------------------------
class SolutionLinear {
public:
    int minimizeSum(vector<int>& nums) {
        // small[0] <= small[1] <= small[2] are the 3 smallest values
        // large[0] >= large[1] >= large[2] are the 3 largest values
        int small[3] = {INT_MAX, INT_MAX, INT_MAX};
        int large[3] = {INT_MIN, INT_MIN, INT_MIN};

        for (int x : nums) {
            // insert x into small, keeping it sorted
            for (int i = 0; i < 3; i++) {
                if (x < small[i]) {
                    swap(x, small[i]);
                }
            }
        }

        for (int x : nums) {
            // insert x into large, keeping it sorted
            for (int i = 0; i < 3; i++) {
                if (x > large[i]) {
                    swap(x, large[i]);
                }
            }
        }

        return min({
            large[0] - small[2],
            large[1] - small[1],
            large[2] - small[0]
        });
    }
};

int main() {
    vector<int> a1 = {1, 4, 3};
    vector<int> a2 = {1, 4, 7, 8, 5};
    vector<int> a3 = {5, 5, 5, 5};

    SolutionBruteForce s1;
    cout << s1.minimizeSum(a1) << " "
         << s1.minimizeSum(a2) << " "
         << s1.minimizeSum(a3) << "\n";

    SolutionSort s2;
    cout << s2.minimizeSum(a1) << " "
         << s2.minimizeSum(a2) << " "
         << s2.minimizeSum(a3) << "\n";

    SolutionLinear s3;
    cout << s3.minimizeSum(a1) << " "
         << s3.minimizeSum(a2) << " "
         << s3.minimizeSum(a3) << "\n";

    return 0;
}